#include "spi_write.h"
#define SPI1_TXE (1U<<1)
#define SPI1_RXE (1U<<0)
#define SPI1_BSY (1U<<7)


static uint8_t dummy_data;

void write(void)
{
	cs_en();
	*((volatile uint8_t*)&SPI1->DR)=0x31;
	while((SPI1->SR&SPI1_TXE)==0){}
	while((SPI1->SR&SPI1_RXE)==0){}
	dummy_data=*((volatile uint8_t*)&SPI1->DR);
	*((volatile uint8_t*)&SPI1->DR)=0x08;
	while((SPI1->SR&SPI1_TXE)==0){}
	while((SPI1->SR&SPI1_RXE)==0){}
	dummy_data=*((volatile uint8_t*)&SPI1->DR);
    while(SPI1->SR & SPI1_BSY){}

	cs_dis();
	for(int i=0; i<100;i++){}
	cs_en();
	*((volatile uint8_t*)&SPI1->DR)=0x2D;
	while((SPI1->SR&SPI1_TXE)==0){}
	while((SPI1->SR&SPI1_RXE)==0){}
	dummy_data=*((volatile uint8_t*)&SPI1->DR);
	*((volatile uint8_t*)&SPI1->DR)=0x08;
	while((SPI1->SR&SPI1_TXE)==0){}
	while((SPI1->SR&SPI1_RXE)==0){}
	dummy_data=*((volatile uint8_t*)&SPI1->DR);
    while(SPI1->SR & SPI1_BSY){}

	cs_dis();


}
