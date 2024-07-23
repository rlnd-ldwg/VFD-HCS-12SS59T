/* 
 * File:   spi.h
 * Author: roland
 *
 * Created on July 20, 2024, 6:46 PM
 */

#ifdef	__cplusplus
extern "C" {
#endif
    
#ifndef SPI_H
#define SPI_H

#include <avr/io.h>
#include <inttypes.h>

// SPI Definitions
#define SPI_DDR		DDRB
#define SPI_PORT	PORTB
#define MISO        PORTB4
#define MOSI        PORTB3
#define SCK         PORTB5
#define SS          PORTB2

/*
#define SPI_SPCR	SPCR
#define SPI_SPDR	SPDR
#define SPI_SPSR	SPSR
#define SPI_SPIF	SPIF
#define SPI_SPE		SPE
#define SPI_MSTR	MSTR
#define SPI_SPR0	SPR0
#define SPI_SPR1	SPR1
*/

// Loop until any current SPI transmissions have completed
#define spi_wait()	while (!(SPSR & (1 << SPIF)));

// Initialize the SPI subsystem
void SPI_Init();

// Transfer a byte of data
uint8_t SPI_Send( uint8_t data );

// Read a byte of data
uint8_t SPI_Read( void );

// Assert the SS line
void SPI_SS_L( void );

// Deassert the SS line
void SPI_SS_H( void );

#endif	/* SPI_H */

#ifdef	__cplusplus
}
#endif
