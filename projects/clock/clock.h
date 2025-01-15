/*
 * lcd.h
 *
 *  Created on: 15 Oca 2025
 *      Author: din21
 */

#ifndef CLOCK_H_
#define CLOCK_H_

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/rom_map.h"

#define LCDPORT                          GPIO_PORTB_BASE
#define RS                               GPIO_PIN_0
#define EN                               GPIO_PIN_1
#define ALL_CONTROL                      RS|EN
#define D4                               GPIO_PIN_4
#define D5                               GPIO_PIN_5
#define D6                               GPIO_PIN_6
#define D7                               GPIO_PIN_7
#define ALL_DATA                         D4|D5|D6|D7
#define Beklet(t)                        SysCtlDelay(t);

void LcdEnable();
void Lcd_dec();
void send_common(char c) ;
void write_char(char c) ;
void Gotox_y(char row, char col);
void Lcd_clear(void);
void LcdDisplayOn();
void Lcdwritestring(const char  dizi[], int dizisayisi);
void LcdBlinkOn();
void LcdCursorOn();
void home();
#endif /* CLOCK_H_ */
