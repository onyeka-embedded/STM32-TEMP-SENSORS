#ifndef __PIN_MODE_H_
#define __PIN_MODE_H_

#include <stdint.h>
#include "stm32f1xx.h"
#include <stdio.h>
#include <string.h>


#define OUTPUT 	"OUTPUT"
#define INPUT		"INPUT"

extern TIM_HandleTypeDef htim4;

void pinMode(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, char* mode);
void usDelay(uint32_t uSec);
#endif