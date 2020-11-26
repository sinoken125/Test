#include "DxLib.h"
#include "SettingDxLib.h"
#include "Define.h"

bool DxLibInit()
{
	// �E�B���h�E���[�h�ɐݒ�
	ChangeWindowMode(TRUE);

	// �E�B���h�E�T�C�Y���蓮�ł͕ύX�������A
	// ���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ���
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// �^�C�g����ύX
	SetMainWindowText(TITLE);

	// ��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�(���j�^�[�̉𑜓x�ɍ��킹��)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// ��ʃT�C�Y��ݒ�(�𑜓x�Ƃ̔䗦�Őݒ�)
	SetWindowSizeExtendRate(1.0);

	// ��ʂ̔w�i�F��ݒ肷��
	SetBackgroundColor(0x00, 0x0, 0x00);

	// (�_�u���o�b�t�@)�`���O���t�B�b�N�̈�͗��ʂ��w��
	SetDrawScreen(DX_SCREEN_BACK);

	// DxLib�̏�����
	if ( DxLib_Init() == -1 )
	{
		// �ُ�I��
		return false;
	}

	// ����I��
	return true;
}

bool DxLibGameLoop()
{
	// (�_�u���o�b�t�@)����
	ScreenFlip();

	// 20�~���b�ҋ@(�^��60FPS)
	WaitTimer(20);

	// Windows�V�X�e�����炭�������������
	if ( ProcessMessage() == -1 )
	{
		return false;
	}

	// ESC�L�[�������ꂽ�烋�[�v���甲����
	if ( IsKeyInputRelease(KEY_INPUT_ESCAPE) )
	{
		return false;
	}

	return true;
}