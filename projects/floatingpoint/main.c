#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"
#include "inc/tm4c123gh6pm.h"
#include "driverlib/pin_map.h"
#include "utils/uartstdio.h"


void ConfigureUART(void) {

    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);


    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    UARTClockSourceSet(UART0_BASE, UART_CLOCK_PIOSC);

    UARTStdioConfig(0, 115200, 16000000);
}
void GetUserInput(float *num1, float *num2, char *operation) {
    UARTprintf("Birinci sayiyi girin: ");
    *num1 = UARTgetc();
    UARTprintf("Ikinci sayiyi girin: ");
    *num2 = UARTgetc();

    UARTprintf("Islem türünü secin (+, -, *, /): ");
    *operation = UARTgetc();
}
void PerformOperation(float num1, float num2, char operation) {
    float result;

    switch (operation) {
        case '+':
            result = num1 + num2;
            UARTprintf("Sonuç: %.2f + %.2f = %.2f\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            UARTprintf("Sonuç: %.2f - %.2f = %.2f\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            UARTprintf("Sonuç: %.2f * %.2f = %.2f\n", num1, num2, result);
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                UARTprintf("Sonuç: %.2f / %.2f = %.2f\n", num1, num2, result);
            } else {
                UARTprintf("Hata: Sýfýra bölme hatasý!\n");
            }
            break;
        default:
            UARTprintf("Geçersiz iþlem türü!\n");
            break;
    }
}

int main(void) {

    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

    ConfigureUART();

    float num1, num2;
    char operation;

    while (1) {
        GetUserInput(&num1, &num2, &operation);
        PerformOperation(num1, num2, operation);
    }
}
