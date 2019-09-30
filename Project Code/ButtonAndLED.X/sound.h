#ifndef SOUND_H
#define	SOUND_H

#define _XTAL_FREQ  4000000
#define TMR2PRESCALE    16

#define C4 262
#define D4 294
#define E4 330
#define F4 350
#define G4 392
#define A4 440
#define B4 494
#define C5 523
#define D5 587
#define E5 659
#define F5 698
#define G5 784

int per_arrp[48] = { C4, C4, G4, G4, A4, A4, G4, G4,
                    F4, F4, E4, E4, D4, D4, C4, C4,
                    G4, G4, F4, F4, E4, E4, D4, D4,
                    G4, G4, F4, F4, E4, E4, D4, D4,
                    C4, C4, G4, G4, A4, A4, G4, G4,
                    F4, F4, E4, E4, D4, D4, C4, C4};
int wait[2] = {1};

char str[10];
int i=0;
int interval = 0;
int tempo = 1000;

int current_tone = 0; //current playing note
int current_tone_duration = 0; //current note duration

void delay_ms(unsigned int milliseconds);
void PWM1_Init(long desired_frequency);
int PWM_Max_Duty();
void PWM1_Duty(unsigned int duty);
void PWM1_Mode_On();
void PWM1_Start();
void PWM1_Stop();
void playTone();

#endif	/* SOUND_H */

