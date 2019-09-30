#ifndef _DRAWLIGHT_H
#define	_DRAWLIGHT_H

#include <pic18f4520.h>
#include <xc.h> 

int count;

unsigned short brake[8] = { 0b00011000,
                            0b00100100,
                            0b00000000,
                            0b11011111,
                            0b11011111,
                            0b00000000,
                            0b00100100,
                            0b00011000};

void Stop(int);
void TurnOff();
void Draw(unsigned short *, int);

#endif	

