#include "stdint.h"
#include "stdbool.h"
#include "inc/tm4c123gh6pm.h"
#include "driverlib/gpio.h"
#include "driverlib/gpio.c"
#include "driverlib/sysctl.h"
#include "driverlib/sysctl.c"
#include "driverlib/pin_map.h"
#include "math.h"
#include "inc/hw_gpio.h"
#include "inc/hw_types.h"

// Main function
void main(void)
{
    // Set the system clock to 40 MHz
    SysCtlClockSet(
            SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ
                    | SYSCTL_OSC_MAIN); // Clock configuration (40000000) 40MHz
    SysCtlClockGet(); // Get the current system clock frequency

    // Enable the GPIO port F
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF); // Activate port F
    // Set pins 1, 2, and 3 of port F as output
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,
                          GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3); // Pins 1, 2, and 3 on port F are defined as outputs

    while (1) // Infinite loop
    {
        // Turn on the red LED (pin 1)
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 2);   // Red LED
        SysCtlDelay(13333333); // Delay for a certain period
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0); // Turn off the red LED

        /////////////////////////////////////////////
        // Turn on the blue LED (pin 2)
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 4);  // Blue LED
        SysCtlDelay(13333333); // Delay for a certain period
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0); // Turn off the blue LED

        /////////////////////////////////////////////
        // Turn on the green LED (pin 3)
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 8);   // Green LED
        SysCtlDelay(13333333); // Delay for a certain period
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0); // Turn off the green LED

        //////////////////////////////////////////////
        // Turn on all LEDs (white)
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, 14); // White
        SysCtlDelay(13333333); // Delay for a certain period
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, 0); // Turn off all LEDs
        break; // Exit the loop after one cycle
    }
}
