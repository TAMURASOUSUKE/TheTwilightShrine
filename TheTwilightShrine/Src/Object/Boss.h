#pragma once
#include <TSLib.h>
#include "ObjectBase.h"

// Bossを実装する
class Boss final : public ObjectBase
{
private:
	Boss(const Transform& _transform);
	~Boss() = default;

	// 更新
	void Update() override;

	// 固定更新
	void FixedUpdate() override;

	// 描画
	void Draw() override;

private:
	Transform transform{}; // 位置、回転、スケール

};