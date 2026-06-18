#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "LED.h"

int main(void)
{
    LED_Init();
    GPIO_ResetBits(GPIOF, GPIO_Pin_9);
    GPIO_ResetBits(GPIOF, GPIO_Pin_10);
}
