#pragma once
#include "../Constant/GameConstant.h"

// オブジェクトに共通する処理をまとめたクラス
class ObjectBase
{
public:
	virtual ~ObjectBase() = default;

	// 更新
	virtual void Update() = 0;

	// 固定更新(固定更新が必要ないモデル類は空関数となる)
	virtual void FixedUpdate(){}

	// 描画
	virtual void Draw() = 0;

	// オブジェクトのIDを返す
	virtual ObjectID GetID() const { return ObjectID::None; }

	// 生存しているかを取得
	bool IsActive() { return  isActive; }

protected:
	bool isActive{ false }; // 生存してるか

};