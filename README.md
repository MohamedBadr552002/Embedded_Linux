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

