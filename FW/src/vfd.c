/*
 * vfd v0.2.0
 *
 * vfd interface functions
 *
 * (c) Juli 2024 by Roland Ludwig
 *
 *  * 2024/07/222 ????
 * 
 * SPI_Init
 * SPI_Send
 * GALprogOff
 * SetSecurityBit
 * Bulkerase
 * GALreadRow
 * GALwriteRow
 * ReadGAL
 * ProgGAL
 * VerifyGAL
 * writeEPROMdata: 2023/09/04 initial Version
 * readEPROMdata
 *  *
 */

#define F_CPU 12000000

#include <util/delay.h>

#include "../include/vfd.h"
#include "../include/spi.h"


char getCode(char c)
{
    if(c>='@' && c<='_')                // 64.. -> 16..
        c -= 48;
    else if(c>=' ' && c<='?')           // 32.. -> 48..
        c += 16;
    else if(c>='a' && c<='z')           // 97.. -> 17..
        c -= 80;
    else                                // unvalid -> ?
        c = 79;

    return c;
}

void VFD_Init()
{
    VFD_DDR |= (1 << VFD_RESET);
    VFD_PORT |= (1 << VFD_RESET);
    
    // Reset VFD 
    VFD_PORT &= ~(1 << VFD_RESET);
    _delay_ms(1);
    VFD_PORT |= (1 << VFD_RESET);

    // SPI enabled, LSB first, master mode, clock polarity, clock phase, F_osc/16
    SPI_Init(( 1 << SPE ) | ( 1 << DORD ) | ( 1 << MSTR ) | (1 << CPOL) | ( 1 << CPHA) | ( 1 << SPR0 ));
   
    enable_slave(); // SPI_SS_L();
    _delay_us(10);

    SPI_Send(NUMDIGIT | 12);    // number of digits
    _delay_us(10);
    SPI_Send(DUTY | 4);         // brightness 1..15
    _delay_us(10);
    SPI_Send(LIGHTS | LINORM);  
    _delay_us(10);
  
 
    disable_slave();    // SPI_SS_H();

/* not implemente 
    pinMode(Pin_VFD_VDON, OUTPUT);          // _VDON output
    digitalWrite(Pin_VFD_VDON, HIGH);       // Vdisp OFF
*/

} // VFD_Init

void VFD_Display(uint8_t* text)
{
    uint8_t i = 0;
    
    enable_slave(); // SPI_SS_L();
    _delay_us(10);

    SPI_Send(DCRAM_WR | 0x00); // Address 0
    _delay_us(10);

    while (text[i]) {
        SPI_Send(getCode(text[i++]));
            _delay_us(10);
    };
    
    _delay_us(10);
    disable_slave();    // SPI_SS_H();
} // VFD_Display
