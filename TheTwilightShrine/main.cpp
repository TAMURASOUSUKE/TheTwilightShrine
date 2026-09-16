#include <Windows.h>
#include "Src/Application/Application.h"

// エントリーポイント
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application app{}; // アプリケーション
	if (!app.IsValid()) return; // 有効状態になっていなければ失敗とする
	app.Run(); // アプリケーションを走らせる
}