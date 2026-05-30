// mock_stm32f4xx.h
#ifndef MOCK_STM32F4XX_H
#define MOCK_STM32F4XX_H

#include <stdint.h>

// 1. Mirror the peripheral register structures from the real CMSIS headers
typedef struct {
    volatile uint32_t MODER;    // GPIO port mode register
    volatile uint32_t OTYPER;   // GPIO port output type register
    volatile uint32_t OSPEEDR;  // GPIO port output speed register
    volatile uint32_t PUPDR;    // GPIO port pull-up/pull-down register
    volatile uint32_t IDR;      // GPIO port input data register
    volatile uint32_t ODR;      // GPIO port output data register
    volatile uint32_t BSRR;     // GPIO port bit set/reset register
    volatile uint32_t LCKR;     // GPIO port configuration lock register
    volatile uint32_t AFR[2];   // GPIO alternate function registers
} GPIO_TypeDef;

typedef struct {
    volatile uint32_t CR1;      // SPI control register 1
    volatile uint32_t CR2;      // SPI control register 2
    volatile uint32_t SR;       // SPI status register
    volatile uint32_t DR;       // SPI data register
    volatile uint32_t CRCPR;    // SPI CRC polynomial register
    volatile uint32_t RXCRCR;   // SPI RX CRC register
    volatile uint32_t TXCRCR;   // SPI TX CRC register
    volatile uint32_t I2SCFGR;  // SPI_I2S configuration register
    volatile uint32_t I2SPR;    // SPI_I2S prescaler register
} SPI_TypeDef;

typedef struct {
    volatile uint32_t CR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t AHB1RSTR;
    volatile uint32_t AHB2RSTR;
    volatile uint32_t AHB3RSTR;
    uint32_t RESERVED0;
    volatile uint32_t APB1RSTR;
    volatile uint32_t APB2RSTR;
    uint32_t RESERVED1[2];
    volatile uint32_t AHB1ENR;   // GPIO clocks are enabled here
    volatile uint32_t AHB2ENR;
    volatile uint32_t AHB3ENR;
    uint32_t RESERVED2;
    volatile uint32_t APB1ENR;
    volatile uint32_t APB2ENR;   // SPI1 clock is enabled here
} RCC_TypeDef;

// 2. Declare the fake hardware structures allocated in PC RAM
extern GPIO_TypeDef  Mock_GPIOA;
extern SPI_TypeDef   Mock_SPI1;
extern RCC_TypeDef   Mock_RCC;

// 3. Point your production code's macros directly to these fake allocations
#define GPIOA               (&Mock_GPIOA)
#define SPI1                (&Mock_SPI1)
#define RCC                 (&Mock_RCC)

// 4. Duplicate the exact hardware register bit masks your code depends on
#define RCC_AHB1ENR_GPIOAEN (1U << 0)
#define RCC_APB2ENR_SPI1EN  (1U << 12)

#define SPI_CR1_SPE         (1U << 6)
#define SPI_SR_TXE          (1U << 1)
#define SPI_SR_RXNE         (1U << 0) // Matching your code's RXE bit
#define SPI_SR_BSY          (1U << 7)

#endif // MOCK_STM32F4XX_H
