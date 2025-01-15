/*
 * lcd.c
 *
 *  Created on: 15 Oca 2025
 *      Author: din21
 */
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.c"
#include "driverlib/gpio.h"
#include "inc/hw_gpio.h"
#include "driverlib/sysctl.c"
#include "clock.h"

void LcdEnable(){
    GPIOPinWrite(LCDPORT,EN,0x02);
    Beklet(1000);
    GPIOPinWrite(LCDPORT,EN,0x00);
}
void send_common(char c) {
    GPIOPinWrite(LCDPORT,ALL_DATA,(c & 0xf0));
    GPIOPinWrite(LCDPORT,RS,0x00);
    LcdEnable();
    Beklet(50000);

    GPIOPinWrite(LCDPORT,ALL_DATA,(c & 0x0f)<<4);
    GPIOPinWrite(LCDPORT,RS,0x00);
    LcdEnable();
    Beklet(50000);
}

void write_char(char c){
    GPIOPinWrite(LCDPORT,ALL_DATA,(c & 0xf0));
    GPIOPinWrite(LCDPORT,RS,0x01);
    LcdEnable();
    Beklet(50000);

    GPIOPinWrite(LCDPORT,ALL_DATA,(c & 0x0f)<<4);
    GPIOPinWrite(LCDPORT,RS,0x01);
    LcdEnable();
    Beklet(50000);
}
void home(){
    send_common(0x02);
    Beklet(1000);
}
void Lcd_clear(void){
    send_common(0x01);
    send_common(0x02);
    Beklet(1000);
}
void LcdDisplayOn(){
    send_common(0x0c);
    Beklet(1000);
}

void LcdCursorOn(){
    send_common(0x0e);
    Beklet(1000);
}
void LcdBlinkOn(){
    send_common(0x0f);
    Beklet(1000);
}

void Gotox_y(char row, char col){
    char adress;
    if(row == 0)
        adress=0;
    else if(row==1)
        adress=0x40;
    else
        adress=0;
    adress|=col;
    send_common(0x80 | adress);
}

void Lcdwritestring(const char  dizi[], int dizisayisi){
    char i=0;
    while(dizisayisi--){
        write_char(dizi[i++]);
    }
}
void Lcd_dec(){
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    GPIOPinTypeGPIOOutput(LCDPORT, 0xFF);
    Beklet(50000);
    GPIOPinWrite(LCDPORT,RS,0x00);
    GPIOPinWrite(LCDPORT, ALL_DATA,  0x30 );
    LcdEnable();
    Beklet(50000);
    GPIOPinWrite(LCDPORT, ALL_DATA,  0x30 );
    LcdEnable();
    Beklet(50000);
    GPIOPinWrite(LCDPORT, ALL_DATA,  0x30 );
    LcdEnable();
    Beklet(50000);


    GPIOPinWrite(LCDPORT, ALL_DATA,  0x20 );
    Beklet(50000);
    GPIOPinWrite(LCDPORT, ALL_DATA,  0xF0);
    Beklet(50000);

    send_common(0x0e); //
    send_common(0x01); //
    send_common(0x06); //
    Lcd_clear();
}
