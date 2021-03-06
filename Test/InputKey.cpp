#include "DxLib.h"
#include "InputKey.h"

// 初期化処理
void KeyInit()
{
	for ( int i = 0; i < 256; i++ )
	{
		keys[i] = 0;
		oldkeys[i] = 0;
	}
}

// 更新処理
void KeyUpdate()
{
	// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
	for ( int i = 0; i < 256; i++ )
	{
		oldkeys[i] = keys[i];
	}

	// 最新のキーボード情報を取得
	GetHitKeyStateAll(keys);
}

// 前フレームが押されていない状態から押された場合TRUE
bool IsKeyInputNow(int key)
{
	if ( oldkeys[key] == FALSE && keys[key] == TRUE )
	{
		return true;
	}

	return false;
}

// 押されていて離された場合TRUE
bool IsKeyInputRelease(int key)
{
	if ( oldkeys[key] == TRUE && keys[key] == FALSE )
	{
		return true;
	}

	return false;
}