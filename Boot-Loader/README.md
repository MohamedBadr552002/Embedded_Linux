# Bootloader
* The bootloader is a piece of code responsible for
  * Basic hardware initialization
  * Loading of an application binary, usually an operating system kernel, from flash storage, from the network, or from another type of non-volatile storage.
  * Possibly decompression of the application binary
  * Execution of the application
* Besides these basic functions, most bootloaders provide a shell or menu
  * Menu to select the operating system to load
  * Shell with commands to load data from storage or network, inspect memory, perform hardware testing/diagnostics

## Booting on x86 Platforms

### 1-BIOS Booting

![image](https://github.com/user-attachments/assets/3513cf93-b182-4f70-9bd3-01e92f7f30f2)

* Part of the hardware platform, closed-source, rarely modifiable Implements the booting process
* Provides runtime services that can be invoked - not commonly used Stored in some flash memory, outside of regular user-accessible storage devices
* Due to the limitation in size of the bootloader, bootloaders are split into two stages:
  * Stage 1, which fits within the 446 bytes constraint
  * Stage 2, which is loaded by stage 1, and can therefore be bigger

### 2-UEFI Booting

![image](https://github.com/user-attachments/assets/8778499c-7cbc-444d-a407-0be4bb3eac5e)

* UEFI offers faster booting and security booting operation
* UEFI Describes the interface between the operating system and the firmware, Firmware in charge of booting, Firmware also provides runtime services to the operating system.
* Stored in some flash memory, outside of regular user-accessible storage devices

## Booting on Embedded Platforms
*  Most embedded processors include `a ROM code` that implements the initial step of the boot process The ROM code is written by the processor vendor and directly built into the processor
*  Responsible for finding a suitable bootloader, loading it and running it rom NAND/NOR flash, from USB, from SD card, from eMMC, etc.
*  Generally runs with the external RAM not initialized, so it can only load the bootloader into an internal SRAM

![image](https://github.com/user-attachments/assets/fe4a41c5-98f7-407d-b722-c6ff32b73554)

### U-boot Bootloader
![image](https://github.com/user-attachments/assets/2d288b07-49ca-4d27-a1bb-aa14c6f46f0f)

* Loaded by BIOS or UEFI to run from RAM to load the kernel
* To meet the need of a two-stage boot process, U-Boot has the concept of `U-Boot SPL`, The SPL is a stripped-down version of U-Boot, made small enough to meet the size constraints of a first stage bootloader

