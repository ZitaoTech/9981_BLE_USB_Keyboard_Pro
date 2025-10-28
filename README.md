# P9981 BLE&USB Keyboard Pro ⌨️
The fully open-sourced P9981 BLE&USB Keyboard is the smallest ZMK-powered keyboard mouse combo and features n-Key rollover that other original blackberry keyboards don't have!

# Image Gallery
<img src="https://github.com/user-attachments/assets/a6b91330-bd4f-4de7-83a6-078fb6cecff9"/>
<table>
    <tr>
        <td><img src="https://github.com/user-attachments/assets/34680f5f-0e0e-4d0e-88fc-5a45a9d949fd"  style="width:700px;"/></td>
        <td><img src="https://github.com/user-attachments/assets/3eb1f541-e02e-4cde-b5e8-41f7481c6407"  style="width:700px;"/></td>
    </tr>

</table>





## Contents
- [About this keyboard](#About-this-keyboard-)
- [Before you buy/use](#Before-you-buy-)
- [Where to buy](#Where-to-buy-)
- [How to use this keyboard](#How-to-use-this-keyboard-)
- [How to connect this keyboard with your device](#How-to-connect-this-keyboard-with-your-device-)
- [Multi device connect](#Multi-device-connect)
- [Trackpad](#Trackpad-)
- 
# About this keyboard [🔼](#contents)
This mini Keyboard uses the cloned P9981 keycap with Blackberry 9380 trackpad and powered by the NRF52840 Microcontroller and operates under ZMK Firmware with extra custom driver.  


| Main Features      |  |   
| :---        |    :----:   | 
| Processor      | [NRF52840](https://www.nordicsemi.com/products/nrf52840) from Nordic Semiconductor | 
| Firmware   | ZMK firmware  | 
| Backlight | Keyboard with white backlight|
|Battery type| Integrated li-on battery|
|Battery capacity| 750mah with up to 3 months battery life(assume 1 hour per day)|
|Mouse and scroll wheel 2 in 1|When Capslock, the trackpad works as scroll wheel|
|USB&BLE Output|Support both wired and wireless connect|
|Shoulder keys|There are two shoulder keys on top|
|Small size| The smallest wireless keyboard mouse combo in the world|
|Aluminium body|The upper case is made of aluminium, lower case 3d printed|
|Multidevice connect| The keyboard can be paired with up to 4 devices at the same time|
|__NKRO__|__There are integrated diodes on the keyboard, all the keys can be pressed at the same time__(Other original Blackberry keyboards don't have this feature)|

## Before you buy/use [🔼](#contents)

**Bluetooth version check**: This keyboard can only be paired wirelessly with devices that have **BLE 4.2 module or higher**, please check if your device have the right Bluetooth module, otherwise the keyboard can not work with your device wirelessly!  
How to check the Bluetooth version of your device: google (your device name) like iphone 8 and plus Bluetooth version and you will find the answer like this:
 <img src="https://github.com/ZitaoTech/BB9900-USB_BLE_Keyboard/blob/main/Pics/BLE%20VERSION%20check.png" width = "500" height = "200" alt="BLE VERSION CHECK" align=center />

## Where to buy [🔼](#contents)
- **If you are outside China**:    
- **If you are in China**: 在闲鱼搜索用户御坂200016号

# How to use this keyboard [🔼](#contents)
- By default the keyboard has 4 Layers, when you just turn on the keyboard, the keyboard is at layer0-the QWERTY layer.  
- When you tap or hold the ```SYM``` key, the keyboard will enter layer1, and the keyboard backlight will start blinking, you can type numbers or symbols at this layer.  
- When you tap or hold the ```aA``` key at the lower right corner, the keyboard will enter layer2 and the keyboard backlight will do a loop effect, you can type some symbols and do some Bluetooth behaviors at this layer.
- The layer 3 basically has no keycode, this layer is reserved for the customer, and the keyboard will blink the twice speed as the layer 1.  


**Now let's check the keymap.**  
## Keymap [🔼](#contents)
**Layer0-QWERTY**    
<p align="center">
  <img src="https://github.com/user-attachments/assets/7bf9b876-41b6-4618-8528-f4447dbfe77d" width="100%" alt="9981_PRO_layer0">
</p>

> [!NOTE]
> - **What means sticky ctrl?** If you want to copy something, you can tap Ctrl and then tap C, the keyboard will triger Ctrl+C, you can do that with one hand.  
> - **What means sticky layer?** A sticky layer stays pressed until another key is pressed. Example: when you short type sym key, the keyboard will enter sticky layer1 after you type the "B" key, the keyboard will type "!" and return to layer0, it's easier to type with one hand.  
> - **What means lock layer?** The "lock layer" behavior enables a layer while a certain key is pressed. Example: when you want to type many numbers you can hold the sym key and tap "WER" and the keyboard will type "123", when you release the sym key, the keyboard will return to layer 0.  
> - **What means to layer?** By default when you double tap the dollar key, the keyboard will go to layer 1, then you can type numbers without pressing the sym key, you need to manually return to layer0 by tap the sym key at layer1.  

**Layer1-Numbers and symbols**    
<p align="center">
<img src="https://github.com/user-attachments/assets/12def0c4-4b1e-46fd-893f-cd3280318965" width="100%" alt="9981_PRO_layer1"> 
</p>
 
**Layer2-Functional keys**   
<p align="center">
<img src="https://github.com/user-attachments/assets/e7b2ab51-f7c6-4130-9f65-834ff672cf56" width="100%" alt="9981_PRO_layer2">  
</p>

> [!NOTE]
> - **What does Eject key do?** When you press E at layer 2, the keyboard will type Eject, Eject can ```bring up``` or ```disable``` keyboard on screen on iphone, this key is important because on iphone by default the keyboard on screen is disable when iphone is connected withe external keyboard.
> - Double tap the trackpad on this layer which trigger the ```Clear bluetooth pairing``` is very important to pair with another device more info please check the content [How to connect this keyboard with your device](How-to-connect-this-keyboard-with-your-device-)
> - This Layer contains many important keycode about Bluetooth connect and Multiconnect, more info please check

**Layer3-Reserved layer for extra keys**   
<p align="center">
<img src="https://github.com/user-attachments/assets/6eaa7f11-12d5-480a-a6e3-967efd103660" width="100%" alt="9981_PRO_layer3"> 
</p>

> [!NOTE]
> - You enter Layer 3 by double tap dollar key at layer 1, you can customize how to enter this layer yourself by editting the keymap.  
> - You can set some key at this layer as Media key like ```next song``` or ```pause``` which I think should be useful.

## How to connect this keyboard with your device [🔼](#contents)
- Turn on the Bluetooth on your phone
- Find the device ```bbp9981``` and pair with it then you should type with the keyboard
- There are some settings for IOS users, please check this.
> [!CAUTION]
> After you delete the bluetooth profile and if you want to pair with the keyboard with another device when you have already paired with some device before, make sure to enter layer 2 and double tap the trackpad to clear the bluetooth profile on the keyboard side. Otherwise there will be error when you want to pair with another device!!! Please use the following steps to delete the bluetooth pairing
- First delete the bluetooth profile(somewhere it's called forget the device or unpair the device) on your device
- Enter layer 2 and doubletap the trackpad(You can tap the lower right aA key to trigger sticky layer 2 or hold the aA key to enter layer2)
- Refresh the Bluetooth setting page on your device(You can turn on and off the bluetooth) and then you can pair with the keyboard again

## Multi device connect [🔼](#contents)
By default the keyboard can be paired with 4 devices at the same time and can be switched between them seamlessly. Here are the steps how to connect with devices:

## Trackpad [🔼](#contents)

## <a name='Realtime Keymap Updating  '>Realtime Keymap Updating   </a>
[ZMK Studio](https://zmk.dev/docs/features/studio) provides runtime update functionality to ZMK powered devices, allowing users to change their keymap layers without flashing new firmware to their keyboards.  

You can use ZMK Studio with ```Chrome/Edge``` at [https://zmk.studio/](https://zmk.studio/).  

Before you use ZMK Studio, you need to ```turn off``` the bluetooth from your phone that the keyboard is paired with, then you can select the port shown on the ZMK Studio page and then start the keymap updating.  

The picture below shows you how it looks like when the keyboard connects with ZMK Studio successfully.

<img width="3102" height="1390" alt="image" src="https://github.com/user-attachments/assets/dcad38e5-0f24-43c1-82c1-8d4393dfe47e" />

> [!NOTE]
> Currently The ZMK Studio is still beta version, there are some functions that ```can not``` be configured e.g. macro, 
> there is another advanced way to update the keymap, please check the content below

## Bluetooth connect [🔼](#contents)
## <a name='Advanced Keymap Updating  '>Advanced Keymap Updating   </a>
## <a name='Mouse DPI change on the fly  '> Mouse DPI change on the fly   </a>
## <a name='How to update the firmware  '> How to update the firmware   </a>
## <a name='Emergency way to enter bootloader  '> Emergency way to enter bootloader   </a>
# <a name='Some tipps for using this keyboard  '>Some tipps for using this keyboard  
## <a name='iphone or IOS users  '>iphone or IOS users  
# <a name='Advanced methods of using this keyboard  '>Advanced methods of using this keyboard   </a>  
## <a name='Build your own firmware   '>Build your own firmware   </a> 
First you need to build the toolchain of ZMK firmware, it's recommended to build it under Github Codespaces. Here are the steps for you to build the toolchain via Codespaces:  
0. Register a Github account if you don't have one
1. Access the zmk firmware [github page](https://github.com/zmkfirmware/zmk)  
2. Create a codespace by clicking this icon:  
<img width="744" height="496" alt="image" src="https://github.com/user-attachments/assets/3c08bbc8-ac93-4895-8304-b2366401aae5" />
 
3. When the codespace is finished setting up, type ```sh ``` in the terminal of the codespace  

# <a name='Others  '>Others   </a>  
## <a name='dimensions about the keyboard  '>dimensions about the keyboard   </a>  
The picture below shows the outerline dimension of the keyboard  
<img width="1786" height="1216" alt="9981_PRO_dimension" src="https://github.com/user-attachments/assets/2382bf18-76bf-47c8-8188-512b67dbcade" />
## <a name='Weight  '>Weight   </a>  
The total weight of the keyboard is 53.3 g
