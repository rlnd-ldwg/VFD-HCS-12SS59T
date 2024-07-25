/*
 * spi v0.1.0
 *
 * spi interface functions
 *
 * (c) Juli 2024 by Roland Ludwig
 *
 *  * 2024/07/24 ????
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

#ifndef SPI_H
    #include "../include/spi.h"
#endif

void SPI_Init()
{
    SPI_DDR |= ( 1 << MOSI ) | ( 1 << SCK ) | ( 1 << SS );  // set MOSI, SCK, and SS pins as output

    SPI_DDR &= ~( 1 << MISO );  // set MISO as input
    
    SPI_SS_H();                 // disable slave
    
    SPCR = ( 1 << MSTR );       // set AVR as master
    
    // SPCR : SPIE SPE DORD MSTR CPOL CPHA SPR1 SPR0 SPCR, InitialValue 0xb00000000
    // SPI parameter: SPI enabled, LSB first, master mode, clock polarity and phase = mode = 3, F_osc/16
    SPCR |= ( 1 << SPE ) | ( 1 << DORD ) | ( 1 << MSTR ) | (1 << CPOL) | ( 1 << CPHA) | ( 1 << SPR0 );
    
    // SPSR = 1;     // set double SPI speed for F_osc/2 -> 2 MHz
}

uint8_t SPI_Send( uint8_t data )
{
    SPDR = data;
    spi_wait();
    return SPDR;
}

uint8_t SPI_Read( void )
{
    SPDR = 0xFF;    // Start dummy transmission to get a result from slave
    spi_wait();
    return SPDR;
}

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
