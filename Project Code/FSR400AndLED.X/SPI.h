#ifndef _SPI_H
#define	_SPI_H

#include <pic18f4520.h>
#include <xc.h>

signed char WriteSPI( unsigned char data_out );
unsigned char ReadSPI( void );

#endif

