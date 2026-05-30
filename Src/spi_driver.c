#include "spi_driver.h"
#define RCC_SPI1_EN    (1U<<12)
#define RCC_GPIOAEN    (1U<<0)
#define SPI1_BIDIMODE  (1U<<15)
#define SPI1_CPOL_MODE (1U<<1)
#define SPI1_CPHA_MODE (1U<<0)
#define SPI1_LSBFIRST  (1U<<7)
#define SPI1_SSM       (1U<<9)
#define SPI1_SSI       (1U<<8)
#define SPI1_MSTR      (1U<<2)
#define SPI1_DFF       (1U<<11)
void cs_en(void);
void cs_dis(void);

void spi_config(void)
{

	//enable clock access to spi
	RCC->APB2ENR |=RCC_SPI1_EN;
	//enable clock access to gpio
	RCC->AHB1ENR |=RCC_GPIOAEN;
	//MAKE PA4 AS CS

	GPIOA->MODER |=(1U<<8);
	GPIOA->MODER &=~(1U<<9);
	//enable alternate function to gpio
	GPIOA->MODER |=(1U<<11);
	GPIOA->MODER &=~(1U<<10);
	GPIOA->MODER |=(1U<<13);
	GPIOA->MODER &=~(1U<<12);
	GPIOA->MODER |=(1U<<15);
	GPIOA->MODER &=~(1U<<14);
	GPIOA->AFR[0] &= ~(15U << 20);  // Clear bits 23:20
	GPIOA->AFR[0] |=  (5U  << 20);  // Set AF5
	GPIOA->AFR[0] &=~(15U<<24);
	GPIOA->AFR[0] |=(5U<<24);
	GPIOA->AFR[0] &=~(15U<<28);
	GPIOA->AFR[0] |=(5U<<28);
	//DISABLE BIDIMOD
	SPI1->CR1=0;
	SPI1->CR2=0;
	SPI1->CR1 &=~ SPI1_BIDIMODE;
	//CONFIGURE SERIER CLOCK BAUDRATE
	SPI1->CR1 |=(1U<<5);//USE IT AS F/32(100)
	SPI1->CR1 &=~(1U<<3);
	SPI1->CR1 &=~(1U<<4);

	// CONFIGURE CPOL AND CPHA
    SPI1->CR1 |=SPI1_CPOL_MODE;
    SPI1->CR1 |=SPI1_CPHA_MODE;
    //CONFIGURE LSBFIRST IN MSBFIRST MODE
    SPI1->CR1 &=~SPI1_LSBFIRST;
    //SET SSM AND SSI
    SPI1->CR1 |=SPI1_SSM;
    SPI1->CR1 |=SPI1_SSI;
    // ENABLE MASTER MODE
    SPI1->CR1 |=SPI1_MSTR;
    //DFF SETING
    SPI1->CR1 &=~SPI1_DFF;
    GPIOA->ODR |= (1U<<4);  // Deassert CS high on init
}
void cs_en(void)
{
    GPIOA->ODR &= ~(1U<<4);
}
void cs_dis(void)
{
    GPIOA->ODR |= (1U<<4);
}

