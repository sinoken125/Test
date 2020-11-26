#pragma once

class System
{
private:


public:
	// メイン処理
	bool Main();

	// 初期化処理
	bool Initialize();

	// メインループ
	bool MainLoop();

	// 終了処理
	void Finalize();
};