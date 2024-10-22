# Bootloader
* The bootloader is a piece of code responsible for
  * Basic hardware initialization
  * Loading of an application binary, usually an operating system kernel, from flash storage, from the network, or from another type of non-volatile storage.
  * Possibly decompression of the application binary
  * Execution of the application
* Besides these basic functions, most bootloaders provide a shell or menu
  * Menu to select the operating system to load
  * Shell with commands to load data from storage or network, inspect memory, perform hardware testing/diagnostics
