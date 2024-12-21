#include <stdint.h>
#include "printf.h"
//this is for the ARMv7-A (32 bit) Cortex-A15



void uart_printf(const char* format, ...);

//base address of the first UART
#define UART0_BASE 0x1c090000
void printAlbaOsForArm(){
    //raw printing lol
    *(volatile uint32_t *)(UART0_BASE) = 'A';
    *(volatile uint32_t *)(UART0_BASE) = 'L';
    *(volatile uint32_t *)(UART0_BASE) = 'B';
    *(volatile uint32_t *)(UART0_BASE) = 'A';
    *(volatile uint32_t *)(UART0_BASE) = 'O';
    *(volatile uint32_t *)(UART0_BASE) = 'S';
    *(volatile uint32_t *)(UART0_BASE) = ' ';
    *(volatile uint32_t *)(UART0_BASE) = 'F';
    *(volatile uint32_t *)(UART0_BASE) = 'O';
    *(volatile uint32_t *)(UART0_BASE) = 'R';
    *(volatile uint32_t *)(UART0_BASE) = ' ';
    *(volatile uint32_t *)(UART0_BASE) = 'A';
    *(volatile uint32_t *)(UART0_BASE) = 'R';
    *(volatile uint32_t *)(UART0_BASE) = 'M';
    *(volatile uint32_t *)(UART0_BASE) = '\n';
}
void testprintf(){
        uart_printf("AlbaOS For Arm Now Works\n");

}
void start() {
    testprintf();
    
}
