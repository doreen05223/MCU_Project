#include <pic18f4520.h>
#include "uart.h"
#include "sound.h"
#include "dot_matrix.h"
#include "main.h"
//#define _XTAL_FREQ  4000000             
// set buzzer pin as RC2
/* use USART_ReceiveChar(); to get the data from the cellphone */


void HC_05_Init() {
    OSCCON=0x72;              /* use internal oscillator frequency and set to 8 MHz */
    USART_Init(9600);         /* initialize USART operation with 9600 baud rate */ 
}

void receiveMsg() {
    char data_in;
    data_in=USART_ReceiveChar();
        
    if(data_in == 'l')            // turn on left light
    {   
       // left pattern dot matrix display
       right_flag = false;
       left_flag=true;
       TurnLeft();
    }
    else if(data_in == 'r')       // turn on right light
    {
       // right pattern dot matrix display
       left_flag = false;
       right_flag=true;
       TurnRight();
    }
    else if(data_in == 'o')       // turn off any light
    {
       // turn off dot matrix display
       left_flag=false;
       right_flag=false;
       Close();
    }
}