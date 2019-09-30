#ifndef HC_05_H
#define	HC_05_H
    
#include <pic18f4520.h>
#include "configure.h"
#include "uart.h"
#include "sound.h"
#define _XTAL_FREQ  4000000
    
void HC_05_Init();
void receiveMsg();

#endif

