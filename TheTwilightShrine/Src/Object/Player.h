#pragma once
#include <TSLib.h>
#include "ObjectBase.h"

// Playerを実装する
class Player final : public ObjectBase
{
public:
	Player(const Transform& _transform);
	~Player() = default;

	// 更新
	void Update() override;

	// 固定更新
	void FixedUpdate() override;

	// 描画
	void Draw() override;

private:
	Transform transform{}; // 位置、回転、スケール
	int clipIndex{ 0 }; // AnimationのClipIndex

#ifdef _DEBUG
	ModelHandle handle{};
	AnimInstanceHandle instance{};
#endif // _DEBUG

};