#pragma once
#include "SceneBase.h"

// 実際のゲームシーンを作成する
class GameScene final : public SceneBase
{
	GameScene() = default;
	~GameScene() = default;

	GameScene(const GameScene& _other) = delete;
	GameScene& operator=(const GameScene& _other) = delete;
};