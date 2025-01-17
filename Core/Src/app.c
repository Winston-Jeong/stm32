/*
 * app.c
 *
 *  Created on: Jan 16, 2025
 *      Author: user
 */

#include "app.h"
#include <math.h>

// 장치 선언
extern TIM_HandleTypeDef htim1;

//timer1의 duty 변경
void setDuty(uint8_t r, uint8_t g, uint8_t b)
{
	htim1.Instance->CCR1 = r * 10;
	htim1.Instance->CCR2 = g * 10;
	htim1.Instance->CCR3 = b * 10;
}

void app()
{
	// 타이머 장치 시작
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
	while(1)
	{
		static int angle = 0;
		angle++;
		angle %= 360;
		uint8_t valuesin = sin(angle * M_PI / 180) * 50 + 49;
		setDuty(valuesin, valuesin, valuesin);
		HAL_Delay(10);
	}
}
