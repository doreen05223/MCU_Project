#include "uart.h"

/*****************************USART Initialization*******************************/
void USART_Init(long baud_rate)
{
    float temp;
    TRISC6=0;                       /*Make Tx pin as output*/
    TRISC7=1;                       /*Make Rx pin as input*/
    temp= (((float)(F_CPU)/(float)baud_rate)-1);     
    SPBRG=(int)temp;                /*baud rate=9600, SPBRG = (F_CPU /(64*9600))-1*/
    TXSTA=0x20;                     /*Transmit Enable(TX) enable*/ 
    RCSTA=0x90;                     /*Receive Enable(RX) enable and serial port enable */
    
    PIR1bits.TXIF = 1;
    PIR1bits.RCIF = 0;              //setting TX/RX interrupt
    PIE1bits.TXIE = 0;              //disable Tx interrupt
    IPR1bits.TXIP = 0;              //Setting Tx as low priority interrupt
    PIE1bits.RCIE = 1;              //Enable Rx interrupt
    IPR1bits.RCIP = 0;              //Setting Rc as low priority interrupt
}

/*******************RECEIVE FUNCTION*****************************************/
char USART_ReceiveChar()
{
    return(ControlLight);                  /*receive data is stored in RCREG register and return to main program */
}

char USART_ReceiveChar_RCREG()
{
    return(RCREG);                  /*receive data is stored in RCREG register and return to main program */
}

void __interrupt(low_priority)  Lo_ISR(void)
{
    if(RCIF)
    {
        if(RCSTAbits.OERR)
        {
            CREN = 0;
            Nop();
            CREN = 1;
        }
        
       if(RCREG == 'o')       // turn off any light
       {
            ControlLight = 'o';
            // turn off dot matrix display
            left_flag=false;
            right_flag=false;
            PWM1_Stop();    //close music
       }
       if(RCREG == 'l')       // turn off left light
       {
           ControlLight = 'l';
           right_flag=false;
           PWM1_Stop();    //close music
       }
        else if(RCREG == 'r')       // turn off right light
       {
            ControlLight = 'r';
            left_flag=false;
            PWM1_Stop();    //close music
        }
        
        return;
    }
}