/*
 * File:   timer.c
 * Author: Aplus_MicroProcessor
 *
 * Created on 2019年1月5日, 上午 10:53
 */
#include "timer.h"

void init_interrupt(void) {
    TRISDbits.TRISD1 = 0;
    LATDbits.LATD1 = 0;

    RCONbits.IPEN=0x01;
    T2CON=0xFF;     // 1111 1111
    PR2=0xF4;       // 1MHz, 1:16 1:16 976/4 = 244 = 0xF4
   
    PIE1bits.TMR2IE=1;
    IPR1bits.TMR2IP=1;
    PIR1bits.TMR2IF=0;
    
    INTCONbits.GIE=1;
}

void __interrupt() tc_int(void)     // High priority interrupt
{
    if(TMR2IE && TMR2IF) {
        count++;
    }
    if(count == 2 && in == 0) { //0.5 sec
        draw_flag = 1;
        off_flag = 0;
        // Draw(brake, 0); 
        count=0;
        in = 1;
        shine = 1;
    }
    if(count == 4 && in == 1) { // 1 sec
        off_flag = 1;
        draw_flag = 0;
        // TurnOff();
        count=0;
        in = 0;
    }
    PIR1bits.TMR2IF=0;
}