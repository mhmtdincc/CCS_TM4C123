/*
 * lcd.h
 *
 *  Created on: 15 Oca 2025
 *      Author: din21
 */

#ifndef LCD_H_
#define LCD_H_

#define LCDPORT                       GPIO_PORTB_BASE
#define RS                            GPIO_PIN_0//PB0
#define E                             GPIO_PIN_1//PB1
#define D4                            GPIO_PIN_4//PB4=D4
#define D5                            GPIO_PIN_5//PB5=D5
#define D6                            GPIO_PIN_6//PB6=D6
#define D7                            GPIO_PIN_7//PB7=D7

void LcdTemizle(void);
void LcdKomut(unsigned char);
void LcdYaz(unsigned char);
void LcdGotoXY(unsigned char,unsigned char);
void Lcdfonkayar(unsigned char,unsigned char,unsigned char);//D1,N,F
// D1=0 1
// N= 0 1 //IF ELSE IF YAPISI
// F= 0 1
void Lcdilkayar(void);
void otuzhexgonder(void);
void LcdEkranonoff(unsigned char,unsigned char,unsigned char);
void LcdGirisKipi(unsigned char,unsigned char);





#endif /* LCD_H_ */
