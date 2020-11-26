#include "DxLib.h"
#include "SettingDxLib.h"
#include "InputKey.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	// DXlibの初期化
	if ( !DxLibInit() )
	{
		return -1;
	}

	KeyInit();

	// ゲームループ
	while ( true )
	{
		// 画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//

		// 更新処理
		KeyUpdate();

		// 描画処理


		//---------  ここまでにプログラムを記述  ---------//
		if ( !DxLibGameLoop() )
		{
			break;
		}
	}

	// Dxライブラリ終了処理
	DxLib_End();

	// 正常終了
	return 0;
}