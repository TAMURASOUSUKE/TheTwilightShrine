#pragma once
#include "../Constant/SceneConstant.h"

// 各Sceneの基底クラスとなるクラス
class SceneBase
{
public:
	// デストラクタvirtualにする
	virtual ~SceneBase() = default;

	// シーンに入った際の処理
	virtual void Initialize() = 0;
	// シーン更新中の処理
	virtual void Update() = 0;
	// シーン中の固定更新
	virtual void FixedUpdate() = 0;
	// シーンを出るときの処理
	virtual void Terminate() = 0;

	// シーンを描画する処理
	virtual void Draw() = 0;

	// 自身のシーンの種類取得関数
	SceneType GetType() const { return type; }

protected:
	SceneType type{ SceneType::None };

};