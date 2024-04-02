
#include "iodefine.h"
#include "misratypes.h"

#include "interval_timer_12bit.h"



// intera_timer���x�N�^�A�h���X(INIT=0x0038)�ɓo�^
#pragma interrupt INT_interval_timer(vect=INTIT)

// �C���^�[�o���^�C�}���荞�ݏ��� (10msec���ɔ���)
// �p�r:
//      1) CTSU�̌v���J�n�g���K�M��(10msec��)
//     
void INT_interval_timer(void)
{
	P1_bit.no2  = 1;			// P12 = 1���o�́@(�f�o�b�O�p)
}


// �C���^�[�o���^�C�} 12bit�̏����ݒ� (10msec) �@CTSU�v���J�n�̃g���K�M��
//�@
void interval_timer_12bit_ini(void)
{
	OSMC = 0x10;		// ���Ӌ@�\�ւ̃T�u�V�X�e���E�N���b�N��������, �ᑬ�I���`�b�v�E�I�V���[�^�E�N���b�N�ifIL�j(15 [KHz])���C���^�[�o���^�C�}�֋����@

	TMKAEN = 1;		// 12 �r�b�g�E�C���^�[�o���E�^�C�}�֓��̓N���b�N���� (���ӃC�l�[�u���E���W�X�^0�iPER0�j�̃r�b�g 7 )
	
	ITMC = 149;            //  150 - 1 count, 10msec , ( 15[KHz], 1clock=1/15 [msec] , 150 count/ 15 = 10 [msec])
	
	ITMC = ITMC | 0x8000;      // RINTE:�J�E���^����J�n
	
	ITMK = 0;		// 12 �r�b�g�E�C���^�[�o���E�^�C�}���荞�݂̃}�X�N���N���A
	
} 