#include "lcd.h"
#include "inc/tm4c123gh6pm.h"



int main(void)
{

    Lcdilkayar();

    LcdGotoXY(1, 1);
    LcdYaz(80);
    LcdGotoXY(1, 2);
    LcdYaz(81);

    return 0;



}
