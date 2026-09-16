#pragma once

// ゲームループなどアプリのシステムを担当する
class Application
{
public:
	// コンストラクタでライブラリなどを初期化
	Application(); 
	// デストラクタでライブラリなどの終了処理
	~Application(); 

	// ゲームループを担当する
	void Run();

	// 有効状態かを返す
	bool IsValid() const { return isInitialized; }

private:
	bool isInitialized{ false }; // 初期化できたか

};