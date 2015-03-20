#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "led.h"

//定时器2中断函数
void TIM2_IRQHandler(void)
{
    if(TIM2->SR & TIM_SR_UIF)
        GPIOD->ODR ^=(1 << 13);
    TIM2->SR = 0x0;
}

void ClockInit(void)
{
}

void Delay(__IO uint32_t nCount)
{
	while(nCount--) 
	{
	}
}

int main(void)
{

	ledInit();
	while (1)
	{
		/* PD12 to be toggled */
		GPIO_SetBits(GPIOD, GPIO_Pin_12);

		/* Insert delay */
		Delay(0x3FFFFF);

		/* PD13 to be toggled */
		GPIO_SetBits(GPIOD, GPIO_Pin_13);

		/* Insert delay */
		Delay(0x3FFFFF);

		/* PD14 to be toggled */
		GPIO_SetBits(GPIOD, GPIO_Pin_14);

		/* Insert delay */
		Delay(0x3FFFFF);

		/* PD15 to be toggled */
		GPIO_SetBits(GPIOD, GPIO_Pin_15);

		/* Insert delay */
		Delay(0x7FFFFF);

		GPIO_ResetBits(GPIOD, GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);

		/* Insert delay */
		Delay(0xFFFFFF);
	}
}
