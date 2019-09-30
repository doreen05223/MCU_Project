/*
 * File:   max7219.c
 * Author: Aplus_MicroProcessor
 *
 * Created on 2019年1月5日, 下午 12:04
 */

#include "max7219.h"
#include "SPI.h"
#include "DrawLight.h"

void MAX7219_1Unit(unsigned char reg_addr, unsigned char reg_data) {// 控制單一個 MAX7219 模組
    TRIS_CS = LOW;// 傳送前 LOAD 腳要先變成LOW
    WriteSPI(reg_addr);// 先送出要設定的暫存器位址
    WriteSPI(reg_data);// 接著送出資料
    TRIS_CS = HIGH;// 傳送完 LOAD 腳要變成 HIGH
}

void init_MAX7219(void)   {
    SSPSTAT = 0b01000000;
    SSPCON1 = 0b00110000;
    // disables converters A/D		
	ADCON1=0x0F; 
    
    TRISAbits.RA5 = 0; // CS pin as output
    TRISCbits.RC3 = 0; // clock pin as output
    TRISCbits.RC5 = 0; // SD0 pin as output
    //TRISCbits.RC4 = 1; // SDI pin as input
   
    // clock 設成 high
    TRIS_SCK = 1;	
    
    // 初始化 MAX7219 的暫存器
    MAX7219_1Unit(max7219_REG_scanLimit, 0x07);// 設定為掃描所有行
    MAX7219_1Unit(max7219_REG_decodeMode, 0x00);// 不使用解碼模式
    MAX7219_1Unit(max7219_REG_shutdown, 0x01);// 設定為不在關閉模式
    MAX7219_1Unit(max7219_REG_displayTest, 0x00); // 設定為不在測試模式
    TurnOff();
    MAX7219_1Unit(max7219_REG_intensity, 0x01);// 設定亮度範圍，0x00 ~ 0x0f
} 