#include "spi_read.h"
#define SPI1_BSY (1U<<7)
#define SPI1_TXE (1U<<1)
#define SPI1_RXE (1U<<0)

static uint8_t dummy_data;
void read(int16_t*x,int16_t*y,int16_t*z)
{
	volatile uint8_t data[6];
	cs_en();
	*((volatile uint8_t*)&SPI1->DR)=0xF2;
	while((SPI1->SR&SPI1_TXE)==0){}
	while((SPI1->SR&SPI1_RXE)==0){}
	dummy_data=*((volatile uint8_t*)&SPI1->DR);

	for(int i=0;i<6;i++)
	{
		*((volatile uint8_t*)&SPI1->DR)=0x00;
		while((SPI1->SR&SPI1_TXE)==0){}
		while((SPI1->SR&SPI1_RXE)==0){}
		data[i]=*((volatile uint8_t*)&SPI1->DR);

	}
    while(SPI1->SR & SPI1_BSY){}

   cs_dis();
*x=(int16_t)((data[1]<<8)|data[0]);
*y=(int16_t)((data[3]<<8)|data[2]);
*z=(int16_t)((data[5]<<8)|data[4]);

}


