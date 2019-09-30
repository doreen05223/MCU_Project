#ifndef _NEWMAIN_H
#define	_NEWMAIN_H

#include "main.h"

#define HIGH 1
#define LOW 0
#define CS        LATAbits.LATA5
#define DATA_bit  LATCbits.LATC5
#define SERCLK    LATCbits.LATC3
#define _XTAL_FREQ 4000000


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

unsigned short RightLight[72]={ 0b11000011,
                              0b01100110,
                              0b00111100,
                              0b10011001,
                              0b11000011,
                              0b01100110,
                              0b00111100,
                              0b00011000, //1
                              0b10000001,
                              0b11000011,
                              0b01100110,
                              0b00111100,
                              0b10011001,
                              0b11000011,
                              0b01100110,
                              0b00111100,//2
                              0b00011000,
                              0b10000001,
                              0b11000011,
                              0b01100110,
                              0b00111100,
                              0b10011001,
                              0b11000011,
                              0b01100110,//3
                              0b00111100,
                              0b00011000,
                              0b10000001,
                              0b11000011,
                              0b01100110,
                              0b00111100,
                              0b10011001,
                              0b11000011,//4
                              0b01100110,
                              0b00111100,
                              0b00011000,
                              0b10000001,
                              0b11000011,
                              0b01100110,
                              0b00111100,
                              0b10011001,//5
                              0b11000011,
                              0b01100110,
                              0b00111100,
                              0b00011000,
                              0b10000001,
                              0b11000011,
                              0b01100110,
                              0b00111100,//6
                              0b10011001,
                              0b11000011,
                              0b01100110,
                              0b00111100,
                              0b00011000,
                              0b10000001,
                              0b11000011,
                              0b01100110,//7
                              0b00111100,
                              0b10011001,
                              0b11000011,
                              0b01100110,
                              0b00111100,
                              0b00011000,
                              0b10000001,
                              0b11000011,//8
                              0b01100110,
                              0b00111100,
                              0b10011001,
                              0b11000011,
                              0b01100110,
                              0b00111100,
                              0b00011000,
                              0b10000001};//9

unsigned short LeftLight[72]={0b00011000, 
                              0b00111100,
                              0b01100110,
                              0b11000011,
                              0b10011001,
                              0b00111100,
                              0b01100110,
                              0b11000011,//1
                              0b00111100,
                              0b01100110,
                              0b11000011,
                              0b10011001,
                              0b00111100,
                              0b01100110,
                              0b11000011,
                              0b10000001,//2
                              0b01100110,
                              0b11000011,
                              0b10011001,
                              0b00111100,
                              0b01100110,
                              0b11000011,
                              0b10000001,
                              0b00011000,//3
                              0b11000011,
                              0b10011001,
                              0b00111100,
                              0b01100110,
                              0b11000011,
                              0b10000001,
                              0b00011000,
                              0b00111100,//4
                              0b10011001,
                              0b00111100,
                              0b01100110,
                              0b11000011,
                              0b10000001,
                              0b00011000,
                              0b00111100,
                              0b01100110,//5
                              0b00111100,
                              0b01100110,
                              0b11000011,
                              0b10000001,
                              0b00011000,
                              0b00111100,
                              0b01100110,
                              0b11000011,//6
                              0b01100110,
                              0b11000011,
                              0b10000001,
                              0b00011000,
                              0b00111100,
                              0b01100110,
                              0b11000011,
                              0b10011001,//7
                              0b11000011,
                              0b10000001,
                              0b00011000,
                              0b00111100,
                              0b01100110,
                              0b11000011,
                              0b10011001,
                              0b00111100,//8
                              0b10000001,
                              0b00011000,
                              0b00111100,
                              0b01100110,
                              0b11000011,
                              0b10011001,
                              0b00111100,
                              0b01100110};


void init_MAX7219(void);
void Draw(unsigned short *, int);
void TurnRight(void);
void TurnLeft(void);
void Close(void);
void MAX7219_1Unit(unsigned char , unsigned char);
void SPI_SendByte(unsigned char);
void External_Interrupt_Init();

#endif
