#include "dht22.h"


void DHT22_Start (void){
	pinMode(DHT22_GPIO_Port, DHT22_Pin, OUTPUT); // set the pin as output
	HAL_GPIO_WritePin (DHT22_GPIO_Port, DHT22_Pin, 0);   // pull the pin low
	usDelay(1200);   // wait for > 1ms

	HAL_GPIO_WritePin (DHT22_GPIO_Port, DHT22_Pin, 1);   // pull the pin high
	usDelay (20);   // wait for 30us

	pinMode(DHT22_GPIO_Port, DHT22_Pin, INPUT);   // set as input
}

uint8_t DHT22_Check_Response (void){
	pinMode(DHT22_GPIO_Port, DHT22_Pin, INPUT);   // set as input
	uint8_t Response = 0;
	usDelay (40);  // wait for 40us
	if (!(HAL_GPIO_ReadPin (DHT22_GPIO_Port, DHT22_Pin))) { // if the pin is low
		usDelay (80);   // wait for 80us
		if ((HAL_GPIO_ReadPin (DHT22_GPIO_Port, DHT22_Pin))) Response = 1;  // if the pin is high, response is ok
		else Response = -1;
	}

	while ((HAL_GPIO_ReadPin (DHT22_GPIO_Port, DHT22_Pin)));   // wait for the pin to go low
	return Response;
}

uint8_t DHT22_Read (void){
	uint8_t i,j;
	for (j=0;j<8;j++)
	{
		while (!(HAL_GPIO_ReadPin (DHT22_GPIO_Port, DHT22_Pin)));   // wait for the pin to go high
		usDelay (40);   // wait for 40 us

		if (!(HAL_GPIO_ReadPin (DHT22_GPIO_Port, DHT22_Pin)))   // if the pin is low
		{
			i&= ~(1<<(7-j));   // write 0
		}
		else i|= (1<<(7-j));  // if the pin is high, write 1
		while ((HAL_GPIO_ReadPin (DHT22_GPIO_Port, DHT22_Pin)));  // wait for the pin to go low
	}

	return i;
}
