#pragma once
#include "../Constant/GameConstant.h"

// オブジェクトに共通する処理をまとめたクラス
class ObjectBase
{
public:
	virtual ~ObjectBase() = default;

	// 更新
	virtual void Update() = 0;

	// 固定更新
	virtual void FixedUpdate() = 0;

	// 描画
	virtual void Draw() = 0;

	// オブジェクトのIDを返す
	ObjectID GetID() const { return ObjectID::None; }
};