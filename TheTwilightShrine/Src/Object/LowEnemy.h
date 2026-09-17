#pragma once
#include <TSLib.h>
#include "ObjectBase.h"

// 雑魚敵を実装する
class LowEnemy final : public ObjectBase
{
private:
	LowEnemy() = default; // 一旦デフォルト
	~LowEnemy() = default;

	// 更新
	void Update() override;

	// 固定更新
	void FixedUpdate() override;

	// 描画
	void Draw() override;

private:
	Transform transform{}; // 位置、回転、スケール

};