# 9981_BLE_USB_Keyboard_Pro
<img src="https://github.com/ZitaoTech/9981_BLE_USB_Keyboard_Pro/blob/main/Pic/9981_PRO_1.jpg" width = "950" height = "700" alt="View1" align=center />  


[**About this keyboard**  ](#about-this-keyboard---)  
[Before you buy/use  ](#before-you-buyuse---)  

# <a name='About this keyboard  '>About this keyboard   </a>
This mini Keyboard uses the cloned P9981 keycap with Blackberry 9380 trackpad and powered by the NRF52840 Microcontroller and operates under ZMK Firmware with extra custom driver.  


| Main Features      |  |   
| :---        |    :----:   | 
| Processor      | [NRF52840](https://www.nordicsemi.com/products/nrf52840) from Nordic Semiconductor | 
| Firmware   | ZMK firmware  | 
|Battery type| Integrated li-on battery|
|Battery capacity| 750mah with up to 3 months battery life(assume 1 hour per day)|
|Mouse and scroll wheel 2 in 1|When Capslock, the trackpad works as scroll wheel|
|USB&BLE Output|Support both wired and wireless connect|
|Shoulder keys|There are two shoulder keys on top|
|Small size| The smallest wireless keyboard mouse combo in the world|
|Aluminium body|The upper case is made of aluminium, lower case 3d printed|
|Multidevice connect| The keyboard can be paired with up to 4 devices at the same time|
|__NKRO__|__There are integrated diodes on the keyboard, all the keys can be pressed at the same time__|

## <a name='Before you buy/use  '>Before you buy/use   </a>

**Bluetooth version check**: This keyboard can only be paired wirelessly with devices that have **BLE 4.2 modul or higher**, please check if your device have the right Bluetooth modul, otherwise the keyboard can not work with your device wirelessly!  
How to check the Bluetooth version of your device: google (your device name) like iphone 8 and plus Bluetooth version and you will find the answer like this:
 <img src="https://github.com/ZitaoTech/BB9900-USB_BLE_Keyboard/blob/main/Pics/BLE%20VERSION%20check.png" width = "500" height = "200" alt="BLE VERSION CHECK" align=center />

## <a name='Where to buy  '>Where to buy   </a>  

# <a name='How to use this keyboard  '>How to use this keyboard   </a>  
## <a name='Concept of Layer   '>Concept of Layer   </a>  
## <a name='Keymap  '>Keymap   </a>
## <a name='Realtime Keymap Updating  '>Realtime Keymap Updating   </a>
[ZMK Studio](https://zmk.dev/docs/features/studio) provides runtime update functionality to ZMK powered devices, allowing users to change their keymap layers without flashing new firmware to their keyboards.  

You can use ZMK Studio with ```Chrome/Edge``` at [https://zmk.studio/](https://zmk.studio/).  

Before you use ZMK Studio, you need to ```turn off``` the bluetooth from your phone that the keyboard is paired with, then you can select the port shown on the ZMK Studio page and then start the keymap updating.  

The picture below shows you how it looks like when the keyboard connects with ZMK Studio successfully.

<img width="3102" height="1390" alt="image" src="https://github.com/user-attachments/assets/dcad38e5-0f24-43c1-82c1-8d4393dfe47e" />

⚠️**Note!** Currently The ZMK Studio is still beta version, there are some functions that ```can not``` be configured e.g. macro, there is another advanced way to update the keymap, please check the content below
## <a name='Advanced Keymap Updating  '>Advanced Keymap Updating   </a>
## <a name='How to update the firmware  '> How to update the firmware   </a>
## <a name='Emergency way to enter bootloader  '> Emergency way to enter bootloader   </a>
# <a name='Some tipps for using this keyboard  '>Some tipps for using this keyboard  
## <a name='iphone or IOS users  '>iphone or IOS users  
# <a name='Advanced methods of using this keyboard  '>Advanced methods of using this keyboard   </a>  
## <a name='Build your own firmware   '>Build your own firmware   </a> 
First you need to build the toolchain of ZMK firmware, it's recommended to build it under Github Codespaces.
