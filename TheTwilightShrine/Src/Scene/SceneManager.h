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

	// 終了処理
	void Shutdown();

	// シーンの更新
	void Update();

	// シーンの固定更新
	void FixedUpdate();

	// シーンの描画
	void Draw();

	// シーン変更を予約する
	bool RequestSceneChange(SceneType _nextScene);

	// 予約を反映する
	void ApplyPendingSceneChange();

private:
	SceneManager(); // シングルトン化のためコンストラクタはprivate

	// シーン変更関数(true = 成功)
	bool ChangeScene(SceneType _nextScene);

private:
	SceneType currentScene{ SceneType::None }; // 現在のシーン
	SceneType pendingScene{ SceneType::None }; // 予約中の遷移先
	std::unique_ptr<SceneBase> scene{}; // シーンのポインタ
};