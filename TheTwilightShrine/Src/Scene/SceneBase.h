#pragma once

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
	// シーンを出るときの処理
	virtual void Terminate() = 0;

	// シーンを描画する処理
	virtual void Draw() = 0;

};