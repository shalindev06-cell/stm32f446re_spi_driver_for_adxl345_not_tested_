# spi_driver_for_adxl345
 SPI peripheral driver for the ADXL345 3-axis accelerometer, targeted for the STM32F446RE
# ADXL345 Accelerometer Driver (Bare-Metal SPI)

Hey there! This is a bare-metal C driver for the ADXL345 3-axis accelerometer, written specifically for the **STM32F446RE** using STM32CubeIDE.

###  Project Status
* **Low-Level SPI Peripheral:** Fully tested and verified working on hardware! 
* **Sensor Logic:** tested and verified using a physichal hardware
### How to Wire It Up
The SPI1 peripheral pins are mapped out to the sensor as follows:

* **PA4** → **CS** (Chip Select - Active Low)
* **PA5** → **SCK** (Serial Clock)
* **PA6** → **MISO** (Master In Slave Out / SDO)
* **PA7** → **MOSI** (Master Out Slave In / SDA)

*Make sure your breakout board is getting a safe, stable 3.3V supply!*
###  Clock & Speed Configuration
* **System Clock:** 16 MHz (Running on default HSI, no PLL required/can be changed if pll needed inside the spi_driver.c file ).
* **SPI Baud Rate:** 500 kHz (SPI prescaler set to 32/can be changed inside the spi_driver.c file).
* Uses SPI1 in this code and can be changed to any SPI but also need to change the pins accrding to which SPI module is used 
* *Note: 500 kHz was chosen intentionally for initial testing. It provides highly reliable signal integrity over breadboard jumper wires while staying well within the ADXL345's 5 MHz maximum limit.*

### What's Left to Do
- [ ] Connect the physical ADXL345 and verify the `DEVID` (0xE5) register read match(this is to check if the sensor is working in  the spi write function change the address to 0x80 and read the dummy data it will be 0xE5 if our sensor is recongonised )..
- [ ] Convert the raw two's complement data into human-readable 'g' values.

### Exploring the Code
If you want to look at the driver architecture, switch over to the `before_testing` branch and check out the `Core/Src` and `Core/Inc` directories. 

This project is open-source under the Apache 2.0 License. Feel free to look around or adapt the SPI layer for your own hardware!
