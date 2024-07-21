/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include <avr/io.h>
#include <util/delay.h>

#include "../include/spi.h"

/*
    Main application
*/

// spi.c
//
// SPI master routines were pulled from the Atmel ATMega168 datasheet.



// Initialize the SPI as master
void SPI_Init()
{
	// make the MOSI, SCK, and SS pins outputs
	SPI_DDR |= ( 1 << SPI_MOSI ) | ( 1 << SPI_SCK ) | ( 1 << SPI_SS );

	// make sure the MISO pin is input
	SPI_DDR &= ~( 1 << SPI_MISO );

	// set up the SPI module: SPI enabled, MSB first, master mode,
	//  clock polarity and phase = 0, F_osc/16
	SPI_SPCR = ( 1 << SPI_SPE ) | ( 1 << SPI_MSTR );// | ( 1 << SPI_SPR0 );
	SPI_SPSR = 1;     // set double SPI speed for F_osc/2
}

// Transfer a byte of data
uint8_t SPI_SendByte( uint8_t data )
{
	// Start transmission
	SPI_SPDR = data;

	// Wait for the transmission to complete
	spi_wait();

	// return the byte received from the slave
	return SPI_SPDR;
}


// Transfer a byte of data
uint8_t SPI_ReadByte( void )
{
	// Start transmission
	SPI_SPDR = 0xFF;

	// Wait for the transmission to complete
	spi_wait();

	// return the byte received from the slave
	return SPI_SPDR;
}


// Assert the SS line
void SPI_AssertSS()
{
	SPI_PORT &= ~(1 << SPI_SS);
}

// Deassert the SS line
void SPI_DeassertSS()
{
	SPI_PORT |= (1 << SPI_SS);
}
int main(void)
{
    /* Initializes MCU, drivers and middleware */
SPI_Init();
SPI_SendByte(0x55);

        
    while (1){
    }
}
/**
    End of File
*/