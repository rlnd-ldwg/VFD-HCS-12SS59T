// spi.c
//
// SPI master routines were pulled from the Atmel ATMega168 datasheet.

#include "../include/spi.h"

// Initialize the SPI as master

void SPI_Init()
{
	// make the MOSI, SCK, and SS pins outputs
	SPI_DDR |= ( 1 << MOSI ) | ( 1 << SCK ) | ( 1 << SS );
	// make sure the MISO pin is input
	SPI_DDR &= ~( 1 << MISO );
    
    // SPCR : SPIE SPE DORD MSTR CPOL CPHA SPR1 SPR0 SPCR, InitialValue 0xb00000000
	// set up the SPI module: SPI enabled, LSB first, master mode, clock polarity and phase = 0, F_osc/16
	SPCR = ( 1 << SPE ) | ( 1 << DORD ) | ( 1 << MSTR ) | ( 1 << SPR0 );
	// SPSR = 1;     // set double SPI speed for F_osc/2 -> 2 MHz
}

// Transfer a byte of data
uint8_t SPI_SendByte( uint8_t data )
{
	// Start transmission
	SPDR = data;

	// Wait for the transmission to complete
	spi_wait();

	// return the byte received from the slave
	return SPDR;
}


// Transfer a byte of data
uint8_t SPI_ReadByte( void )
{
	// Start transmission
	SPDR = 0xFF;

	// Wait for the transmission to complete
	spi_wait();

	// return the byte received from the slave
	return SPDR;
}

// Assert the SS line
void SPI_AssertSS()
{
	SPI_PORT &= ~(1 << SS);
}

// Deassert the SS line
void SPI_DeassertSS()
{
	SPI_PORT |= (1 << SS);
}
