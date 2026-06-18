#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "LED.h"
#include "DELAY.h"
#include "KEY.h"

int8_t KEY_Num;
int main(void)
{
    LED_Init();
    KEY_Init();
    LED_RED_OFF();
    LED_GREEN_OFF();
    while(1)
    {
        KEY_Num = KEY_Scan();
        if (KEY_Num == 0)
        {
            LED_RED_OFF();
            LED_GREEN_ON();
        }
        if (KEY_Num == 1)
        {
            LED_RED_ON();
            LED_GREEN_OFF();
        }
        if (KEY_Num == 2)
        {
            uint8_t LED_Status = LED_GREEN_Status();
            if (LED_Status == 0)
            {
                LED_RED_ON();
                LED_GREEN_OFF();
            }
            else
            {
                LED_RED_OFF();
                LED_GREEN_ON();
            }
        }
        if (KEY_Num == 3)
        {
            LED_RED_ON();
            LED_GREEN_ON();
        }
    }
}
