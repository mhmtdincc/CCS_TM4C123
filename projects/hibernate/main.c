#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/sysctl.c"
#include "driverlib/gpio.h"
#include "inc/hw_gpio.h"
#include "inc/tm4c123gh6pm.h"
#include "driverlib/hibernate.h"

int main(void)
{

    SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_HIBERNATE); // Peripheral active
    // we use an m4 with a hibernate module

    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4); //pin0 and pin4 input
    GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_STRENGTH_4MA, GPIO_PIN_TYPE_STD_WPU); // pin0 and pin4 pull-up

    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0);



    HibernateEnableExpClk(SysCtlClockGet()); // 1.function
    // wake from sleep with purpose wake-up pin
    HibernateGPIORetentionEnable();// helps maintain pin states when left in sleep mode

    HibernateRTCSet(0);//Sets the value of the real time clock (RTC) counter.
    HibernateRTCEnable();
    HibernateRTCMatchSet(0, 5); // 5 seconds when it arrives.

    // floating point 1 saatlik
    // mermory pwm
    // dac ama dac yok
    // dma

    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,2);
    SysCtlDelay(50000000);
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,0);
    HibernateWakeSet(HIBERNATE_WAKE_PIN|HIBERNATE_WAKE_RTC); // wake-up unit
    // pf0 wake-up pin

    HibernateRequest(); // put me to sleep
    while(1)
    {

    }
}
