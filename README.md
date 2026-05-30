# spi_driver_for_adxl345_not_tested_for_stm32
WIP: SPI peripheral driver for the ADXL345 3-axis accelerometer, targeted for the STM32F446RE. This codebase is currently untested.
# ADXL345 Accelerometer Driver (Bare-Metal SPI)

Hey there! This is a bare-metal C driver for the ADXL345 3-axis accelerometer, written specifically for the **STM32F446RE** using STM32CubeIDE.

### 🚀 Project Status
* **Low-Level SPI Peripheral:** Fully tested and verified working on hardware! 
* **Sensor Logic:** Work in progress. The ADXL345 register configurations and data-reading state machines are drafted but still need to be verified with the physical sensor.

### How to Wire It Up
The SPI1 peripheral pins are mapped out to the sensor as follows:

* **PA4** → **CS** (Chip Select - Active Low)
* **PA5** → **SCK** (Serial Clock)
* **PA6** → **MISO** (Master In Slave Out / SDO)
* **PA7** → **MOSI** (Master Out Slave In / SDA)

*Make sure your breakout board is getting a safe, stable 3.3V supply!*

### What's Left to Do
- [ ] Connect the physical ADXL345 and verify the `DEVID` (0xE5) register read match.
- [ ] Finalize data rate and power management configurations (`POWER_CTL`).
- [ ] Test multi-byte reads to grab the X, Y, and Z axis data streams simultaneously.
- [ ] Convert the raw two's complement data into human-readable 'g' values.

### Exploring the Code
If you want to look at the driver architecture, switch over to the `before_testing` branch and check out the `Core/Src` and `Core/Inc` directories. 

This project is open-source under the Apache 2.0 License. Feel free to look around or adapt the SPI layer for your own hardware!
