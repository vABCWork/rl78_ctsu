
#include   "iodefine.h"
#include   "misratypes.h"


#include "timer.h"
#include  "ctsu.h"
#include  "uart.h"
#include  "interval_timer_12bit.h"
#include  "delay.h"
#include  "led_port.h"


// メイン処理
// 
void main(void)
{
	PM1_bit.no2 = 0;	// P12は、出力モード（デバッグ用ポート)
	
	uart_1_ini();		// UART1 通信の初期化
	
	interval_timer_12bit_ini();	// 12bit インターバルタイマの起動
	
	ctsu_self_set();	//  静電容量式タッチセンサ(CTSU)の設定
	
	__EI();			// 割り込み許可
	
	CTSUSTRT = 1; 		 // CTSU計測動作開始
	

	timer_ch4_ini();        // ステッピングモータ パルス設定(タイマアレイユニット チャンネル4 の初期化) 
	p16_out_mode();		// ステッピングモータ 回転方向設定

	touch_led_port();	// タッチキー用 LEDポート設定
	uart_1_led_port();      // TXD1,RXD1用 LEDポート設定
	alarm_led_port();	// アラーム用 LEDポート設定
	
	
	while(1)
	{
	    if ( rcv_over == 1 ) {	// コマンド受信完了
	      
		comm_cmd();			// レスポンス作成、送信
	   	rcv_over = 0;			// コマンド受信フラグのクリア
		rcv_cnt  = 0;			//  受信バイト数の初期
		
	    }
	
	}
	
}

//
// 未使用な割り込みに、登録される関数
//  「リンク・オプション→出力コード→ベクタ・テーブル空き領域のアドレス」で _Dummy とする。
//
//　( コンパイル後、RETI(61 FC))　
//
#pragma interrupt Dummy
void Dummy(void)
{
}




