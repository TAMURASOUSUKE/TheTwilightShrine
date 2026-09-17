#pragma once
#include <TSLib.h>
#include "ObjectBase.h"

// 雑魚敵を実装する
class LowEnemy final : public ObjectBase
{
public:
	LowEnemy(const Transform& _transform);
	~LowEnemy() = default;

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
	int clipIndex{ 0 }; // AnimationのClipIndex
#endif // _DEBUG

};