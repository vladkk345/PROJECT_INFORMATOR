#include "scroll.h"
#include "delay.h"
#include "7219.h"
#include "ledmatrix.h"
#include "cmsis_os.h"
#include "font.h"

uint8_t ScrollBuff[150];		// Буфер кадра
uint16_t ScrollLines;			// Переменная для строки
//==============================================================================
// Процедура прокручивает на матрице буфер pBuff (ВЛЕВО/ВПРАВО)
//==============================================================================

void demo_ScrollBuff(uint8_t *pBuff, uint16_t ScrollLines, uint8_t RightToLeft)
{
  uint16_t ScrollIdx = (RightToLeft) ? 0 : ScrollLines - 1;

  ledmatrix_fill_screenbuff(0x00);  // Очистка буфера кадра
  
  for (uint16_t i = 0; i < ScrollLines + (MAX7219_NUM * 8); i++)
  {
    if (RightToLeft)    // Прокрутка справа налево
    {
      ledmatrix_ScrollLeft();

      if (i < ScrollLines)
        ledmatrix_screenbuff[(MAX7219_NUM * 8) - 1] = pBuff[ScrollIdx++];
      else
        ledmatrix_screenbuff[(MAX7219_NUM * 8) - 1] = 0;
    }
    else                // Прокрутка слева направо
    {
      ledmatrix_ScrollRight();

      if (i < ScrollLines)
        ledmatrix_screenbuff[0] = pBuff[ScrollIdx--];
      else
        ledmatrix_screenbuff[0] = 0;
    }
      
    ledmatrix_update_from_buff();
      
    osDelay(25);
  }
}

//----------------------------------------Функция по отображению Питерских остановок автобуса--------------------------------

