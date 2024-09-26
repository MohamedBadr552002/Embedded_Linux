# Linux Fundamentals
### What does kernel mean ?
t's a Software Component represent the OS core which manage verious tasks, it acts as an intermediation between hardware and software.
It's responsible for:

* Process management
        Creation and termination
        Process scheduling
        process switching
        Process Synchronization
* Memory management
        Allocation of processes
        Swapping
        Page and segment managment
* I/O Management
* Support Functions
        Interrupt
        Accounting
        Monitoring

### What does Operating System mean?
OS Can be defined as kernel addition to some applications

### Architecture Layer Diagram

![Architecture Layer Diagram drawio](https://github.com/user-attachments/assets/826e0cf0-1661-4c80-9ee2-138809e48e6a)


### glib Library
Glibc is the cornerstone of the C standard library for Linux and Unix-like systems, providing the necessary system call wrappers, utility functions, and runtime support that enable programs to interact with the OS and perform essential tasks like I/O, memory management, and threading. It is fundamental to the operation of nearly all software on Linux systems.

## Process Managemnet Stack
### Process
Executable Program loaded into the main memory

![Process drawio](https://github.com/user-attachments/assets/b4752830-8678-4ce7-ad84-939544ae4172)

#### Init-process
The init process is the first process started by the Linux or Unix kernel during the system boot process. It is responsible for initializing the system by starting essential system services, setting up the environment, and managing user processes. The init process is typically assigned the process ID (PID) 1, making it the parent of all processes on the system.

#### Zombie Process
When the parent didn't wait for the child (Both are runing concurrently) then the child has been terminated this child called a zombi process because its all resources allocated ,it will be deallocated but the process table still contain this process entery because it was not removed by the parent.

#### Daemon Process
a daemon is a background process that runs continuously, typically without any direct user interaction. Daemon processes often provide system services, such as managing network connections, handling hardware, or performing scheduled tasks. They typically start at boot time and continue running until the system is shut down.

### Signals 
* A software interrupt send by user (throw the Kernel) - Kernel itself - another process to a process to perform an operation
* the signal send throw the `kill` command

``` sh
kill [signal] [pid]
```

### The Actions taken by the kernel when signal sent ?
1) `Core Operation:` the required operation + core-dump file will be genrated
2) `term operation:` the required operation


### Commands

```sh
ps -j # group D + Session id + ...
ps -l # long format.
ps aux ps fax # show relations between commands.
top# monitoring prcocess.
# changing process prioity.
>nice[-20, 19].
>renice
# send signal to process
kill<signal number>
man7 signal
killall<name>
# signal 15 --> instruct a process to stop.
# signal 9 --> stop immediately.
fg# number of command ,# background to foreground.
bg# send process to packground.
jobs# display all process run in background
```


## File System Stack

### Root file system
Is the top-level directory in a Linux file system  hierarchy. It contains all the directories and files necessary to boot the system and start the user space. 

The root file system is usually stored on a non-volatile storage device like a hard drive, solid-state drive, or flash memory. The type of file system used for the root file system can have a significant impact on the performance and reliability of the system

`EXT4` This is the default file system used by many Linux distributions. It is a journaling file system that supports large file sizes and can handle a large number of files.

Mounting and unmounting a file system is a process of attaching or detaching a file system to/from a directory in the hierarchy of directories,  The syntax of the mount command is as follows: 
```sh
mount [-t fstype] [-o options] device directory
```
* fstype: The file system type (e.g., ext4, nfs, etc.) 
* options: The mount options (e.g., read-only, noexec, etc.) 
* device: The device file or remote server containing the file system data 
* directory: The directory in the file system hierarchy where the file system will be mounted

The umount command in Linux is used to detach a file system from a directory. The syntax of the umount command is as follows: 
```sh
umount directory
```

**NOTE: When no root fileSystem is available, the kernel panics**

The location of the root filesystem is a crucial aspect of a Linux system's configuration. It is where all  of the files and directories necessary for the system to boot and run are stored. 

### File System Contents 
The Linux file system is organized hierarchically, with the root directory being the top-level directory in the file system

1) `/bin` - Contains essential binaries that are required to boot the system and for everyday use, such as the ls command and the bash shell.
2) `/boot` - Contains the files needed for booting the system, including the kernel and boot loader configuration files.
3) `/dev` - Contains device files that represent hardware devices connected to the system, such as disks and network interfaces.
4) `/etc` - Contains system-wide configuration files, such as the passwd file that stores user account information.
5) `/home` - Contains home directories for all users on the system
6) `/lib` - Contains shared libraries needed by programs and other libraries.
7) `/media` - Contains mount points for removable media, such as USB drives and CDs
8) /mnt - Contains mount points for file systems that are mounted temporarily.
9) `/opt` - Contains add-on software packages that are not part of the core system distribution. 
10) `/proc` - Provides a view into the system's running processes, system status, and other system information in the form of virtual files.
11) `/root` - The home directory for the root user. 
12) `/sbin` - Contains essential system binaries, such as those needed for system maintenance and administration.
13) `/sys` - Provides a view into the system's hardware devices and drivers in the form of virtual files.
14) `/tmp` - Contains temporary files created by the system and its users.
15) `/usr` - Contains non-essential binaries, libraries, and documentation for the system.
16) `/var` - Contains variable files, such as log files, spool files, and other files that change frequently during system operation. 
