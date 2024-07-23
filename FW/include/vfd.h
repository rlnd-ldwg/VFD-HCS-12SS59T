/* 
 * File:   vfd.h
 * Author: roland
 *
 * Created on July 20, 2024, 6:46 PM
 */

#ifdef  __cplusplus
extern "C" {
#endif
    
#ifndef VFD_H
#define VFD_H

// VFD Definitions
#define VFD_DDR		DDRB
#define VFD_PORT	PORTB
#define VFD_RESET   PORTB1
    
#define DCRAM_WR			0x10		// ccccaaaa dddddddd dddddddd ..
#define CGRAM_WR			0x20		// "
#define ADRAM_WR			0x30		// ccccaaaa ******dd ******dd ..
#define DUTY				0x50		// ccccdddd
#define NUMDIGIT			0x60		// "
#define LIGHTS				0x70		// cccc**dd

#define LINORM					0x00		// normal display
#define LIOFF					0x01		// lights OFF
#define LION					0x02		//    "   ON
    
#endif  /* VFD_H */

#ifdef  __cplusplus
}
#endif
