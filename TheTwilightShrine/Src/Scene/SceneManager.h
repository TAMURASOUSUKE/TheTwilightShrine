#pragma once
#include <vector>
#include <memory>
#include "SceneBase.h"

// シーンを管理するクラス
class SceneManager
{
public:
	SceneManager() = default;
	~SceneManager() = default;

	// コピー代入禁止
	SceneManager(const SceneManager& _other) = delete;
	SceneManager& operator=(const SceneManager& _other) = default;

	// シーン登録関数
	void Register(const std::unique_ptr<SceneBase>& _scene);



private:
	std::vector<std::unique_ptr<SceneBase>> sceneBases{}; // 各シーンのポインタ
};