#pragma once
#include <memory>
#include "SceneBase.h"
#include "../Constant/SceneConstant.h"

// シーンを管理するクラス
class SceneManager
{
public:
	~SceneManager() = default;
	// シングルトン化のためのインスタンス取得
	static SceneManager& Instance()
	{
		static SceneManager instance;
		return instance;
	}
	// シーン変更関数(true = 成功)
	bool ChangeScene(SceneType _nextScene);

	// シーンの更新
	void Update();

	// シーンの固定更新
	void FixedUpdate();

	// シーンの描画
	void Draw();


private:
	SceneManager(); // シングルトン化のためコンストラクタはprivate

private:
	SceneType currentScene{ SceneType::None }; // 現在のシーン
	std::unique_ptr<SceneBase> scene{}; // シーンのポインタ
};