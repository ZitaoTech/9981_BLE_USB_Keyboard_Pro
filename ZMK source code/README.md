# How to use or modify the source code

First you need to build the toolchain of ZMK firmware, it's recommended to build it under Github Codespaces. Here are the steps for you to build the toolchain via Codespaces:  
0. Register a Github account if you don't have one
1. Access the zmk firmware [github page](https://github.com/zmkfirmware/zmk)  
2. Create a codespace by clicking this icon:

<p align="center">
<img width="744" height="496" alt="image" src="https://github.com/user-attachments/assets/3c08bbc8-ac93-4895-8304-b2366401aae5" >
 </p>
 
3. When the codespace is finished setting up, type ```cd zmk ``` in the terminal of the codespace
4. type ```west init -l app/``` in the terminal
5. type ```west update``` and wait about 5-10 minutes and the toolchain is finished setting up
6. copy and paste the ```bbp9981``` folder into the ```app/boards/arm``` folder
7. compile the firmware by using ```cd app``` and ```west build -p -b bbp9981``` and zmk will start compiling the firmware
8. the compiled firmware is ```app/build/zephyr/zmk.uf2```. You can download and update the firmware

## Or build with github action:

Please refer to this [page](https://github.com/ZitaoTech/zmk-config-9981-pro)
