#pragma once
#include <vector>
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

	// コピー代入禁止
	SceneManager(const SceneManager& _other) = delete;
	SceneManager& operator=(const SceneManager& _other) = default;

	// シーン登録関数
	void Register(const std::unique_ptr<SceneBase>& _scene);
	// シーン変更関数(true = 成功)
	bool ChangeScene(SceneType _nextScene);


private:
	SceneManager() = default; // シングルトン化のためコンストラクタはprivate

private:
	SceneType currentScene{ SceneType::None }; // 現在のシーン
	std::vector<std::unique_ptr<SceneBase>> sceneBases{}; // 各シーンのポインタ
};