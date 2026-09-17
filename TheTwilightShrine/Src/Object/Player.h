#pragma once
#include <TSLib.h>
#include "ObjectBase.h"

// Playerを実装する
class Player final : public ObjectBase
{
private:
	Player() = default; // 一旦デフォルト
	~Player() = default;

	// 更新
	void Update() override;

	// 固定更新
	void FixedUpdate() override;

	// 描画
	void Draw() override;

private:
	Transform transform{}; // 位置、回転、スケール

};