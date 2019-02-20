#include "74HC595.h"

extern UINT8 LED[]={0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71, 0x40 , 0x00};
//��ʾ�������ֺ���ĸ��λѡ���룬�ֱ���0~9��A~F�������������,���һλ����ʾ���
/**********************************************************
Function Name: Send_Data_To_74HC595
Description: �������ݵ�74HC595
Inputs: {data:���͵�����}
Outputs: None
Writer:  CSJ,MaxMarth
***********************************************************/
static void Send_Data_To_74HC595(UINT8 data)

{
    UINT8 i, Data_temp = 0;
    Data_temp = data;
    for (i = 0; i < 8; i++)              //һ��ֻ�ܷ���һ���ֽڵ����ݣ�8λ)
    {
        if (Data_temp & (1 << 7))         //�Ӹ�λ��ʼ����
            HC595_DATA_HIGH;            //���Ϊ1������������
        else
            HC595_DATA_LOW;             //���Ϊ0������������

        HC595_SCLK_HIGH;   			 //ʱ��������
        NOP(); NOP();
        HC595_SCLK_LOW;                 //ʱ��������
        Data_temp <<= 1;                 //����������λ��������һλ
    }
/*
    for (i=0;i<8;i++)                       ///һ��ֻ�ܷ���һ���ֽڵ����ݣ�8λ��
    {
        if( data_temp & (1<<(7-i)) )        ///�Ӹ�λ��ʼ����
            HC595_DATA_HIGH;                      ///����������
        else
            HC595_DATA_LOW;                       ///����������
        HC595_SCLK_HIGH ;                         ///ʱ��������
        NOP() ; NOP() ;
        HC595_SCLK_LOW ;                          ///ʱ��������
    }
*/
}

/************************************************************
Function Name: Display_74HC595
Inputs: UINT8 sit, UINT8 seg
Outputs: none
Description:    ��74HC595������������,ǰ8λΪ��ѡ�����λΪλѡ��ѡһλ��
Writer: XZ,WH,WZY
*************************************************************/
void Display_74HC595(UINT8 sit , UINT8 seg)    ///situationΪλ,segmentΪ��
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
Description: ����ܵĵڼ�λ��ʾ����0-9
		     ����ܵ�����˳����ҵ�������Ϊ01234567
		     point : 1->�ڸ�λ��ʾС����
		     0->�ڸ�λ����ʾС����
Inputs: {bit:��һλ�������;a_bit_data:��ʾ������;point:�Ƿ���ʾС����}
Outputs: None
Notes: ��2015��ѧϰ����PB0(������)��PB1(������)��PB2(ʱ����)���˿�Ϊ������
       ����74HC595�����跢��16λ����������8λ���ݣ���������������
       ������λHC595_DisplayData(�Ĵ���ͬʱ�����
***********************************************************/
void HC595_Display_Bit(UINT8 bit, UINT8 a_bit_data, UINT8 point)
{
    UINT8 i, data_temp = 0;
    data_temp = LED[a_bit_data];         //ֻ�ܻ�ȡ���ֶ�ѡ�ź�

    if (point)   SetBit(data_temp,7);     //��ʾС����
    else        ClrBit(data_temp,7);     //����ʾС����

    HC595_Init();
    HC595_LCLK_LOW;    //����������
    HC595_SCLK_LOW;    //ʱ��������
    Delay_us(5);
    Send_Data_To_74HC595(~(1 << bit));  //����λѡ�ź�
    Delay_us(5);
    Send_Data_To_74HC595(data_temp);   //���Ͷ�ѡ�ź�

    HC595_LCLK_HIGH;      //������ʵ�ָ������ʮ��λ���ݵ����������
}

/**********************************************************
Function Name: HC595_DisplayData()
Description: ��startλ��stopλ��ʾ����data
		     ����ܵ�����˳�������������Ϊ01234567
Inputs: {start:��ʼλ;stop:��ֹλ;data:��Ҫ��ʾ��ʮ���Ƶ�����}
Outputs: None
Notes: ��2015��ѧϰ����PB0(������)��PB1(������)��PB2(ʱ����)���˿�Ϊ������
        ����õ�����ܵ�λ������ʮ��������λ������λ��ʾ0����001234
***********************************************************/
void HC595_DisplayData(UINT8 start, UINT8 stop ,UINT32  data)
{
    UINT8 i, j, temp;
    j = stop;
    for (i = start; i <= stop ; i++)
    {
    temp = data % 10;   //ѡ��data�ĵ�iλ���Ӹ�λ����λ��)
    HC595_Display_Bit(j, temp, 0);//ͨ��ɨ��ķ�ʽ��ʾ
    j--;
    data /= 10;//ȥ��ĩλ������ʮ������������һλ
    Delay_ms(200);
    }

}


/**********************************************************
Function Name: HC595_DisplayData_Point()
Description: ��startλ��stopλ��ʾ����data
		     ����ܵ�����˳�������������Ϊ01234567
Inputs: {start:��ʼλ;stop:��ֹλ;data:��ʵ������;point_bit:����һλ��ʾС����}
Outputs: None
Notes: ��2015��ѧϰ����PB0(������)��PB1(������)��PB2(ʱ����)���˿�Ϊ������
       С�����Ǵ���������01234567
       ������ʾ��������ʾС��
***********************************************************/
extern void HC595_DisplayData_Point(UINT8 start, UINT8 stop , UINT32  data , UINT8 point_bit)
{
  UINT8 i, j, temp;
  j = stop;
  for (i = start; i <= stop ; i++)
    {
    temp = data % 10;     //ѡ��data��ĩλ���Ӹ�λ����λ��)��������ʾ��λ
    if(j == stop - point_bit)
       HC595_Display_Bit(j, temp, 1);  //����ʾС����
    else
       HC595_Display_Bit(j, temp, 0);  //������ʾС����
    j--;
    data /= 10;       //ȥ��ĩλ������ʮ������������һλ
    Delay_ms(200);
    }
}


/**********************************************************
Function Name: HC595_Init()
Description: ��ʼ���˿ڣ�PB0��PB1��PB2�˿�Ϊ���
Inputs: None
Outputs: None
Notes: ��2015��ѧϰ����PB0(������)��PB1(������)��PB2(ʱ����)���˿�Ϊ������
Writer: MaxMarth
***********************************************************/
void HC595_Init(void)
{
    DDRB |= (1<<HC595_DATA_bit);
    DDRB |= (1<<HC595_LCLK_bit);
    DDRB |= (1<<HC595_SCLK_bit);
    HC595_LCLK_HIGH;      //����������
    HC595_SCLK_HIGH;      //ʱ��������
}
