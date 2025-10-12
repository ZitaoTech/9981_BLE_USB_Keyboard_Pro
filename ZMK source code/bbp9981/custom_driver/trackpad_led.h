/*
 * Copyright (c) 2025 ZitaoTech
 *
 * SPDX-License-Identifier: MIT
 */
#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Get current indicator led brightness
 *
 * @return uint8_t valid LED brightness
 */
uint8_t indicator_tp_get_last_valid_brightness(void);

#ifdef __cplusplus
}
#endif
