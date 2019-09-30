/*
 * File:   newmain.c
 * Author: Aplus_MicroProcessor
 *
 * Created on 2019年1月2日, 下午 10:01
 */

#include "setting.h"
#include <pic18f4520.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MODE1 0x06
#define MODE2 0x0f
float voltage;
void main()
{
    init_MAX7219();
    init_interrupt(); // open interrupt
    ADC_Initialize();
    int mode = 1;
    while(1) {
        if(draw_flag) Draw(brake, 0); 
        if(off_flag) TurnOff();
        
        //壓力感測
        int digital = ADC_Read();
        voltage = digital* ((float)5/1023); // 5v / 2^10-1  (10bits)
        mode = (voltage > 0.05) ? 1 : 0; 
        if(mode == 1) mode = (voltage > 0.3) ? 2 : 1;
        if(mode > 0) MAX7219_1Unit(max7219_REG_shutdown, 0x01);// 設定為不在關閉模式
        
        if(shine == 1) {
            shine = 0;
            if(mode == 1) {
                Stop(MODE1);
                mode = 0;
            }
            else if(mode == 2) {
                Stop(MODE2);
                mode = 0;
            }
            else if(mode == 0) {
                TurnOff();
                MAX7219_1Unit(max7219_REG_shutdown, 0x00);// 設定為不在關閉模式
            }
        }
    }
}

