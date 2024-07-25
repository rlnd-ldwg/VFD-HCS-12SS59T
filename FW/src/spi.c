/*
 * spi v0.2.0
 *
 * spi interface functions
 *
 * (c) Juli 2024 by Roland Ludwig
 *
 *  * 2024/07/24 ????
 * 
 * SPI_Init
 * SPI_Send
 * SPI_Read
 * 
 */

#include "../include/spi.h"

void SPI_Init(uint8_t spcr)
{
    SPI_DDR |= ( 1 << MOSI ) | ( 1 << SCK ) | ( 1 << SS );  // set MOSI, SCK, and SS pins as output
    SPI_DDR &= ~( 1 << MISO );  // set MISO as input
    disable_slave();            // disable slave
    SPCR = ( 1 << MSTR );       // set AVR as master 
    
    // SPCR : SPIE SPE DORD MSTR CPOL CPHA SPR1 SPR0 SPCR, InitialValue 0xb00000000
    // SPI enabled, LSB first, master mode, clock polarity, clock phase, F_osc/16
    SPCR |= spcr;   // ( 1 << SPE ) | ( 1 << DORD ) | ( 1 << MSTR ) | (1 << CPOL) | ( 1 << CPHA) | ( 1 << SPR0 );
    
    // SPSR = 1;     // set double SPI speed for F_osc/2 -> 2 MHz
} // SPI_Init

uint8_t SPI_Send( uint8_t data )
{
    SPDR = data;
    spi_wait();
    return SPDR;
} //SPI_Send

uint8_t SPI_Read( void )
{
    SPDR = 0xFF;    // Start dummy transmission to get a result from slave
    spi_wait();
    return SPDR;
} //SPI_Read

/* replaced by macros
 * // Enable slave
void SPI_SS_L()
{
    SPI_PORT &= ~(1 << SS);
}

// Disable slave
void SPI_SS_H()
{
    SPI_PORT |= (1 << SS);
}
*/
