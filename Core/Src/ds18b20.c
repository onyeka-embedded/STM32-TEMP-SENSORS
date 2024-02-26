#include "ds18b20.h"


void usDelay(uint32_t uSec);
void pinMode(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, char* mode);

uint8_t DS18B20_Start (void){
	uint8_t Response = 0;
	pinMode(DS18B20_PORT, DS18B20_PIN, OUTPUT);   // set the pin as output
	HAL_GPIO_WritePin (DS18B20_PORT, DS18B20_PIN, 0);  // pull the pin low
	usDelay (480);   // usDelay according to datasheet

	pinMode(DS18B20_PORT, DS18B20_PIN, INPUT);    // set the pin as input
	usDelay (80);    // usDelay according to datasheet

	if (!(HAL_GPIO_ReadPin (DS18B20_PORT, DS18B20_PIN))) Response = 1;    // if the pin is low i.e the presence pulse is detected
	else Response = -1;

	usDelay (400); // 480 us usDelay totally.

	return Response;
}

void DS18B20_Write (uint8_t data){
	pinMode(DS18B20_PORT, DS18B20_PIN, OUTPUT);  // set as output

	for (int i=0; i<8; i++)
	{

		if ((data & (1<<i))!=0)  // if the bit is high
		{
			// write 1

			pinMode(DS18B20_PORT, DS18B20_PIN, OUTPUT);  // set as output
			HAL_GPIO_WritePin (DS18B20_PORT, DS18B20_PIN, 0);  // pull the pin LOW
			usDelay (1);  // wait for 1 us

			pinMode(DS18B20_PORT, DS18B20_PIN, INPUT);  // set as input
			usDelay (50);  // wait for 60 us
		}

		else  // if the bit is low
		{
			// write 0

			pinMode(DS18B20_PORT, DS18B20_PIN, OUTPUT);
			HAL_GPIO_WritePin (DS18B20_PORT, DS18B20_PIN, 0);  // pull the pin LOW
			usDelay (50);  // wait for 60 us

			pinMode(DS18B20_PORT, DS18B20_PIN, INPUT);
		}
	}
}

uint8_t DS18B20_Read (void){
	uint8_t value=0;

	pinMode(DS18B20_PORT, DS18B20_PIN, INPUT);

	for (int i=0;i<8;i++)
	{
		pinMode(DS18B20_PORT, DS18B20_PIN, OUTPUT);   // set as output

		HAL_GPIO_WritePin (DS18B20_PORT, DS18B20_PIN, 0);  // pull the data pin LOW
		usDelay (1);  // wait for > 1us

		pinMode(DS18B20_PORT, DS18B20_PIN, INPUT);  // set as input
		if (HAL_GPIO_ReadPin (DS18B20_PORT, DS18B20_PIN))  // if the pin is HIGH
		{
			value |= 1<<i;  // read = 1
		}
		usDelay (50);  // wait for 60 us
	}
	return value;
}
