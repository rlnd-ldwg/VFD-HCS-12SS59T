/*
 * test programm VFD display Samsung HCS-12SS59T
 *
 * (c) Juli 2024 by Roland Ludwig
 *
 *  v0.2.0
 * 
 * 2024/07/24 ????
 * 
 */

#define F_CPU 12000000  // ATmega8 Testboard Ulrich Radig

#include <avr/io.h>
#include <util/delay.h>
#include "../include/spi.h"
#include "../include/vfd.h"

int main(void)
{
    uint8_t i;

    VFD_DDR |= (1 << LED);
    for (i = 1; i < 8; i++)
        VFD_PORT ^= (1 << LED);
        _delay_ms(200);
    }

    VFD_Init();

    VFD_Display("Das ist Test");
    
    while (1){
        
        VFD_PORT ^= (1 << LED);
        _delay_ms(500);
    }
} // main
