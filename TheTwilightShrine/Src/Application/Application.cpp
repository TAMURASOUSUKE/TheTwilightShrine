#include <TSLib.h>
#include "../Scene/SceneManager.h" 
#include "Application.h"

Application::Application()
{
	// ライブラリ初期化
	constexpr int WINDOW_WIDTH{ 1920 }; // 画面横幅
	constexpr int WINDOW_HEIGHT{ 1080 }; // 画面縦幅
	if (!TSLib::Initialize(L"黄昏の社", WINDOW_WIDTH, WINDOW_HEIGHT))
	{
		isInitialized = false;
		return;
	}
	SceneManager::Instance().ChangeScene(SceneType::Title); // とりあえず最初はタイトルから
	isInitialized = true; // ここまで来たら成功とする
}

Application::~Application()
{
	// シーンマネージャー終了処理
	SceneManager::Instance().Shutdown();
	// ライブラリ終了処理
	TSLib::Finish();
}

void Application::Run()
{
	// ゲームループ(後でApplicationファイルへと分離)
	while (TSLib::ProcessMessage())
	{
		TSLib::BeginFrame(); // フレーム開始処理

		// シーン更新
		SceneManager::Instance().Update();

		// 固定更新に必要な時間が溜まっていればその分だけ消費し続ける
		while (Time::IsFixedUpdateRequired()) // FixedUpdateを行う必要があるかを更新する
		{
			SceneManager::Instance().FixedUpdate();
			Time::ConsumeFixedTime(); // 一回分の時間を消費
		}

		if (Input::IsKeyPushed(KeyCode::Button::T)) SceneManager::Instance().ChangeScene(SceneType::Title);
		if (Input::IsKeyPushed(KeyCode::Button::G)) SceneManager::Instance().ChangeScene(SceneType::Game);

		Gfx::ClearScreen(); // 画面クリア

		SceneManager::Instance().Draw();

		TSLib::EndFrame(); // フレーム終了処理
	}
}