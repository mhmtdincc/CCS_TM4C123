#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_ints.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/rom_map.h"
#include "driverlib/timer.h"
#include "driverlib/interrupt.h"
#include "clock.h"

int second=30,min=57,hour=1;

void LcdClockWrite(int second,int min,int hour){
    int secondlow=second%10;
    int secondhigh=second/10;
    int minlow=min%10;
    int minhigh=min/10;
    int hourlow=hour%10;
    int hourhigh=hour/10;
    Lcd_clear();
    Gotox_y(0,0);

    Lcdwritestring("SAAT", 4);
    Gotox_y(0,7);
    write_char(48+hourhigh);
    Gotox_y(0,8);
    write_char(48+hourlow);
    Gotox_y(0,9);
    write_char(':');
    Gotox_y(0,10);
    write_char(48+minhigh);
    Gotox_y(0,11);
    write_char(48+minlow);
    Gotox_y(0,12);
    write_char(':');
    Gotox_y(0,13);
    write_char(secondhigh+48);
    Gotox_y(0,14);
    write_char(secondlow+48);
}
void TimeIntFunc(){
    TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
    second++;
    if(second==60){
        second=0;
        min++;
        if(min==60){
            min=0;
            hour++;
            if(hour==24)
                hour=0;
        }
    }
    LcdClockWrite(second, min, hour);
}
void InitSettings(){
    SysCtlClockSet(SYSCTL_OSC_MAIN|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_SYSDIV_5);
    Lcd_dec();
    LcdDisplayOn();
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
    TimerConfigure(TIMER0_BASE, TIMER_CFG_A_PERIODIC);
    TimerLoadSet(TIMER0_BASE, TIMER_A, SysCtlClockGet()); //1 sn ayarlandi
    // kesme ayar
    //2 GLOBAL
    IntMasterEnable();
    IntEnable(INT_TIMER0A);
    //3 LOCAL
    TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
    TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
    TimerIntRegister(TIMER0_BASE, TIMER_A, TimeIntFunc);

}
void main(void)
    {
    InitSettings(); // Sistem ayarlarýný baþlat
    LcdClockWrite(second, min, hour); // LCD'ye saati yaz
    TimerEnable(TIMER0_BASE, TIMER_A); // Timer'ý baþlat
    while(1); // Sonsuz döngü
}
