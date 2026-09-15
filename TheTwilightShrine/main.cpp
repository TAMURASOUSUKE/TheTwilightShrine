#include <TSLib.h>


// エントリーポイント
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// ライブラリ初期化
	constexpr int WINDOW_WIDTH{ 1920 }; // 画面横幅
	constexpr int WINDOW_HEIGHT{ 1080 }; // 画面縦幅
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