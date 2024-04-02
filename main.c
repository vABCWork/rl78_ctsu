
#include   "iodefine.h"
#include   "misratypes.h"


#include "timer.h"
#include  "ctsu.h"
#include  "uart.h"
#include  "interval_timer_12bit.h"
#include  "delay.h"
#include  "led_port.h"


// ���C������
// 
void main(void)
{
	PM1_bit.no2 = 0;	// P12�́A�o�̓��[�h�i�f�o�b�O�p�|�[�g)
	
	uart_1_ini();		// UART1 �ʐM�̏�����
	
	interval_timer_12bit_ini();	// 12bit �C���^�[�o���^�C�}�̋N��
	
	ctsu_self_set();	//  �Ód�e�ʎ��^�b�`�Z���T(CTSU)�̐ݒ�
	
	__EI();			// ���荞�݋���
	
	CTSUSTRT = 1; 		 // CTSU�v������J�n
	

	timer_ch4_ini();        // �X�e�b�s���O���[�^ �p���X�ݒ�(�^�C�}�A���C���j�b�g �`�����l��4 �̏�����) 
	p16_out_mode();		// �X�e�b�s���O���[�^ ��]�����ݒ�

	touch_led_port();	// �^�b�`�L�[�p LED�|�[�g�ݒ�
	uart_1_led_port();      // TXD1,RXD1�p LED�|�[�g�ݒ�
	alarm_led_port();	// �A���[���p LED�|�[�g�ݒ�
	
	
	while(1)
	{
	    if ( rcv_over == 1 ) {	// �R�}���h��M����
	      
		comm_cmd();			// ���X�|���X�쐬�A���M
	   	rcv_over = 0;			// �R�}���h��M�t���O�̃N���A
		rcv_cnt  = 0;			//  ��M�o�C�g���̏���
		
	    }
	
	}
	
}

//
// ���g�p�Ȋ��荞�݂ɁA�o�^�����֐�
//  �u�����N�E�I�v�V�������o�̓R�[�h���x�N�^�E�e�[�u���󂫗̈�̃A�h���X�v�� _Dummy �Ƃ���B
//
//�@( �R���p�C����ARETI(61 FC))�@
//
#pragma interrupt Dummy
void Dummy(void)
{
}