void Piter_bus()
{
	// Отображаем текст и скроллим по матрице справа налево

	ScrollLines = DrawString("Ostorozhno!", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Dveri zakryvautsa!", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Next STOP", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Airport Pulkovo-1", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Bus - 1", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Airport Pulkovo-1", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Staroderevenskaya ulitsa", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Bus - 1", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Airport Pulkovo-1", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Staroderevenskaya ulitsa", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("STOP", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Pulkovo-1", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Ostorozhno!", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Dveri zakryvautsa!", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Next", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("St.m Moskovskaya", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("STOP", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("St.m Moskovskaya", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Ostorozhno!", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Dveri zakryvautsa!", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Next", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Moskovski prospekt, 4", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("STOP", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Moskovski prospekt, 4", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Ostorozhno!", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Dveri zakryvautsa!", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Next", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Nevski prospekt", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("STOP", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Nevski prospekt", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Ostorozhno!", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Dveri zakryvautsa!", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Next", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("St.m Petrogradskaya", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("STOP", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("St.m Petrogradskaya", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Ostorozhno!", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Dveri zakryvautsa!", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Next", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Starodeverenskaya ulitsa", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Last STOP", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("STOP", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Starodeverenskaya", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Last", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("GoodBye!", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);
}

//----------------------------------------Функция по отображению Невельских остановок автобуса--------------------------------

void Nevelsk_bus()
{
	// Отображаем текст и скроллим по матрице справа налево
	ScrollLines = DrawString("Ostorozhno!", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Dveri zakryvautsa!", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Next STOP", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("ATP", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Bus - 3", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("ATP", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Flotskaya ulitsa", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Bus - 3", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("ATP", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Flotskaya ulitsa", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Bus - 3", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("ATP", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Flotskaya ulitsa", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("STOP", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("ATP", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Ostorozhno!", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Dveri zakryvautsa!", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Next STOP", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Viaduk", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("STOP", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Viaduk", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Ostorozhno!", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Dveri zakryvautsa!", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Next STOP", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Severnaya", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("STOP", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Severnaya", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Ostorozhno!", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Dveri zakryvautsa!", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Next STOP", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Skver pamyati voinam", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("STOP", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Skver pamyati voinam", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Ostorozhno!", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Dveri zakryvautsa!", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Next STOP", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Skver Nevelskogo", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Ustupayte mesta", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Snimayte ryukzaki", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Ustupayte mesta", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Snimayte ryukzaki", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("STOP", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Skver Nevelskogo", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Ostorozhno!", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Dveri zakryvautsa!", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Next STOP", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Flotskaya ulitsa", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Last STOP", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("STOP", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Flotskaya ulitsa", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("Last STOP", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("GoodBye!", ScrollBuff, 140);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	// Пустые строки для окончания текста с аудиофайлом
	ScrollLines = DrawString("", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);

	ScrollLines = DrawString("", ScrollBuff, 240);
	demo_ScrollBuff(ScrollBuff, ScrollLines, 1);
}

////==============================================================================
//// Процедура прокручивает на матрице буфер pBuff (ВЛЕВО/ВПРАВО)
////==============================================================================
//void demo_ScrollBuff(uint8_t *pBuff, uint16_t ScrollLines, uint8_t RightToLeft)
//{
//  uint16_t ScrollIdx = (RightToLeft) ? 0 : ScrollLines - 1;

//  fill_screenbuff(0x00);  // Очистка буфера кадра
//  
//  for (uint16_t i = 0; i < ScrollLines + (MAX7219_NUM * 8); i++)
//  {
//    if (RightToLeft)    // Прокрутка справа налево
//    {
//      ScrollLeft();

//      if (i < ScrollLines)
//        screenbuff[(MAX7219_NUM * 8) - 1] = pBuff[ScrollIdx++];
//      else
//        screenbuff[(MAX7219_NUM * 8) - 1] = 0;
//    }
//    else                // Прокрутка слева направо
//    {
////      ScrollRight();

////      if (i < ScrollLines)
////        screenbuff[0] = pBuff[ScrollIdx--];
////      else
////        screenbuff[0] = 0;
//    }
//      
//    update_from_buff();
//      
//    delay_ms(100);
//  }
//}






////int x = 0; // Переменная счетчик

////void demo_ScrollBuff(uint8_t *pBuff, uint16_t ScrollLines, uint8_t RightToLeft)
////{
////  uint16_t ScrollIdx = (RightToLeft) ? 0 : ScrollLines - 1;

////  fill_screenbuff(0x00);  // Очистка буфера кадра
////  
////  for (uint16_t i = 0; i < ScrollLines + (MAX7219_NUM * 8); i++)
////  {
////    if (RightToLeft)    // Прокрутка справа налево
////    {
////      ScrollLeft();

////      if (i < ScrollLines)
////       screenbuff[(MAX7219_NUM * 8) - 1] = pBuff[ScrollIdx++];
////      else
////        screenbuff[(MAX7219_NUM * 8) - 1] = 0;
////    }
//////    else                // Прокрутка слева направо
//////    {
//////      ScrollRight();

//////      if (i < ScrollLines)
//////        screenbuff[0] = pBuff[ScrollIdx--];
//////      else
//////        screenbuff[0] = 0;
//////    }
////      
////    update_from_buff();
////      
////    delay_ms(100);
////  }
////}

//////--------------------------------Функция отображения текста(динамическая индикация)-------------------------

////void demo_ScrollBuff_1(uint8_t *pBuff, uint16_t ScrollLines, uint8_t RightToLeft)
////{
////  uint16_t ScrollIdx = (RightToLeft) ? 0 : ScrollLines - 1;

////  fill_screenbuff(0x00);  
////  
////  for (uint16_t i = 0; i < ScrollLines + (MAX7219_NUM * 8); i++)
////  {
////    if (RightToLeft)    
////    {
////      ScrollLeft();

////      if (i < ScrollLines)
////        screenbuff[(MAX7219_NUM * 8) - 1] = pBuff[ScrollIdx++];
////      else
////        screenbuff[(MAX7219_NUM * 8) - 1] = 0;
////    }
////    
////		// Для отображения статического текста
////		
////		x++;	
////		if (x == 8) 
////		{
////			update_from_buff(); // Отображаем текст один раз (на 8 итерации)	
////		}
////		
////      
////    //delay_ms(1000);
////  }
////}

