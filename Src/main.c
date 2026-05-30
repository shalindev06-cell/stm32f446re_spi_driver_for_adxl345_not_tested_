#include "spi_driver.h"
#include "spi_write.h"
#include "spi_read.h"
#define SPI1_EN  (1U<<6)
#define SPI1_TXE (1U<<1)
#define SPI1_RXE (1U<<0)
#define SPI1_BSY (1U<<7)



 int16_t x;
 int16_t y;
 int16_t z;

int main(void)
{
    spi_config();

    SPI1->CR1 |= SPI1_EN;
    for (int i=0;i<90000;i++){}
    write();
    read(&x,&y,&z);


    while(1)
    {
        // Stop here and inspect variables
    }
}




