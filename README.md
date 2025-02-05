# PiVoyager firmware 

This repository contains all the source code for the STM32F0xx ARM Cortex
MCU on the PiVoyager, the best UPS for the Raspberry Pi!

## Directories

`firmware` contains the code for the STM32F0 UPS driver.

`bootloader` contains the code for the I2C STM32F0 bootloader.

## Compiling

Compiling the firmware requires the very small subset of CMSIS libraries that come with [stm32 standard peripheral library][2] (STSW-STM32048, Filter for STM32F0). The code itself does not use standard peripheral library but relies on direct programming of STM32F0 registers.

To compile the code, you will need to edit the `LIBROOT` variable in the Makefile to point to the location of your copy of the standard peripheral library.

Compilation relies on the `gcc-arm-none-eabi` toolchain and `make`.
Ubuntu ARM:
```
$ sudo apt install gcc-arm-none-eabi
$ make -C bootloader
$ make -C firmware
```

The approach is derived from the one described by [Geoffrey Brown, of University of Indiana][1]

## License

This code is licensed under the MIT licence, as described in the LICENSE file.

[1]: https://www.cs.indiana.edu/~geobrown/book.pdf
[2]: https://www.st.com/en/embedded-software/stm32-standard-peripheral-libraries.html?querycriteria=productId=LN1939
