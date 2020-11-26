#include "DxLib.h"
#include "SettingDxLib.h"
#include "InputKey.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	// DXlib�̏�����
	if ( !DxLibInit() )
	{
		return -1;
	}

	KeyInit();

	// �Q�[�����[�v
	while ( true )
	{
		// ��ʃN���A
		ClearDrawScreen();
		//---------  ��������v���O�������L�q  ----------//

		// �X�V����
		KeyUpdate();

		// �`�揈��


		//---------  �����܂łɃv���O�������L�q  ---------//
		if ( !DxLibGameLoop() )
		{
			break;
		}
	}

	// Dx���C�u�����I������
	DxLib_End();

	// ����I��
	return 0;
}