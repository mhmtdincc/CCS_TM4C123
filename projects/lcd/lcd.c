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
#include "lcd.h"



void Lcdilkayar(void)
{
    SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    GPIOPinTypeGPIOOutput(LCDPORT, 0xFF);
    //GPIOPinWrite(GPIO_PORTB_BASE, GPIO_INT_PIN_0|GPIO_INT_PIN_1|GPIO_INT_PIN_2|GPIO_INT_PIN_3|GPIO_INT_PIN_4|GPIO_INT_PIN_5|GPIO_INT_PIN_6|GPIO_INT_PIN_7, 0X00);

    SysCtlDelay(50000);
    GPIOPinWrite(LCDPORT, RS, 0);//RS=0
    otuzhexgonder();
    otuzhexgonder();
    otuzhexgonder();
    SysCtlDelay(50000);
    SysCtlDelay(50000);
    SysCtlDelay(50000);

    GPIOPinWrite(LCDPORT, D4 | D5 | D6 | D7,  0x20 );
            GPIOPinWrite(LCDPORT, E, 0x02);
            SysCtlDelay(200);
            GPIOPinWrite(LCDPORT, E, 0x00);
            SysCtlDelay(50000);


    SysCtlDelay(1000000);

    Lcdfonkayar(4,2,7);

    SysCtlDelay(1000000);

    LcdEkranonoff(2,1,1);
    SysCtlDelay(1000000);

    LcdKomut(0x02);
    SysCtlDelay(1000000);

    LcdGirisKipi(2, 1);
    SysCtlDelay(1000000);

    LcdKomut(0x01);
    SysCtlDelay(1000000);



}



void LcdKomut(unsigned char c) //0x1c=28 decimal=0001 1100
{
    GPIOPinWrite(LCDPORT, RS, 0);
    SysCtlDelay(50000);
    GPIOPinWrite(LCDPORT,D4|D5|D6|D7 , c); //c & 0xF0
    GPIOPinWrite(LCDPORT, E, 2);
    SysCtlDelay(50000);
    GPIOPinWrite(LCDPORT, E, 0);
    SysCtlDelay(50000);
    GPIOPinWrite(LCDPORT, RS, 0);
    GPIOPinWrite(LCDPORT,D4|D5|D6|D7 , (c<<4));//c & 0x0F
    GPIOPinWrite(LCDPORT, E, 2);
    SysCtlDelay(50000);
    GPIOPinWrite(LCDPORT, E, 0);
    SysCtlDelay(50000);
}

void LcdTemizle(void)
{
    LcdKomut(0x01);
}

void Lcdfonkayar(unsigned char DL,unsigned char N,unsigned char F)
{

if(DL==4 & N==1 & F==7)
        {

        LcdKomut(0x20);
        }else if(DL==8 & N==2 & F==10)
        {
        LcdKomut(0xc3);
        }
if(DL==8 & N==1 & F==5)
        {
        LcdKomut(0x30);
        }else if (DL==8 & N==2 & F==7)
        {
        LcdKomut(0x38);
        }
if (DL==8 & N==1 & F==10)
        {
        LcdKomut(0x34);
        }else if (DL==4 & N==1 & F==10)
        {
        LcdKomut(0x24);
        }
if (DL==4 & N==2 & F==10)
        {
        LcdKomut(0x2c);
        }else if (DL==4 & N==2 & F==7)
        {
        LcdKomut(0x28);
        }

//1-1-1       0-0-0        1-0-0      1-1-0     1-0-1    0-0-1    0-1-1    0-1-0

}

void LcdYaz(unsigned char c)
{

    SysCtlDelay(50000);
    GPIOPinWrite(LCDPORT, RS, 1);//RS=1//
    SysCtlDelay(50000);
    GPIOPinWrite(LCDPORT,D4|D5|D6|D7 , (c & 0xF0)); //c & 0xF0
    SysCtlDelay(50000);
    GPIOPinWrite(LCDPORT, E, 2);
    SysCtlDelay(200000);
    GPIOPinWrite(LCDPORT, E, 0);
    SysCtlDelay(50000);
    GPIOPinWrite(LCDPORT, RS, 1);//RS=1//
    SysCtlDelay(50000);
    GPIOPinWrite(LCDPORT,D4|D5|D6|D7 , (c & 0x0F)<<4); //c & 0x0F
    SysCtlDelay(50000);
    GPIOPinWrite(LCDPORT, E, 2);
    SysCtlDelay(200000);
    GPIOPinWrite(LCDPORT, E, 0);
    SysCtlDelay(50000);
}

