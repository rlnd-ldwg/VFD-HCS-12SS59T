/* 
 * File:   vfd.c
 * Author: roland
 *
 * Created on July 22, 2024, 6:46 PM
 */

#define F_CPU 12000000

#include <util/delay.h>
#include "../include/vfd.h"
#include "../include/spi.h"


char getCode(char c)
{
	if(c>='@' && c<='_')				// 64.. -> 16..
		c -= 48;
	else if(c>=' ' && c<='?')			// 32.. -> 48..
		c += 16;
	else if(c>='a' && c<='z')			// 97.. -> 17..
		c -= 80;
	else								// unvalid -> ?
		c = 79;

	return c;
}

void VFD_Init()
{
	SPI_Init();
   
    VFD_DDR |= (1 << VFD_RESET) | (1 << 1);
    VFD_PORT |= (1 << VFD_RESET);
    // Reset VFD 
    VFD_PORT &= ~(1 << VFD_RESET);
    _delay_ms(1);
    VFD_PORT |= (1 << VFD_RESET);

        SPI_SS_L();

	SPI_Send(NUMDIGIT | 12);		// number of digits
        _delay_us(10);
	SPI_Send(DUTY | 4);					// brightness 1..15
        _delay_us(10);
	SPI_Send(LIGHTS | LINORM);	
        _delay_us(10);
            SPI_SS_L();
/* Hardwareseitig nich implemetiert 
	pinMode(Pin_VFD_VDON, OUTPUT);			// _VDON output
	digitalWrite(Pin_VFD_VDON, HIGH);		// Vdisp OFF
*/
    
/* interner Puffer für Text 	for(int16_t i=0; i<NUMDIGITS; i++)		// preset display buffer
		buf[i] = 0xff;						// with unused char

	buf[NUMDIGITS] = '\0';					// terminate buffer
*/
}

/*void VFD::write(char* text)
{
	scrLen = strlen(text);
	scrPos = NUMDIGITS-1;

	if(scrLen > BUFSIZE-1){
		scrLen = BUFSIZE-1;
		text[scrLen] = '\0';
	}

	strcpy(buf, text);
	display();
}
*/
void VFD_display(uint8_t* text)
{
    uint8_t i = 0;
    
    SPI_SS_L();

    SPI_Send(DCRAM_WR | 0x00); // Adresse 0
    _delay_us(10);

    while (text[i]) {
        SPI_Send(getCode(text[i++]));
            _delay_us(10);
    };
    
    SPI_SS_H();
} 
