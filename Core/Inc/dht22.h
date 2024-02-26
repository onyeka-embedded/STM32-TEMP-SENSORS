#ifndef __DHT22_H_
#define __DHT22_H_

#include <stdint.h>
#include "stm32f1xx.h"
#include "pin_mode.h"


#define DHT22_GPIO_Port GPIOB
#define DHT22_Pin GPIO_PIN_12


extern TIM_HandleTypeDef htim4;

void DHT22_Start (void);
uint8_t DHT22_Check_Response (void);
uint8_t DHT22_Read (void);
#endif