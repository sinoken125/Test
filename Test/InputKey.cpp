#include "DxLib.h"
#include "InputKey.h"

// ����������
void KeyInit()
{
	for ( int i = 0; i < 256; i++ )
	{
		keys[i] = 0;
		oldkeys[i] = 0;
	}
}

// �X�V����
void KeyUpdate()
{
	// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
	for ( int i = 0; i < 256; i++ )
	{
		oldkeys[i] = keys[i];
	}

	// �ŐV�̃L�[�{�[�h�����擾
	GetHitKeyStateAll(keys);
}

// �O�t���[����������Ă��Ȃ���Ԃ��牟���ꂽ�ꍇTRUE
bool IsKeyInputNow(int key)
{
	if ( oldkeys[key] == FALSE && keys[key] == TRUE )
	{
		return true;
	}

	return false;
}

// ������Ă��ė����ꂽ�ꍇTRUE
bool IsKeyInputRelease(int key)
{
	if ( oldkeys[key] == TRUE && keys[key] == FALSE )
	{
		return true;
	}

	return false;
}