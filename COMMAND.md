## Process Managemnet Stack


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
fg # number of command ,# background to foreground.
bg # send process to packground.
jobs # display all process run in background
```



## File System Stack

```sh
lsblk     #List all block devices
fdisk     #parted Manage disk partitions
blkid     #Show block device attributes such as UUID
hwinfo    #Show hardware information
file -s   #Show filesystem and partition information
stat, df -i, ls -i #Show and list inode-related information

```
