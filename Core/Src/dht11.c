#include "dht11.h"


void DHT11_Start (void){
	pinMode (DHT11_PORT, DHT11_PIN, OUTPUT);  // set the pin as output
	HAL_GPIO_WritePin (DHT11_PORT, DHT11_PIN, 0);   // pull the pin low
	usDelay (18000);   // wait for 18ms
    HAL_GPIO_WritePin (DHT11_PORT, DHT11_PIN, 1);   // pull the pin high
	usDelay (20);   // wait for 20us
	pinMode(DHT11_PORT, DHT11_PIN, INPUT);    // set as input
}

uint8_t DHT11_Check_Response (void){
	uint8_t Response = 0;
	usDelay (40);
	if (!(HAL_GPIO_ReadPin (DHT11_PORT, DHT11_PIN)))
	{
		usDelay (80);
		if ((HAL_GPIO_ReadPin (DHT11_PORT, DHT11_PIN))) Response = 1;
		else Response = -1; // 255
	}
	while ((HAL_GPIO_ReadPin (DHT11_PORT, DHT11_PIN)));   // wait for the pin to go low

	return Response;
}

uint8_t DHT11_Read (void){
	uint8_t i,j;
	for (j=0;j<8;j++)
	{
		while (!(HAL_GPIO_ReadPin (DHT11_PORT, DHT11_PIN)));   // wait for the pin to go high
		usDelay (40);   // wait for 40 us
		if (!(HAL_GPIO_ReadPin (DHT11_PORT, DHT11_PIN)))   // if the pin is low
		{
			i&= ~(1<<(7-j));   // write 0
		}
		else i|= (1<<(7-j));  // if the pin is high, write 1
		while ((HAL_GPIO_ReadPin (DHT11_PORT, DHT11_PIN)));  // wait for the pin to go low
	}
	return i;
}

