#pragma once
#include <TSLib.h>
#include "ObjectBase.h"

// 雑魚敵を実装する
class LowEnemy final : public ObjectBase
{
public:
	LowEnemy(const Transform& _transform);
	~LowEnemy();

	// 更新
	void Update() override;

	// 固定更新
	void FixedUpdate() override;

	// 描画
	void Draw() override;

	// IDのGetter
	ObjectID GetID() const  override { return ObjectID::Enemy; }

private:
	Transform transform{}; // 位置、回転、スケール
	int clipIndex{ 0 }; // AnimationのClipIndex

#ifdef _DEBUG
	ModelHandle handle{};
	AnimInstanceHandle instance{};
#endif // _DEBUG

};