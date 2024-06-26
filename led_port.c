
#include "iodefine.h"
#include "misratypes.h"
#include "led_port.h"



//
//  SW1〜SW4 LED 出力ポート設定
//  
//  P05 : SW4 LED : (TS06)
//  P07 : SW3 LED : (TS08)
//  P20 : SW2 LED : (TS10)
//  P43 : SW1 LED : (TS13) 
//
// 1) PCM (ポート出力モード・レジスタ): CMOS 出力／N-ch オープン・ドレイン出力を1 ビット単位で設定
//    0: 通常出力モード 
//    1: N-ch オープン・ドレイン出力（VDD 耐圧）モード
//    リセット信号の発生により、00H
//
// 2)PMC(ポート・モード・コントロール・レジスタ): デジタル入出力／アナログ入力を 1 ビット単位で設定
//   0:デジタル入出力（アナログ入力以外の兼用機能）
//   1:アナログ入力
//  リセット信号の発生により、FFH
//
// 3)PM(ポート・モード・レジスタ): ポートの入力／出力を 1 ビット単位で設定
//   0:出力モード（出力バッファ・オン）
//   1:入力モード（出力バッファ・オフ）
//リセット信号の発生により、FFH
//
//  4)P(ポート・レジスタ) : ポートの出力ラッチの値を設定
//   0: 0 を出力（出力モード時）
//   1: 1 を出力（出力モード時）
//リセット信号の発生により、P13 は不定、その他は00H
//
//  5)TSSELt(タッチ端子機能選択レジスタ):タッチ端子機能以外（兼用機能）／タッチ端子機能のどちらで使用するかを設定
//   0: タッチ端子機能以外（兼用機能）として使用
//   1: タッチ端子機能として使用
//  リセット信号の発生により、00H
//
/// 資料「RL78/G16　ユーザーズマニュアル ハードウェア編」(Rev.1.10 2023.08)
//         4.5.3 使用するポート機能および兼用機能のレジスタ設定例
//
void touch_led_port(void)
{
	POM0_bit.no5 = 0;	// P05は、通常出力モード
	PMC0_bit.no5 = 0;       // P05は、デジタル入出力
	PM0_bit.no5 = 0;	// P05は、出力モード
	P0_bit.no5 = 0;		// P05 = 0 を出力
	
	POM0_bit.no7 = 0;	// P07は、通常出力モード
	PMC0_bit.no7 = 0;       // P07は、デジタル入出力
	PM0_bit.no7 = 0;	// P07は、出力モード
	P0_bit.no7 = 0;		// P07 = 0 を出力
	
	POM2_bit.no0 = 0;	// P20は、通常出力モード
	PMC2_bit.no0 = 0;       // P20は、デジタル入出力
	PM2_bit.no0 = 0;	// P20は、出力モード
	P2_bit.no0 = 0;		// P20 = 0 を出力
	
	PM4_bit.no3 = 0;	// P43は、出力モード
	P4_bit.no3 = 0;		// P43 = 0 を出力
}

//
//  TXD1,RXD1 LED 出力ポート設定
//   P14 : RXD1_LED
//   P15 : TXD1_LED
//
void uart_1_led_port(void)
{
	POM1_bit.no4 = 0;	// P14は、通常出力モード
	PM1_bit.no4 = 0;	// P14は、出力モード
	P1_bit.no4 = 0;		// P14 = 0 を出力

	PM1_bit.no5 = 0;	// P15は、出力モード
	P1_bit.no5 = 0;		// P15 = 0 を出力
}


//
//  Alarm LED 出力ポート設定
//   P13 : ALM_LED
//
void alarm_led_port(void)
{

	PM1_bit.no3 = 0;	// P13は、出力モード
	P1_bit.no3 = 0;		// P13 = 0 を出力
}
