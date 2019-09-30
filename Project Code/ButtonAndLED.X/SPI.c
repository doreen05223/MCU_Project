#include "SPI.h"

signed char WriteSPI( unsigned char data_out )
{
    unsigned char TempVar;
    TempVar = SSPBUF;           // Clears BF
    PIR1bits.SSPIF = 0;         // Clear interrupt flag
    SSPCON1bits.WCOL = 0;            //Clear any previous write collision
    SSPBUF = data_out;           // write byte to SSPBUF register
    if ( SSPCON1 & 0x80 )        // test if write collision occurred
        return ( -1 );              // if WCOL bit is set return negative #
    else
        while( !PIR1bits.SSPIF );  // wait until bus cycle complete
    return ( 0 );                // if WCOL bit is not set return non-negative#
}