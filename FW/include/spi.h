/* 
 * File:   spi.h
 * Author: roland
 *
 * Created on July 20, 2024, 6:46 PM
 */

/*
 * spi v0.1.0
 *
 * header file: hardware interface
 *
 * (c) July 2024 by Roland Ludwig
 * 
 * 2024/07/23 ???
 *
 */

#ifdef  __cplusplus
extern "C" {
#endif
    
#ifndef SPI_H
#define SPI_H

#include <avr/io.h>
#include <inttypes.h>

// SPI Definitions
#define SPI_DDR     DDRB
#define SPI_PORT    PORTB
#define MISO        PORTB4
#define MOSI        PORTB3
#define SCK         PORTB5
#define SS          PORTB2

#define spi_wait()  while (!(SPSR & (1 << SPIF)));  // wait for SPI tramsmission completed
#define enable_slave()  SPI_PORT &= ~(1 << SS);     // enable slave
#define disable_slave() SPI_PORT |= (1 << SS);      // disable slave

void SPI_Init();

uint8_t SPI_Send( uint8_t data );

uint8_t SPI_Read( void );

/* replaced by macros 
 // Assert the SS line
void SPI_SS_L( void );

// Deassert the SS line
void SPI_SS_H( void );
*/

#endif  /* SPI_H */

#ifdef  __cplusplus
}
#endif
