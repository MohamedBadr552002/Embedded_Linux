## Tool-Chain
It's a set of tools that compiles source code into executable that can run on target device including compiler, assembler and linker

![Screenshot from 2024-10-17 14-16-11](https://github.com/user-attachments/assets/e970838e-55a3-469c-b563-c7d103574180)

### Cross tool-chain Structure
`<architecture name> <vendor name (Optionally)> <OS/none> <ABI/C library>`

* These tuples are 3 or 4 parts:
  * The architecture name: arm, riscv, mips64el, etc.
  * Optionally, a vendor name, which is a free-form string
  * An operating system name, or none when not targeting an operating system
  * The ABI/C library (see later)

* Binutils is a set of tools to generate and manipulate binaries (usually with the ELF format) for a given CPU architecture
  * as, the assembler, that generates binary code from assembler source code
  * ld, the linker
  * ar, ranlib, to generate .a archives (static libraries)
  * objdump, readelf, size, nm, strings, to inspect binaries. Very useful analysis tools!
  * objcopy, to modify binaries
  * strip, to strip parts of binaries that are just needed for debugging (reducing their size).

### Linux vs. bare-metal toolchain
* A Linux toolchain
  * is a toolchain that includes a Linux-ready C standard library, which uses the Linux system calls to implement system services
  * can be used to build Linux user-space applications, but also bare-metal code (firmware, bootloader, Linux kernel)
  * is identified by the linux OS identifier in the toolchain tuple: arm-linux, arm-none-linux-gnueabihf
* A bare metal toolchain
  * is a toolchain that does not include a C standard library, or a very minimal one that isn’t tied to a particular operating system
  * can be used to build only bare-metal code (firmware, bootloader, Linux kernel)
  * is identified by the none OS identifier in the toolchain tuple: arm-none-eabi, arm-none-none-eabi (vendor is none, OS is none)

### ABI
* When building a toolchain, the ABI used to generate binaries needs to be defined
* ABI, for Application Binary Interface, defines the calling conventions (how function arguments are passed, how the return value is passed, how system calls are made) and the organization of structures (alignment, etc.)
* All binaries in a system are typically compiled with the same ABI, and the kernel must understand this ABI.

## Building a toolchain manually Using crosstool-NG
* Typical process is:
  * Build dependencies of binutils/gcc (GMP, MPFR, ISL, etc.)
  * Build binutils
  * Build a baremetal, first stage GCC
  * Extract kernel headers from the Linux source code
  * Build the C library using the first stage GCC
  * Build the second stage and final GCC supporting the Linux OS and the C library.

![Screenshot from 2024-10-17 15-25-54](https://github.com/user-attachments/assets/80756e83-7356-4a0d-bbd6-7c6a7eb0debf)


### Instaling crosstool-NG
Make Sure from your dependencies in your machine 
```sh
sudo apt-get install autoconf automake bison bzip2 cmake flex g++ gawk gcc gettext git gperf help2man libncurses5-dev libstdc++6 libtool libtool-bin make patch python3-dev rsync texinfo unzip wget xz-utils
```
```sh
git clone https://github.com/crosstool-ng/crosstool-ng.git
```
```sh
cd crosstool-ng
git checkout crosstool-ng-1.26.0
```
```sh
./bootstrap
```
```sh
./configure --prefix=${PWD}
sudo make
sudo make install
```

### Run crosstool-NG
Navigate to the bin directory
```sh
cd /bin
```

List all Target devices
```sh
./ct-ng list-samples
```

Extract Configuration file based on target
```sh
./ct-ng <target name>
```
![Screenshot from 2024-10-17 15-23-54](https://github.com/user-attachments/assets/893d3b57-d90b-497a-8d35-5ecc94d669a5)

Edit the Configuration file Using GUI
```sh
./ct-ng menuconfig
```
Choose Linux version 6.4.16
![Screenshot from 2024-10-17 15-36-57](https://github.com/user-attachments/assets/73d95e0c-691d-4bf6-abb1-b82f294b5422)

Configure Companion tools like that
![Screenshot from 2024-10-17 15-44-31](https://github.com/user-attachments/assets/c7f81fb1-d1ef-4ba2-86b1-5ef7356867ae)


Save these Configuratiions in `.config` file.

Then Build with identification number of Cors
```sh
./ct-ng build.3
```
**Note: if you have any problem in permissions use sudo command or change the permission of tool directory**



