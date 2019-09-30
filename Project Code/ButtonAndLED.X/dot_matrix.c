#include "dot_matrix.h"

void MAX7219_1Unit(unsigned char reg_addr, unsigned char reg_data) {
    CS = LOW;
    WriteSPI(reg_addr);
    WriteSPI(reg_data);
    CS = HIGH;
}

void TurnRight() {
    int i = 0;
    
    TRISCbits.TRISC2 = 0; //set Pin C2 as output
    char MELODY_LENGTH = sizeof (per_arrp) / sizeof (per_arrp[0]);
    PWM1_Init(500); //exact value doesn't matter at all, just not 0
    PWM1_Duty(0);
    PWM1_Start();
    
    while(1) {
        for (int j = 0; j < MELODY_LENGTH; j++) {
           if(i == 72) i=0;         // restart the flashing
           Draw(RightLight, i); 
           if(!right_flag){
               return;
           }
           i = i + 8;
           
           current_tone = per_arrp[j];
           current_tone_duration = tempo / wait[0];
           // tempo == 1000, wait[0] == 1
           playTone();
       }
    }
}

void TurnLeft() {
    int i = 0;
    
    TRISCbits.TRISC2 = 0; //set Pin C2 as output
    char MELODY_LENGTH = sizeof (per_arrp) / sizeof (per_arrp[0]);
    PWM1_Init(500); //exact value doesn't matter at all, just not 0
    PWM1_Duty(0);
    PWM1_Start();
    
    while(1) {
       for (int j = 0; j < MELODY_LENGTH; j++) {
           if(i == 72) i=0;
            Draw(LeftLight, i);
            if(!left_flag){
                return;
            }
            i = i + 8;
            current_tone = per_arrp[j];
            current_tone_duration = tempo / wait[0];
            playTone();
       }
    }
}

void Close() {
    PWM1_Stop();    //close music
    for(int i=1; i<=8; i++) {
        MAX7219_1Unit(i,0);
    }
}

void Draw(unsigned short *A, int i) {
    MAX7219_1Unit(1,A[i++]);
    MAX7219_1Unit(2,A[i++]);
    MAX7219_1Unit(3,A[i++]);
    MAX7219_1Unit(4,A[i++]);
    MAX7219_1Unit(5,A[i++]);
    MAX7219_1Unit(6,A[i++]);
    MAX7219_1Unit(7,A[i++]);
    MAX7219_1Unit(8,A[i++]);
}

void init_MAX7219(void)   {
    SSPSTAT = 0b01000000;
    SSPCON1 = 0b00110000;
    // disables converters A/D		
	ADCON1=0x0F; 
    
    TRISAbits.RA5 = 0;
    TRISCbits.RC3 = 0;
    TRISCbits.RC4 = 1;
    TRISCbits.RC5 = 0;

    SERCLK = 1;	

    MAX7219_1Unit(max7219_REG_scanLimit, 0x07);
    MAX7219_1Unit(max7219_REG_decodeMode, 0x00);
    MAX7219_1Unit(max7219_REG_shutdown, 0x01);
    MAX7219_1Unit(max7219_REG_displayTest, 0x00);
    
    for(int i=1; i<=8; i++) {
        MAX7219_1Unit(i,0);
    }
    MAX7219_1Unit(max7219_REG_intensity, 0x01);
    __delay_ms(10);
} 


void External_Interrupt_Init()
{
    TRISBbits.TRISB0=1;		/* Make INT0 pin as an input pin*/
    TRISBbits.TRISB1=1;

    /* Also make PBADEN off in Configuration file or
    clear ADON in ADCON0 so as to set analog pin as digital*/
  
    INTCON2=0x00;		/* Set Interrupt on falling Edge*/
    INTCON3bits.INT1IF=0;	/* Clear INT0IF flag*/
    INTCON3bits.INT1IE=1;
    INTCON3bits.INT1IP=1;
    INTCON3bits.INT2IF=0;	/* Clear INT0IF flag*/
    INTCON3bits.INT2IE=1;
    INTCON3bits.INT2IP=1;
    INTCONbits.GIEH=1;		/* Enable Global Interrupt*/
    INTCONbits.GIEL=1;
    RCONbits.IPEN=1;
}

//  right light interrupt
void __interrupt(high_priority) _INTInterrupt(void)
{
    if(INTCON3bits.INT2IF == 1){
        left_flag = ~left_flag;
        if(left_flag) ControlLight = 'l';
        else ControlLight = 'o';
        right_flag = false;
        INTCON3bits.INT2IF=0;
        return;
    }
    
    if(INTCON3bits.INT1IF == 1) {
        right_flag = ~right_flag;
        if(right_flag) ControlLight = 'r';
        else ControlLight = 'o';
        left_flag = false;
        INTCON3bits.INT1IF=0;
        return;
    }
}