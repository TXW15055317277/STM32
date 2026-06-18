#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "DELAY.h"

void KEY_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOE, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

int8_t KEY_Scan(void)
{
    int8_t KEY= -1;
    if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4) == 0)
    {
        delay_ms(20);
        if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4) == 0)
        {
            while (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4) == 0);
            delay_ms(20);
            KEY = 0;
        }
    }
    if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3) == 0)
    {
        delay_ms(20);
        if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3) == 0)
        {
            while (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3) == 0);
            delay_ms(20);
            KEY = 1;
        }
    }
    if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_2) == 0)
    {
        delay_ms(20);
        if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_2) == 0)
        {
            while (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_2) == 0);
            delay_ms(20);
            KEY = 2;
        }
    }
    if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 1)
    {
        delay_ms(20);
        if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 1)
        {
            while (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 1);
            delay_ms(20);
            KEY = 3;
        }
    }
    return KEY;
}
