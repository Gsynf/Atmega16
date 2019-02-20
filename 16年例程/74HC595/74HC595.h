#ifndef _74HC505_H_
#define _74HC595_H_

#include "../Headers/Global.h"

#define  HC595_DATA_bit (0)
#define  HC595_LCLK_bit (1)
#define  HC595_SCLK_bit (2)


#define HC595_DATA_HIGH   PORTB |= (1<<HC595_DATA_bit)
#define HC595_DATA_LOW    PORTB &= ~(1<<HC595_DATA_bit) //数据线

#define HC595_LCLK_HIGH   PORTB |= (1<<HC595_LCLK_bit)
#define HC595_LCLK_LOW    PORTB &= ~(1<<HC595_LCLK_bit) //锁存线

#define HC595_SCLK_HIGH   PORTB |= (1<<HC595_SCLK_bit)
#define HC595_SCLK_LOW    PORTB &= ~(1<<HC595_SCLK_bit) //时钟线

extern void HC595_Init(void);
static void Send_Data_To_74HC595(UINT8 data);
extern void HC595_Display_Bit(UINT8 bit, UINT8 a_bit_data, UINT8 Point);
extern void HC595_DisplayData(UINT8 start, UINT8 stop , UINT32  data);
extern void HC595_DisplayData_Point( UINT8 start, UINT8 stop, UINT32  data, UINT8 point_bit);
extern void Display_74HC595(UINT8 sit, UINT8 seg);

#endif
