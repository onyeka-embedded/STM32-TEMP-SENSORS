#include "pin_mode.h"


void pinMode(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, char* mode){
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = GPIO_Pin;
	if(strcmp(mode, "OUTPUT") == 0){
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	}
	else if(strcmp(mode, "INPUT") == 0){
		GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
		GPIO_InitStruct.Pull = GPIO_PULLUP;
	}
	else{}
	//GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
}

void usDelay(uint32_t uSec){
  __HAL_TIM_SET_COUNTER(&htim4, 0);
  while (__HAL_TIM_GET_COUNTER(&htim4) < uSec);
}
