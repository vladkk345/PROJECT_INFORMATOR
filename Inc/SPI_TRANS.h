#ifndef __SPI_TRANS_H__
#define __SPI_TRANS_H__

#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "main.h"

void SPI_SendData8(SPI_TypeDef* SPIx, uint8_t Data);
void SPI_I2S_SendData16(SPI_TypeDef* SPIx, uint16_t Data);
FlagStatus SPI_I2S_GetFlagStatus(SPI_TypeDef* SPIx, uint16_t SPI_I2S_FLAG);

#endif /* __SPI_TRANS_H__ */
