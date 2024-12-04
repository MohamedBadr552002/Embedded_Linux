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

if you simulate Right now the kernel will panic Due to there's no existing for Root file System
```sh
qemu-system-aarch64 -M virt -cpu cortex-a53 -m 1G -kernel Image -append "console=ttyAMA0" -nographic
```
![Screenshot from 2024-12-04 15-52-10](https://github.com/user-attachments/assets/8962bba3-5493-4059-9abd-c7fb2a72fc1c)

### Build and Config Root file System

**1-Make Target root file system manually**
![Screenshot from 2024-12-04 16-01-11](https://github.com/user-attachments/assets/27f9cfb5-6e99-4ea4-b8bc-8c0c1ba87924)


**2-Clone busybox tool** 
```sh
git clone git://busybox.net/busybox.git
cd busybox
```

**3-Build busybox**
```sh
make ARCH=arm64 CROSS_COMPILE=aarch64-rpi3-linux-gnu- menuconfig
make ARCH=arm64 CROSS_COMPILE=aarch64-rpi3-linux-gnu-
```
**4-Install BusyBox to Minimal Root File System**

change `\_install` to location of target root file system
![Screenshot from 2024-12-04 16-25-05](https://github.com/user-attachments/assets/dfecd5b7-bb19-490c-8ad9-5c9e3b9c40ce)

```sh
make ARCH=arm64 CROSS_COMPILE=aarch64-rpi3-linux-gnu- install
```

