#include "7219.h"
#include "SPI_TRANS.h"

extern SPI_HandleTypeDef hspi1;

#define CS_SET() 	 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET)
#define CS_RESET() HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET)

//==============================================================================
// Процедура отправляет массив команд в max7219
//==============================================================================
void max7219_sendarray(uint16_t *pArray)
{
  CS_RESET();
  
  for (uint8_t i = 0; i < MAX7219_NUM; i++)
    max7219_send16bit(*(pArray++));
  
  CS_SET();
}
//==============================================================================

//==============================================================================
// Процедура отправляет 16-битное слово по SPI
//==============================================================================
void max7219_send16bit(uint16_t Word)
{
	HAL_SPI_Transmit (&hspi1, (uint8_t*)&Word, 1, 5000);
}
//==============================================================================

void Send_data (uint8_t MAX_Idx, uint8_t rg, uint8_t dt)
{
	uint16_t max7219_SpiBuff[MAX7219_NUM];
	uint16_t Word = (uint16_t) rg << 8 | dt;
	
	for (uint8_t i = 0; i < MAX7219_NUM; i++)
  {
    if (MAX_Idx == 0xFF)  // Нужно записать во все max7219 в цепочке
      max7219_SpiBuff[i] = Word;
    else                  // Нужно записать только в один max7219
    {
      if (i == MAX_Idx)         // Та микросхема max7219, в которую нужно записать команду/данные
        max7219_SpiBuff[i] = Word;
      else                      // max7219, которому нет данных на запись
        max7219_SpiBuff[i] = 0x00 | ((uint16_t) MAX7219_CMD_NO_OP << 8);
    }
  }
	 max7219_sendarray(max7219_SpiBuff);
}
