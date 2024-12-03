#include "io.h"

//kernel jump point
int main(){
    //dont touch
    uart_init();


    uart_writeText("Hello world!\n");

    //leave this or die
    while (1);
    return 0;
}
