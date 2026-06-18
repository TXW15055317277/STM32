#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
void LED_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOF, &GPIO_InitStructure);
		GPIO_SetBits(GPIOF, GPIO_Pin_9);
		GPIO_SetBits(GPIOF, GPIO_Pin_10);
}
void LED_GREEN_ON(void)
{
    GPIO_ResetBits(GPIOF, GPIO_Pin_10);
}

void LED_GREEN_OFF(void)
{
    GPIO_SetBits(GPIOF, GPIO_Pin_10);
}

void LED_RED_ON(void)
{
    GPIO_ResetBits(GPIOF, GPIO_Pin_9);
}

void LED_RED_OFF(void)
{
    GPIO_SetBits(GPIOF, GPIO_Pin_9);
}

uint8_t LED_GREEN_Status(void)
{
    return GPIO_ReadOutputDataBit(GPIOF, GPIO_Pin_10);
}

uint8_t LED_RED_Status(void)
{
    return GPIO_ReadOutputDataBit(GPIOF, GPIO_Pin_9);
}
