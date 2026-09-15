#include <TSLib.h>
#include "Src/Constant/SystemConstant.h"

// エントリーポイント
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// ライブラリ初期化
	if (!TSLib::Initialize(L"黄昏の社", WINDOW_WIDTH, WINDOW_HEIGHT)) return -1;

	// ゲームループ(後でApplicationファイルへと分離)
	while (TSLib::ProcessMessage())
	{
		TSLib::BeginFrame(); // フレーム開始処理

		Gfx::ClearScreen(); // 画面クリア

		Gfx::DrawString("TSGameLibConnected...", Vector2::Zero);

		TSLib::EndFrame(); // フレーム終了処理
	}

	// ライブラリ終了処理
	TSLib::Finish(); 
}