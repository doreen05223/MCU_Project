#include <xc.h>
#include "sound.h"

void delay_ms(unsigned int milliseconds) {
   while(milliseconds > 0) {
      milliseconds--;
       __delay_us(990);
   }
}

void PWM1_Init(long desired_frequency) {
    /*  
        PWM period = (PR2+1)*4*Tosc*prescaler
        PR2 = PWM period/4/Tosc/prescaler - 1
        PR2 = (1/PWM freq)/4/(1/Fosc)/prescaler - 1
        PR2 = Fosc/PWM freq/4/prescaler - 1
        PR2 = Fosc/(PWM freq * 4 * prescaler) - 1   
     */
    PR2 = (_XTAL_FREQ / (desired_frequency * 4 * TMR2PRESCALE)) - 1;
    current_tone = desired_frequency;
}

int PWM_Max_Duty() {
    /*
        duty cycle = [CCPRxL:CCPxCON] * Tosc * prescaler
        duty cycle = [CCPRxL:CCPxCON] * (1/Fosc) * prescaler
        [CCPRxL:CCPxCON] = duty cycle/(1/Fosc)/prescaler
        [CCPRxL:CCPxCON] = Fosc/(duty freq)/prescaler
        [CCPRxL:CCPxCON] = Fosc/(current tone of the note) * prescaler) --> 100% HIGH
     */
    return (_XTAL_FREQ / (current_tone * TMR2PRESCALE));
}

void PWM1_Duty(unsigned int duty) {
    if (duty < 1024) {
        duty = ((float) duty / 1023) * PWM_Max_Duty();      // 511/1023 ~= 1/2 --> set 50% LOW
        CCP1X = duty & 2;
        CCP1Y = duty & 1;
        CCPR1L = duty >> 2;
    }
}

void PWM1_Mode_On() {
    // set as PWM mode
    CCP1M3 = 1;
    CCP1M2 = 1;
}

void PWM1_Start() {
    PWM1_Mode_On();

    T2CKPS0 = 1;
    T2CKPS1 = 1;
    
    TMR2ON = 1;
}

// used to stop music
void PWM1_Stop() {
    // turn off PWM mode
    CCP1M3 = 0;
    CCP1M2 = 0;
}

void playTone() {
    if (current_tone > 0) {
        PWM1_Init(current_tone);
        PWM1_Duty(511);
        
        delay_ms(current_tone_duration);    // delay for 1 second
        PWM1_Duty(0);
    }
}