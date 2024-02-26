#ifndef __7SEGMENT_H_
#define __7SEGMENT_H_

#include <stdint.h>
#include "stm32f1xx.h"

#define PAGE_CTRL 		GPIOB
#define DATA_PAGE 		GPIOA

#define PAGE4_Pin GPIO_PIN_0
#define PAGE3_Pin GPIO_PIN_1
#define PAGE2_Pin GPIO_PIN_10
#define PAGE1_Pin GPIO_PIN_11

#define B_Pin GPIO_PIN_1
#define F_Pin GPIO_PIN_2
#define A_Pin GPIO_PIN_3
#define E_Pin GPIO_PIN_4
#define D_Pin GPIO_PIN_5
#define C_Pin GPIO_PIN_6
#define G_Pin GPIO_PIN_7

/*-----------------------------------------------------------------------------------------------------*/
#define ZERO_SET 					A_Pin | B_Pin | C_Pin | D_Pin | E_Pin| F_Pin
#define ONE_SET  					B_Pin | C_Pin
#define TWO_SET  					A_Pin | B_Pin | D_Pin | E_Pin| G_Pin
#define THREE_SET  				A_Pin | B_Pin | C_Pin | D_Pin | G_Pin
#define FOUR_SET  				B_Pin | C_Pin | F_Pin | G_Pin
#define FIVE_SET  				A_Pin | C_Pin | D_Pin | F_Pin | G_Pin
#define SIX_SET  					A_Pin | C_Pin | D_Pin | E_Pin| F_Pin | G_Pin
#define SEVEN_SET  				A_Pin | B_Pin | C_Pin
#define EIGHT_SET  				A_Pin | B_Pin | C_Pin | D_Pin | E_Pin| F_Pin | G_Pin
#define NINE_SET  				A_Pin | B_Pin | C_Pin | D_Pin | F_Pin | G_Pin
#define DEGREE_SET  			A_Pin | B_Pin | F_Pin | G_Pin
#define C_SET  						A_Pin | D_Pin | E_Pin | F_Pin
/*-------------------------------------------------------------------------------------------------------*/
#define ZERO_RESET  			G_Pin
#define ONE_RESET  				A_Pin | D_Pin | E_Pin| F_Pin | G_Pin
#define TWO_RESET  				C_Pin | F_Pin
#define THREE_RESET  			E_Pin | F_Pin
#define FOUR_RESET  			A_Pin | D_Pin | E_Pin
#define FIVE_RESET  			B_Pin | E_Pin
#define SIX_RESET  				B_Pin
#define SEVEN_RESET  			D_Pin | E_Pin | F_Pin |G_Pin
//#define EIGHT_RESET  			
#define NINE_RESET  			E_Pin
#define DEGREE_RESET  		C_Pin | D_Pin | E_Pin 
#define C_RESET  					B_Pin | C_Pin | G_Pin
/*-------------------------------------------------------------------------------------------------------*/

#define DEGREE				10
#define CENTIGRADE		11

void displayDigit(int digit, int value );
void displayDisplay(int number);

#endif