/*
 * Copyright (c) 2023 ZitaoTech
 *
 * SPDX-License-Identifier: MIT
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/logging/log.h>

#include <zmk/events/position_state_changed.h> 
#include <zmk/hid.h>
#include <zmk/endpoints.h>
#include <zmk/hid_indicators.h>
#include "trackpad_led.h"

#define HID_INDICATORS_CAPS_LOCK (1 << 1)

LOG_MODULE_REGISTER(a320_0x57, LOG_LEVEL_INF);

// === set parameter ===
#define POLLING_INTERVAL_MS 10
#define SMOOTHING_SIZE 2
#define SCROLL_INTERVAL_MS CONFIG_A320_TRACKPAD_SCROLL_INTERVAL
// === set motion pin gpio ===
#define MOTION_GPIO_NODE DT_NODELABEL(gpio0)
#define MOTION_GPIO_PIN 2
static const struct device *motion_gpio_dev;

/* ==== I2C Device ==== */
#define A320_NODE DT_INST(0, avago_a320)
static const struct i2c_dt_spec a320_i2c = I2C_DT_SPEC_GET(A320_NODE);

/* ==== get touch status ==== */
static bool touched = false;

/* ==== smoothing function ==== */
static int8_t dx_buffer[SMOOTHING_SIZE] = {0};
static int8_t dy_buffer[SMOOTHING_SIZE] = {0};
static uint8_t buffer_index = 0;

/* ==== k_work timer ==== */
static struct k_work_delayable a320_work;

/* ==== Ctrl  position=37  true ==== */
static bool ctrl_pressed = false;

/* ==== position_state_changed  ==== */
static int ctrl_listener_cb(const zmk_event_t *eh)  
{
    const struct zmk_position_state_changed *ev = as_zmk_position_state_changed(eh);
    if (!ev) {
        return 0;
    }

    if (ev->position == 37) {
        ctrl_pressed = ev->state;
        LOG_INF("Ctrl position=37 %s", ctrl_pressed ? "PRESSED" : "RELEASED");
    }
    return 0;
}
ZMK_LISTENER(a320_ctrl_listener, ctrl_listener_cb);
ZMK_SUBSCRIPTION(a320_ctrl_listener, zmk_position_state_changed);

/* ==== initial ==== */
static int a320_init(void) {
    LOG_INF("Initializing A320 input handler...");

    motion_gpio_dev = DEVICE_DT_GET(MOTION_GPIO_NODE);
    if (!device_is_ready(motion_gpio_dev)) {
        LOG_ERR("Motion GPIO device not ready");
        return -ENODEV;
    }
    gpio_pin_configure(motion_gpio_dev, MOTION_GPIO_PIN, GPIO_INPUT | GPIO_PULL_UP);

    if (!device_is_ready(a320_i2c.bus)) {
        LOG_ERR("I2C bus not ready for A320 sensor");
        return -ENODEV;
    }

    LOG_INF("A320 sensor initialized at addr=0x%02x", a320_i2c.addr);
    return 0;
}

/* ==== smoothing function ==== */
static void apply_smoothing(int16_t *x, int16_t *y) {
    dx_buffer[buffer_index] = *x;
    dy_buffer[buffer_index] = *y;

    int32_t sum_x = 0, sum_y = 0;
    for (int i = 0; i < SMOOTHING_SIZE; i++) {
        sum_x += dx_buffer[i];
        sum_y += dy_buffer[i];
    }

    *x = sum_x / SMOOTHING_SIZE;
    *y = sum_y / SMOOTHING_SIZE;

    buffer_index = (buffer_index + 1) % SMOOTHING_SIZE;
}

/* ==== read motion data ==== */
static int a320_read_motion(int16_t *dx, int16_t *dy) {
    uint8_t buf[7] = {0};
    uint8_t reg = 0x0A;

    int ret = i2c_write_dt(&a320_i2c, &reg, 1);
    if (ret < 0) {
        LOG_ERR("Failed to write register address 0x0A: %d", ret);
        return ret;
    }

    ret = i2c_burst_read_dt(&a320_i2c, 0x0A, buf, sizeof(buf));
    if (ret < 0) {
        LOG_ERR("Failed to read from 0x0A: %d", ret);
        return ret;
    }

    *dy = (int8_t)buf[1];
    *dx = (int8_t)buf[3];
    return 0;
}

/* ==== API: if is touched ==== */
bool tp_is_touched(void) { return touched; }


static void a320_work_handler(struct k_work *work) {
    int16_t dx, dy;
    int pin_state = gpio_pin_get(motion_gpio_dev, MOTION_GPIO_PIN);

    if (pin_state == 0) {
        if (a320_read_motion(&dx, &dy) == 0) {
            if (dx || dy) {
                bool capslock =
                    (zmk_hid_indicators_get_current_profile() & HID_INDICATORS_CAPS_LOCK);
                LOG_INF("Motion dx=%d dy=%d", dx, dy);


                if (ctrl_pressed) {
                    dx /= 2;
                    dy /= 2;
                }

                if (!capslock) {
                    uint8_t tp_led_brt = indicator_tp_get_last_valid_brightness();
                    float tp_factor = 0.4f + 0.01f * tp_led_brt;
                    dx = dx * 3 / 2 * tp_factor;
                    dy = dy * 3 / 2 * tp_factor;
                }
                apply_smoothing(&dx, &dy);

                if (capslock) {
                    int8_t x = -dx;
                    int8_t y = dy;
                    int8_t scroll_x = 0, scroll_y = 0;

                    if (abs(y) >= 128) {
                        scroll_x = -x / 24;
                        scroll_y = -y / 24;
                    } else if (abs(y) >= 64) {
                        scroll_x = -x / 16;
                        scroll_y = -y / 16;
                    } else if (abs(y) >= 32) {
                        scroll_x = -x / 12;
                        scroll_y = -y / 12;
                    } else if (abs(y) >= 21) {
                        scroll_x = -x / 8;
                        scroll_y = -y / 8;
                    } else if (abs(y) >= 3) {
                        scroll_x = (x > 0) ? -1 : (x < 0) ? 1 : 0;
                        scroll_y = (y > 0) ? -1 : (y < 0) ? 1 : 0;
                    } else {
                        scroll_x = (x > 0) ? -1 : (x < 0) ? 1 : 0;
                        scroll_y = 0;
                    }

                    zmk_hid_mouse_movement_set(0, 0);
                    zmk_hid_mouse_scroll_set(0, 0);
                    zmk_hid_mouse_scroll_update(scroll_x, scroll_y);
                    zmk_endpoints_send_mouse_report();

                    k_msleep(SCROLL_INTERVAL_MS);
                } else {
                    zmk_hid_mouse_scroll_set(0, 0);
                    zmk_hid_mouse_movement_set(0, 0);
                    zmk_hid_mouse_movement_update(dx, dy);
                    zmk_endpoints_send_mouse_report();
                    touched = true;
                }
            }
        } else {
            zmk_hid_mouse_scroll_set(0, 0);
            zmk_hid_mouse_movement_set(0, 0);
            zmk_endpoints_send_mouse_report();
        }
    } else {
        touched = false;
    }


    k_work_schedule(&a320_work, K_MSEC(POLLING_INTERVAL_MS));
}


static int a320_start(void) {
    if (a320_init() < 0) {
        return -ENODEV;
    }
    k_work_init_delayable(&a320_work, a320_work_handler);
    k_work_schedule(&a320_work, K_NO_WAIT);
    return 0;
}

SYS_INIT(a320_start, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);
