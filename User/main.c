#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "LED.h"
#include "DELAY.h"
#include "KEY.h"
#include "BEEP.h"
#include "LIGHT_SENSOR.h"

int main(void)
{
    LIGHT_SENSOR_Init();
    BEEP_Init();
    LED_Init();
    LED_RED_OFF();
    LED_GREEN_OFF();
    
    while(1)
    {
        if(LIGHT_SENSOR_Status() == 1)
        {
            LED_RED_ON();
            LED_GREEN_OFF();
            BEEP_ON();
        }
        else
        {
            LED_RED_OFF();
            LED_GREEN_ON();
            BEEP_OFF();
        }
    }
}
