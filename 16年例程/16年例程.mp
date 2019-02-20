Project:      ..\16年例程 - 副本\16年例程
Build Number: 75
Date:         Fri Jan 13 15:53:52 2017
Compiler:     ICCAVR
Version:      8.05.02

NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   0054   00D1 =    209. bytes (rel,con,rom,lit)

       Addr  Global Symbol
      -----  --------------------------------
       0054  __idata_start
       0125  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0126   0E1A =   3610. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0093  __start
       0093  __text_start
       00B5  _exit
       00B6  _Fast_PWM
       00DB  74HC595.c":Send_Data_To_74HC595
       00F0  _Display_74HC595
       0109  _HC595_Display_Bit
       0130  _HC595_DisplayData
       0168  _HC595_DisplayData_Point
       01B3  _HC595_Init
       01B9  _Interrupt_Init
       01CC  _Int0_isr
       01DB  _Int1_isr
       01EA  _ADC_Init
       01FF  _Display_ADC
       0246  _Timer0_Ovf_Isr
       02A7  _Timer0_Init
       02B1  _Timer0_LED_Flow
       02BF  _InitTimer0
       02D6  _OpenT0CTC
       02DD  _CloseT0CTC
       02E4  _MusicNote
       0316  _MusicNote2
       0357  _MusicNoteHalf
       0398  _MusicNoteHalfHalf
       03D9  _MaiBaoGe
       047E  _HuanLeSong
       054D  _main
       05B4  _start
       060D  _uart0_rx_isr
       0649  _USART_Init
       065D  _USART_Rx
       0661  _USART_Tx
       0664  _USART_send
       067E  _Delay_us
       068C  _Delay_ms
       06A2  mod16s
       06A6  div16s
       06C0  mod16u
       06C2  div16u
       06C3  xdiv16u
       06DC  div32u
       06DE  mod32u
       06E2  div32s
       06E4  mod32s
       0710  long_div_prolog
       0723  long_div_epilog
       0733  tst_R16_R19
       0738  tst_R24_R27
       073D  neg_R24_R27
       0746  empy16s
       0756  pop_xgset30FC
       075F  pop_xgsetF0FC
       076A  push_xgsetF0FC
       076C  push_xgset30FC
       076E  push_xgset00FC
       0770  push_xgset003C
       0775  push_xgsetF000
       077A  pop_xgsetF000
       077F  push_xgsetF03C
       0788  pop_xgsetF03C
       0791  neg32
       079A  lsl8
       07A0  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0060   00D1 =    209. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0060  __data_start
       0060  Timer.h":NoteData
       0075  Timer.h":NoteData:1
       008A  _LED
       009C  Timer.h":NoteData:2
       00B1  _turn_flag
       00B3  Timer.h":NoteData:3
       00C8  Timer.h":NoteData:4
       00DD  _LED_Flag
       00DF  Timer.h":NoteData:5
       0106  Timer.h":NoteData:6
       011B  _receive_flag
       011C  Timer.h":NoteData:7
       0131  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   0131   0067 =    103. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0131  _buf
       0131  __bss_start
       0195  _rec
       0196  _num_now
       0197  _receive_now
       0198  __bss_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   0030 =     48. bytes (abs,ovr,rom,code)

Files Linked      [ module(s) ]

C:\iccv8avr\lib\crtatmega.o	[ crtatmega.s ]
.objs\PWM\PWM.o	[ PWM.c ]
.objs\74HC595\74HC595.o	[ _74HC595.c ]
.objs\Interrupt\Interrupt.o	[ Interrupt.c ]
.objs\ADC\ADC.o	[ ADC.c ]
.objs\Timer\Timer.o	[ Timer.c ]
.objs\main.o	[ main.c ]
.objs\Usart\usart.o	[ usart.c ]
.objs\Delay\Delay.o	[ Delay.c ]
<library>	[ div16s.s, div16u.s, div32.s, emul16s.s, gpop4.s, gpop5.s, gpush.s, gpushy.s, gpushb.s, lneg.s, lsl8.s ]


User Global Definitions

ram_end = 0x45f
hwstk_size = 0x14

Area Definitions

-bfunc_lit:0x54.0x1000
-bdata:0x60.0x45f

