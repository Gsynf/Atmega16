#include "74HC595.h"

extern UINT8 LED[]={0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71, 0x40 , 0x00};
//显示各种数字和字母的位选编码，分别是0~9，A~F共阴数码管适用,最后一位是显示横杠
/**********************************************************
Function Name: Send_Data_To_74HC595
Description: 发送数据到74HC595
Inputs: {data:发送的数据}
Outputs: None
Writer:  CSJ,MaxMarth
***********************************************************/
static void Send_Data_To_74HC595(UINT8 data)

{
    UINT8 i, Data_temp = 0;
    Data_temp = data;
    for (i = 0; i < 8; i++)              //一次只能发送一个字节的数据（8位)
    {
        if (Data_temp & (1 << 7))         //从高位开始发送
            HC595_DATA_HIGH;            //如果为1，拉高数据线
        else
            HC595_DATA_LOW;             //如果为0，拉蒂数据线

        HC595_SCLK_HIGH;   			 //时钟线拉高
        NOP(); NOP();
        HC595_SCLK_LOW;                 //时钟线拉低
        Data_temp <<= 1;                 //数据向左移位，发送下一位
    }
/*
    for (i=0;i<8;i++)                       ///一次只能发送一个字节的数据（8位）
    {
        if( data_temp & (1<<(7-i)) )        ///从高位开始发送
            HC595_DATA_HIGH;                      ///数据线拉高
        else
            HC595_DATA_LOW;                       ///数据线拉低
        HC595_SCLK_HIGH ;                         ///时钟线拉高
        NOP() ; NOP() ;
        HC595_SCLK_LOW ;                          ///时钟线拉低
    }
*/
}

/************************************************************
Function Name: Display_74HC595
Inputs: UINT8 sit, UINT8 seg
Outputs: none
Description:    向74HC595发送两次数据,前8位为段选，后八位为位选（选一位）
Writer: XZ,WH,WZY
*************************************************************/
void Display_74HC595(UINT8 sit , UINT8 seg)    ///situation为位,segment为段
{
    HC595_Init();
    HC595_LCLK_LOW;
    HC595_SCLK_LOW;
    Send_Data_To_74HC595(~(1 << sit));
    Send_Data_To_74HC595(LED[seg]);
    HC595_LCLK_HIGH;
}

/**********************************************************
Function Name: HC595_Display_Bit
Description: 数码管的第几位显示数字0-9
		     数码管的排列顺序从右到左依次为01234567
		     point : 1->在该位显示小数点
		     0->在该位不显示小数点
Inputs: {bit:哪一位数码管亮;a_bit_data:显示的数字;point:是否显示小数点}
Outputs: None
Notes: 在2015级学习板上PB0(数据线)，PB1(锁存线)，PB2(时钟线)三端口为控制线
       两个74HC595串联需发送16位，连发两次8位数据，最后在拉高输出，
       两个移位HC595_DisplayData(寄存器同时输出。
***********************************************************/
void HC595_Display_Bit(UINT8 bit, UINT8 a_bit_data, UINT8 point)
{
    UINT8 i, data_temp = 0;
    data_temp = LED[a_bit_data];         //只能获取数字段选信号

    if (point)   SetBit(data_temp,7);     //显示小数点
    else        ClrBit(data_temp,7);     //不显示小数点

    HC595_Init();
    HC595_LCLK_LOW;    //锁存线拉低
    HC595_SCLK_LOW;    //时钟线拉低
    Delay_us(5);
    Send_Data_To_74HC595(~(1 << bit));  //发送位选信号
    Delay_us(5);
    Send_Data_To_74HC595(data_temp);   //发送段选信号

    HC595_LCLK_HIGH;      //上升沿实现刚移入的十六位数据的输出及锁存
}

/**********************************************************
Function Name: HC595_DisplayData()
Description: 从start位到stop位显示数字data
		     数码管的排列顺序从左往右依次为01234567
Inputs: {start:起始位;stop:截止位;data:需要显示的十进制的数字}
Outputs: None
Notes: 在2015级学习板上PB0(数据线)，PB1(锁存线)，PB2(时钟线)三端口为控制线
        如果用的数码管的位数超过十进制数的位数，高位显示0，如001234
***********************************************************/
void HC595_DisplayData(UINT8 start, UINT8 stop ,UINT32  data)
{
    UINT8 i, j, temp;
    j = stop;
    for (i = start; i <= stop ; i++)
    {
    temp = data % 10;   //选出data的第i位（从高位往低位数)
    HC595_Display_Bit(j, temp, 0);//通过扫描的方式显示
    j--;
    data /= 10;//去除末位，并将十进制数向右移一位
    Delay_ms(200);
    }

}


/**********************************************************
Function Name: HC595_DisplayData_Point()
Description: 从start位到stop位显示数字data
		     数码管的排列顺序从左往右依次为01234567
Inputs: {start:起始位;stop:截止位;data:现实的数字;point_bit:在哪一位显示小数点}
Outputs: None
Notes: 在2015级学习板上PB0(数据线)，PB1(锁存线)，PB2(时钟线)三端口为控制线
       小数点是从右往左数01234567
       这种显示方法可显示小数
***********************************************************/
extern void HC595_DisplayData_Point(UINT8 start, UINT8 stop , UINT32  data , UINT8 point_bit)
{
  UINT8 i, j, temp;
  j = stop;
  for (i = start; i <= stop ; i++)
    {
    temp = data % 10;     //选出data的末位（从高位往低位数)，首先显示低位
    if(j == stop - point_bit)
       HC595_Display_Bit(j, temp, 1);  //该显示小数点
    else
       HC595_Display_Bit(j, temp, 0);  //不该显示小数点
    j--;
    data /= 10;       //去除末位，并将十进制数向右移一位
    Delay_ms(200);
    }
}


/**********************************************************
Function Name: HC595_Init()
Description: 初始化端口，PB0，PB1，PB2端口为输出
Inputs: None
Outputs: None
Notes: 在2015级学习板上PB0(数据线)，PB1(锁存线)，PB2(时钟线)三端口为控制线
Writer: MaxMarth
***********************************************************/
void HC595_Init(void)
{
    DDRB |= (1<<HC595_DATA_bit);
    DDRB |= (1<<HC595_LCLK_bit);
    DDRB |= (1<<HC595_SCLK_bit);
    HC595_LCLK_HIGH;      //锁存线拉高
    HC595_SCLK_HIGH;      //时钟线拉高
}
