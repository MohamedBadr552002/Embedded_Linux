# Linux Kernel

![napkin-selection (2)](https://github.com/user-attachments/assets/416af6ba-b164-40d5-b12f-10388407b1e2)

![napkin-selection (3)](https://github.com/user-attachments/assets/581aaf10-7b55-46f6-a49f-0128129bb3b2)

## Customize Linux Kernel for Raspi3

install dependencies
```sh
sudo apt install libncurses5-dev flex bison
sudo apt install subversion libssl-dev 
sudo apt-get install qemu-system
sudo apt-get install device-tree-compiler
```

Clone the vendor linux Version
```sh
git clone --depth=1 -b rpi-4.19.y https://github.com/raspberrypi/linux.git
```
Build configuration
```sh
cd linux
KERNEL=kernel8
make ARCH=arm64 CROSS_COMPILE=< your cross compiler (aarch64-linux-gnu-)> bcm2711_defconfig
```

Build the Kernel
```sh
make ARCH=arm64 CROSS_COMPILE=< your cross compiler (aarch64-linux-gnu-)> Image modules dtbs
```
