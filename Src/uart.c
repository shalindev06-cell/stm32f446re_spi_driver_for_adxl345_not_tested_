#include "uart.h"

#define UART2EN       (1U<<17)
#define GPIOAEN       (1U<<0)
#define UART_BAUDRATE 115200
#define CLK           16000000
#define CR1_TE        (1U<<3)
#define CR1_RE        (1U<<2)
#define CR1_UE        (1U<<13)
#define SR_TXE        (1U<<7)

static uint16_t compute_uart_bd(uint32_t periph_clk, uint32_t baudrate);
static void uart_set_baudrate(uint32_t periph_clk, uint32_t baudrate);
void usart2_write(int ch);

int __io_putchar(int ch) {
    usart2_write(ch);
    return ch;
}

void uart2_tx_init(void) {
    RCC->AHB1ENR |= GPIOAEN;
    GPIOA->MODER &= ~(1U<<4);
    GPIOA->MODER |=  (1U<<5);
    GPIOA->AFR[0] |=  (1U<<8);
    GPIOA->AFR[0] |=  (1U<<9);
    GPIOA->AFR[0] |=  (1U<<10);
    GPIOA->AFR[0] &= ~(1U<<11);
    RCC->APB1ENR |= UART2EN;
    uart_set_baudrate(CLK, UART_BAUDRATE);
    USART2->CR1 |= CR1_TE;
    USART2->CR1 |= CR1_UE;
}

void usart2_write(int ch) {
    while (!(USART2->SR & SR_TXE)) {}
    USART2->DR = (ch & 0xFF);
}

static uint16_t compute_uart_bd(uint32_t periph_clk, uint32_t baudrate) {
    return (periph_clk + (baudrate / 2U)) / baudrate;
}

static void uart_set_baudrate(uint32_t periph_clk, uint32_t baudrate) {
    USART2->BRR = compute_uart_bd(periph_clk, baudrate);
}
