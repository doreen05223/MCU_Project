/*
 * File:   DrawLight.c
 * Author: Aplus_MicroProcessor
 *
 * Created on 2019年1月5日, 上午 11:56
 */


#include "DrawLight.h"
#include "timer.h"
#include "max7219.h"

void Stop(int mode) {
    MAX7219_1Unit(max7219_REG_intensity, mode);// 設定亮度範圍
}

void TurnOff() {
    for(int i=1; i<=8; i++) {// 把所有 LED 矩陣變暗
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