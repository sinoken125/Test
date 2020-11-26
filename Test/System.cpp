#include "DxLib.h"
#include "System.h"
#include "SettingDxLib.h"

// メイン処理
bool System::Main()
{
	// 初期化処理
	if ( !Initialize() )
	{
		return false;
	}

	// メインループ処理を行う
	if ( !MainLoop() )
	{
		return false;
	}

	// 終了処理
	Finalize();

	return true;
}

// 初期化処理
bool System::Initialize()
{
	// DXLibの初期化
	if ( !DxLibInit() )
	{
		return false;
	}

	// 入力処理の初期化
	KeyInit();

	return true;
}

// メインループ
bool System::MainLoop()
{
	// ゲームループ
	while ( true )
	{
		// 画面クリア
		ClearDrawScreen();

		// 更新処理
		KeyUpdate();

		// 描画処理


		if ( !DxLibGameLoop() )
		{
			return false;
		}
	}

	return true;
}

// 終了処理
void System::Finalize()
{
	// Dxライブラリ終了処理
	DxLib_End();
}