#include "DxLib.h"
#include "System.h"
#include "SettingDxLib.h"

// ���C������
bool System::Main()
{
	// ����������
	if ( !Initialize() )
	{
		return false;
	}

	// ���C�����[�v�������s��
	if ( !MainLoop() )
	{
		return false;
	}

	// �I������
	Finalize();

	return true;
}

// ����������
bool System::Initialize()
{
	// DXLib�̏�����
	if ( !DxLibInit() )
	{
		return false;
	}

	// ���͏����̏�����
	KeyInit();

	return true;
}

// ���C�����[�v
bool System::MainLoop()
{
	// �Q�[�����[�v
	while ( true )
	{
		// ��ʃN���A
		ClearDrawScreen();

		// �X�V����
		KeyUpdate();

		// �`�揈��


		if ( !DxLibGameLoop() )
		{
			return false;
		}
	}

	return true;
}

// �I������
void System::Finalize()
{
	// Dx���C�u�����I������
	DxLib_End();
}