void LcdGotoXY(unsigned char x,unsigned char y)
{

    if(x==1 & y==1)
    {
    LcdKomut(0x80);
    }
    SysCtlDelay(50000);
    if(x==1 & y==2)
    {
    LcdKomut(0x81);
    }
    if(x==1 & y==3)
    {
    LcdKomut(0x82);
    }
    if(x==1 & y==4)
    {
    LcdKomut(0x83);
    }
    if(x==1 & y==5)
    {
    LcdKomut(0x84);
    }
    if(x==1 & y==6)
    {
    LcdKomut(0x85);
    }
    if(x==1 & y==7)
    {
    LcdKomut(0x86);
    }
    if(x==1 & y==8)
    {
    LcdKomut(0x87);
    }
    if(x==1 & y==9)
    {
    LcdKomut(0x88);
    }
    if(x==1 & y==10)
    {
    LcdKomut(0x89);
    }
    if(x==1 & y==11)
    {
    LcdKomut(0x8A);
    }
    if(x==1 & y==12)
    {
    LcdKomut(0x8B);
    }
    if(x==1 & y==13)
    {
    LcdKomut(0x8C);
    }
    if(x==1 & y==14)
    {
    LcdKomut(0x8D);
    }
    if(x==1 & y==15)
    {
    LcdKomut(0x8E);
    }
    if(x==1 & y==16)
    {
    LcdKomut(0x8F);
    }
    if(x==2 & y==1)
    {
    LcdKomut(0xC0);
    }
    if(x==2 & y==2)
    {
    LcdKomut(0xC1);
    }
    if(x==2 & y==3)
    {
    LcdKomut(0xC2);
    }
    if(x==2 & y==4)
    {
    LcdKomut(0xC3);
    }
    if(x==2 & y==5)
    {
    LcdKomut(0xC4);
    }
    if(x==2 & y==6)
    {
    LcdKomut(0xC5);
    }
    if(x==2 & y==7)
    {
    LcdKomut(0xC6);
    }
    if(x==2 & y==8)
    {
    LcdKomut(0xC7);
    }
    if(x==2 & y==9)
    {
    LcdKomut(0xC8);
    }
    if(x==2 & y==10)
    {
    LcdKomut(0xC9);
    }
    if(x==2 & y==11)
    {
    LcdKomut(0xCA);
    }
    if(x==2 & y==12)
    {
    LcdKomut(0xCB);
    }
    if(x==2 & y==13)
    {
    LcdKomut(0xCC);
    }
    if(x==2 & y==14)
    {
    LcdKomut(0xCD);
    }
    if(x==2 & y==15)
    {
    LcdKomut(0xCE);
    }
    if(x==2 & y==16)
    {
    LcdKomut(0xCF);
    }

}

void LcdEkranonoff(unsigned char D, unsigned char C, unsigned char B)

{
    GPIOPinWrite(LCDPORT, RS, 0);
if(D==2 & C==2 & B==2)
        {

        LcdKomut(0x0F);
        }else if(D==1 & C==1 & B==1)
        {
        LcdKomut(0x08);
        }
if(D==2 & C==1 & B==1)
        {
        LcdKomut(0x0C);
        }else if (D==2 & C==2 & B==1)
        {
        LcdKomut(0x0E);
        }
if (D==2 & C==1 & B==2)
        {
        LcdKomut(0x0D);
        }else if (D==1 & C==1 & B==2)
        {
        LcdKomut(0x09);
        }
if (D==1 & C==2 & B==2)
        {
        LcdKomut(0x0B);
        }else if (D==1 & C==2 & B==1)
        {
        LcdKomut(0x0A);
        }


}

void LcdGirisKipi(unsigned char D2,unsigned char S)

{
    GPIOPinWrite(LCDPORT, RS, 0);
if(D2==2 & S==2)
        {
        LcdKomut(0x07);
        }else if(D2==1 & S==1)
        {
        LcdKomut(0x04);
        }
if(D2==2 & S==1)
        {
        LcdKomut(0x06);
        }else if (D2==1 & S==2)
        {
        LcdKomut(0x05);
        }
}
void otuzhexgonder()
{
SysCtlDelay(50000);
GPIOPinWrite(LCDPORT, RS, 0);//RS=0
GPIOPinWrite(LCDPORT,D4|D5|D6|D7 , 0x30);
GPIOPinWrite(LCDPORT, E, 2);
SysCtlDelay(5000);
GPIOPinWrite(LCDPORT, E, 0);

}



