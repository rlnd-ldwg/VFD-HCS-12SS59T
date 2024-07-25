/*
 * vfd v0.2.0
 *
 * header file: vfd interface
 *
 * (c) July 2024 by Roland Ludwig
 * 
 * 2024/07/20 ???
 *
 */

#ifdef  __cplusplus
extern "C" {
#endif
    
#ifndef VFD_H
#define VFD_H

// VFD Definitions
#define VFD_DDR     DDRB
#define VFD_PORT    PORTB
#define VFD_RESET   PORTB0
#define LED         PORTB1
    
#define DCRAM_WR    0x10        // ccccaaaa dddddddd dddddddd ..
#define CGRAM_WR    0x20        // "
#define ADRAM_WR    0x30        // ccccaaaa ******dd ******dd ..
#define DUTY        0x50        // ccccdddd
#define NUMDIGIT    0x60        // "
#define LIGHTS      0x70        // cccc**dd

#define LINORM      0x00        // normal display
#define LIOFF       0x01        // lights OFF
#define LION        0x02        //    "   ON
    
void VFD_Init();
void VFD_Display(uint8_t* text);
    
#endif  /* VFD_H */

#ifdef  __cplusplus
}
#endif

