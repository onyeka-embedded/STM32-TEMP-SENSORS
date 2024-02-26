#ifndef __DHT11_H_
#define __DHT11_H_

#include <stdint.h>
#include "stm32f1xx.h"
#include "pin_mode.h"


#define DHT11_PORT GPIOB
#define DHT11_PIN GPIO_PIN_12

extern TIM_HandleTypeDef htim4;

void DHT11_Start (void);
uint8_t DHT11_Check_Response (void);
uint8_t DHT11_Read (void);
#endif