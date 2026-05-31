# STM32F446RE ADXL345 SPI Driver

A bare-metal SPI driver for the ADXL345 3-axis accelerometer, developed and tested on the STM32F446RE using STM32CubeIDE.

## Overview

This project demonstrates low-level SPI communication between an STM32F446RE and an ADXL345 accelerometer without using vendor-provided sensor libraries.

The goal of the project was to learn:

* SPI peripheral configuration
* Register-level programming
* Datasheet-driven development
* Sensor interfacing
* Embedded C programming
* Hardware debugging and verification

---

## Project Status

### SPI Driver

* SPI peripheral configuration implemented
* Register read and write operations implemented
* Multi-byte register reads implemented
* Tested and verified on hardware

### ADXL345 Sensor Interface

* Sensor configuration verified
* X, Y, and Z acceleration data successfully acquired
* Sensor orientation changes correctly reflected in measured values
* Tested using a physical ADXL345 module

---

## Hardware Used

* STM32F446RE
* ADXL345 3-Axis Accelerometer
* Breadboard and jumper wires
* ST-Link debugger

---

## Wiring

SPI1 is configured as follows:

| STM32F446RE | ADXL345    |
| ----------- | ---------- |
| PA4         | CS         |
| PA5         | SCK        |
| PA6         | MISO (SDO) |
| PA7         | MOSI (SDA) |

**Note:** Ensure the ADXL345 is powered from a stable 3.3V supply.

---

## Clock and SPI Configuration

* System Clock: 16 MHz (HSI)
* SPI Peripheral: SPI1
* SPI Baud Rate: 500 kHz
* SPI Prescaler: 32

The SPI clock was intentionally kept low during initial hardware verification to improve signal reliability on a breadboard setup.

These values can be modified inside the driver source code if higher communication speeds are required.

---

## Hardware Verification

The following functionality has been verified on real hardware:

* SPI communication established successfully
* Register writes completed successfully
* Multi-byte acceleration register reads completed successfully
* Raw X, Y, and Z acceleration values obtained
* Acceleration values change correctly when the sensor orientation changes

---

## Future Improvements

* Verify the DEVID register (expected value: 0xE5) during initialization
* Convert raw acceleration values into units of g
* Add calibration and offset compensation
* Improve error handling
* Support additional ADXL345 features such as interrupts and FIFO operation

---

## Repository Structure

* `Core/Src/` - Driver source files
* `Core/Inc/` - Header files
* `chip_headers/` - Device and CMSIS headers

---

## License

This project is licensed under the Apache 2.0 License.

Feel free to use, modify, and learn from the code.
