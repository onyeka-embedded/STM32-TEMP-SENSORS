#ifndef __DS18B20_H_
#define __DS18B20_H_

#include <stdint.h>
#include "stm32f1xx.h"
#include "pin_mode.h"


#define DS18B20_PORT GPIOB
#define DS18B20_PIN GPIO_PIN_12

extern TIM_HandleTypeDef htim4;


uint8_t DS18B20_Start (void);
void DS18B20_Write (uint8_t data);
uint8_t DS18B20_Read (void);
#endif