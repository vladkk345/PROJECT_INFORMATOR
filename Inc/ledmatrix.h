#ifndef _LEDMATRIX_H
#define _LEDMATRIX_H

#include "stm32f4xx.h"

extern uint8_t screenbuff[];

void init(void);
void fill_screenbuff(uint8_t FillValue);
void ScrollLeft(void);
void update_from_buff(void);


extern uint8_t ledmatrix_screenbuff[];


// Процедура инициализирует матрицу
void ledmatrix_init(void);
// Процедура управляет режимом Test матрицы
void ledmatrix_testmatrix(uint8_t TestOn);
// Процедура устанавливает яркость матрицы. Диапазон 0-15
void ledmatrix_set_brightness(uint8_t Value);
// Процедура заполняет буфер кадра значением FillValue
void ledmatrix_fill_screenbuff(uint8_t FillValue);
// Процедура сдвигает содержимое буфера кадра ВЛЕВО
// Самый правый столбец сохраняет при этом своё старое значение
void ledmatrix_ScrollLeft(void);
// Процедура сдвигает содержимое буфера кадра ВПРАВО
// Самый левый столбец сохраняет при этом своё старое значение
void ledmatrix_ScrollRight(void);
// Процедура обновляет состояние индикаторов в соответствии с буфером экрана ledmatrix_screenbuff
void ledmatrix_update_from_buff(void);

#endif /* __LEDMATRIX_H__ */
