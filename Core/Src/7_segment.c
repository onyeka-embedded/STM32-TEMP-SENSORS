#include "7_segment.h"


void displayDigit(int page, int value){
	
    switch (page)
    {
    case 1:
				HAL_GPIO_WritePin(PAGE_CTRL, PAGE2_Pin | PAGE3_Pin | PAGE4_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(PAGE_CTRL, PAGE1_Pin, GPIO_PIN_SET);
        break;
    case 2:
				HAL_GPIO_WritePin(PAGE_CTRL, PAGE1_Pin | PAGE3_Pin | PAGE4_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(PAGE_CTRL, PAGE2_Pin, GPIO_PIN_SET);
        break;
    case 3:
				HAL_GPIO_WritePin(PAGE_CTRL, PAGE1_Pin | PAGE2_Pin | PAGE4_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(PAGE_CTRL, PAGE3_Pin, GPIO_PIN_SET);
        break;
    case 4:
				HAL_GPIO_WritePin(PAGE_CTRL, PAGE1_Pin | PAGE2_Pin | PAGE3_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(PAGE_CTRL, PAGE4_Pin, GPIO_PIN_SET);
        break;
    }
    switch (value)
    {
    case 0:
        HAL_GPIO_WritePin(DATA_PAGE, ZERO_SET, GPIO_PIN_SET);
        HAL_GPIO_WritePin(DATA_PAGE, ZERO_RESET, GPIO_PIN_RESET);
        break;
    case 1:
        HAL_GPIO_WritePin(DATA_PAGE, ONE_SET, GPIO_PIN_SET);
        HAL_GPIO_WritePin(DATA_PAGE, ONE_RESET, GPIO_PIN_RESET);
        break;
    case 2:
        HAL_GPIO_WritePin(DATA_PAGE, TWO_SET, GPIO_PIN_SET);
        HAL_GPIO_WritePin(DATA_PAGE, TWO_RESET, GPIO_PIN_RESET);
        break;
    case 3:
				HAL_GPIO_WritePin(DATA_PAGE, THREE_SET, GPIO_PIN_SET);
        HAL_GPIO_WritePin(DATA_PAGE, THREE_RESET, GPIO_PIN_RESET);
        break;
    case 4:
        HAL_GPIO_WritePin(DATA_PAGE, FOUR_SET, GPIO_PIN_SET);
        HAL_GPIO_WritePin(DATA_PAGE, FOUR_RESET, GPIO_PIN_RESET);
        break;
    case 5:
        HAL_GPIO_WritePin(DATA_PAGE, FIVE_SET, GPIO_PIN_SET);
        HAL_GPIO_WritePin(DATA_PAGE, FIVE_RESET, GPIO_PIN_RESET);
        break;
    case 6:
        HAL_GPIO_WritePin(DATA_PAGE, SIX_SET, GPIO_PIN_SET);
        HAL_GPIO_WritePin(DATA_PAGE, SIX_RESET, GPIO_PIN_RESET);
        break;
    case 7:
        HAL_GPIO_WritePin(DATA_PAGE, SEVEN_SET, GPIO_PIN_SET);
        HAL_GPIO_WritePin(DATA_PAGE, SEVEN_RESET, GPIO_PIN_RESET);
        break;
    case 8:
        HAL_GPIO_WritePin(DATA_PAGE, EIGHT_SET, GPIO_PIN_SET);
        /*HAL_GPIO_WritePin(DATA_PAGE, EIGHT_RESET, GPIO_PIN_RESET);*/
        break;
    case 9:
        HAL_GPIO_WritePin(DATA_PAGE, NINE_SET, GPIO_PIN_SET);
        HAL_GPIO_WritePin(DATA_PAGE, NINE_RESET, GPIO_PIN_RESET);
        break;
		case 10:
        HAL_GPIO_WritePin(DATA_PAGE, DEGREE_SET, GPIO_PIN_SET);
        HAL_GPIO_WritePin(DATA_PAGE, DEGREE_RESET, GPIO_PIN_RESET);
        break;
		case 11:
        HAL_GPIO_WritePin(DATA_PAGE, C_SET, GPIO_PIN_SET);
        HAL_GPIO_WritePin(DATA_PAGE, C_RESET, GPIO_PIN_RESET);
        break;
    }
}

void displayDisplay(int number){
	
    int page1 = number / 1000;
    int page2 = (number / 100) % 10;
    int page3 = (number / 10) % 10;
    int page4 = number % 10;

	    displayDigit(1, page3);
			HAL_Delay(1);
			displayDigit(2, page4);
			HAL_Delay(1);
			displayDigit(3, DEGREE);
			HAL_Delay(1);
			displayDigit(4, CENTIGRADE);
			HAL_Delay(1);
 
}