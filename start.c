#include <stdint.h>
#define UART0_BASE 0x1c090000

//this is for the ARM-A7 (32 bit) Cortex-A15

void printAlbaOsForArm(){
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
}

void start() {
    printAlbaOsForArm();
    
}
