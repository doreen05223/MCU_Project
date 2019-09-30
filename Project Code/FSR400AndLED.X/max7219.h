#ifndef _max7219_H
#define	_max7219_H

#include <pic18f4520.h>
#include <xc.h> 

#define HIGH 1
#define LOW 0
#define TRIS_SCK LATCbits.LATC3      // DIRECTION define clock pin as output
#define TRIS_CS LATAbits.LATA5      // DIRECTION CS - RA5
#define TRIS_SDO LATCbits.LATC5      //DIRECTION SD0 as output

unsigned char max7219_REG_noop = 0x00;
unsigned char max7219_REG_digit0 = 0x01;
unsigned char max7219_REG_digit1 = 0x02;
unsigned char max7219_REG_digit2 = 0x03;
unsigned char max7219_REG_digit3 = 0x04;
unsigned char max7219_REG_digit4 = 0x05;
unsigned char max7219_REG_digit5 = 0x06;
unsigned char max7219_REG_digit6 = 0x07;
unsigned char max7219_REG_digit7 = 0x08;
unsigned char max7219_REG_decodeMode = 0x09;
unsigned char max7219_REG_intensity = 0x0a;
unsigned char max7219_REG_scanLimit = 0x0b;
unsigned char max7219_REG_shutdown = 0x0c;
unsigned char max7219_REG_displayTest = 0x0f;

void init_MAX7219(void);
void MAX7219_1Unit(unsigned char , unsigned char);

#endif

