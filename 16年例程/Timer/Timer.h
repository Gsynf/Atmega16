#ifndef _Timer_H_
#define _Timer_H_


#include "../Headers/Global.h"

/*-------------------T I M E R 0-------------------*/
//宏定义
//2拍音
#define _O2      MusicNote2(0);
#define _Re2     MusicNote2(1);
#define _Mi2     MusicNote2(2);
#define _Fa2     MusicNote2(3);
#define _Sol2    MusicNote2(4);
#define _La2     MusicNote2(5);
#define _Si2     MusicNote2(6);
#define Do2      MusicNote2(7);
#define Re2      MusicNote2(8);
#define Mi2      MusicNote2(9);
#define Fa2      MusicNote2(10);
#define Sol2     MusicNote2(11);
#define La2      MusicNote2(12);
#define Si2      MusicNote2(13);
#define Do2_     MusicNote2(14);
#define Re2_     MusicNote2(15);
#define Mi2_     MusicNote2(16);
#define Fa2_     MusicNote2(17);
#define Sol2_    MusicNote2(18);
#define La2_     MusicNote2(19);
#define Si2_     MusicNote2(20);

//1拍音
#define _O      MusicNote(0);
#define _Re     MusicNote(1);
#define _Mi     MusicNote(2);
#define _Fa     MusicNote(3);
#define _Sol    MusicNote(4);
#define _La     MusicNote(5);
#define _Si     MusicNote(6);
#define Do      MusicNote(7);
#define Re      MusicNote(8);
#define Mi      MusicNote(9);
#define Fa      MusicNote(10);
#define Sol     MusicNote(11);
#define La      MusicNote(12);
#define Si      MusicNote(13);
#define Do_     MusicNote(14);
#define Re_     MusicNote(15);
#define Mi_     MusicNote(16);
#define Fa_     MusicNote(17);
#define Sol_    MusicNote(18);
#define La_     MusicNote(19);
#define Si_     MusicNote(20);
//1/2拍音
#define _OH      MusicNoteHalf(0);
#define _ReH     MusicNoteHalf(1);
#define _MiH     MusicNoteHalf(2);
#define _FaH     MusicNoteHalf(3);
#define _SolH    MusicNoteHalf(4);
#define _LaH     MusicNoteHalf(5);
#define _SiH     MusicNoteHalf(6);
#define DoH      MusicNoteHalf(7);
#define ReH      MusicNoteHalf(8);
#define MiH      MusicNoteHalf(9);
#define FaH      MusicNoteHalf(10);
#define SolH     MusicNoteHalf(11);
#define LaH      MusicNoteHalf(12);
#define SiH      MusicNoteHalf(13);
#define Do_H     MusicNoteHalf(14);
#define Re_H     MusicNoteHalf(15);
#define Mi_H     MusicNoteHalf(16);
#define Fa_H     MusicNoteHalf(17);
#define Sol_H    MusicNoteHalf(18);
#define La_H     MusicNoteHalf(19);
#define Si_H     MusicNoteHalf(20);
//1/4拍音
#define _OHH      MusicNoteHalfHalf(0);
#define _ReHH     MusicNoteHalfHalf(1);
#define _MiHH     MusicNoteHalfHalf(2);
#define _FaHH     MusicNoteHalfHalf(3);
#define _SolHH    MusicNoteHalfHalf(4);
#define _LaHH     MusicNoteHalfHalf(5);
#define _SiHH     MusicNoteHalfHalf(6);
#define DoHH      MusicNoteHalfHalf(7);
#define ReHH      MusicNoteHalfHalf(8);
#define MiHH      MusicNoteHalfHalf(9);
#define FaHH      MusicNoteHalfHalf(10);
#define SolHH     MusicNoteHalfHalf(11);
#define LaHH      MusicNoteHalfHalf(12);
#define SiHH      MusicNoteHalfHalf(13);
#define Do_HH     MusicNoteHalfHalf(14);
#define Re_HH     MusicNoteHalfHalf(15);
#define Mi_HH     MusicNoteHalfHalf(16);
#define Fa_HH     MusicNoteHalfHalf(17);
#define Sol_HH    MusicNoteHalfHalf(18);
#define La_HH     MusicNoteHalfHalf(19);
#define Si_HH     MusicNoteHalfHalf(20);

//端口定义
#define TIMER0_DDR  DDRB
#define TIMER0_PORT PORTB
#define TIMER0_OCR0 (3)

//函数声明
extern void InitTimer0(void);
extern void OpenT0CTC(void);
extern void CloseT0CTC(void);
extern void MusicNote2(int n);
extern void MusicNote(int n);
extern void MusicNoteHalf(int n);
extern void MusicNoteHalfHalf(int n);
extern void MaiBaoGe(void);
extern void FaRuXue(void);
extern void ForElise(void);
extern void Xiaoxingxing(void);
extern int music_flag;
extern int break_flag;


//变量

static UINT8 NoteData[]={0,252,225,212,188,168,150,141,126,112,105,94,83,74,70,62,55,52,46,41,37};
//从_Re 到Si_的OCR0的值  NoteData[0]=0 为休止符


extern void Timer0_Ovf_Isr(void);
extern void Timer0_Init(void);
extern int Timer0_LED_Flow(void);


#endif
