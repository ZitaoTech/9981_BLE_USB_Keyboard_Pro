# Firmware 

This page will share different firmware for 9981 pro keyboard, or you can share your own by using ```Pull requests```

### How to update the firmware?

You need to connect the keyboard with your PC and make the keyboard enter bootloader

Then a new USB Disk called NICENANO will be found by your PC

drag the firmware file: the .uf2 file into the USB Disk and the firmware is updated.

### Here is the explanation of the firmware files.

```9981_Pro_default_firmware.uf2```: 

The keymap is as shown on the github page

```9981_Pro_hold400ms_output_sym.uf2```:

When you hold the key at layer0 for more than 400ms, the keyboard will type the corresponding symbol character. You can check the keymap at this [page](https://github.com/ZitaoTech/zmk-config-9981-pro/blob/hold-400ms-output-sym-layer/config/bbp9981.keymap)

