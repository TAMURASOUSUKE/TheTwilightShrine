#pragma once
#include "SceneBase.h"

// 実際のタイトルシーンを作成する
class TitleScene final : public SceneBase
{
	TitleScene() = default;
	~TitleScene() = default;

	TitleScene(const TitleScene& _other) = delete;
	TitleScene& operator=(const TitleScene& _other) = delete;

	// シーンに入った際の処理
	void Initialize() override;
	// シーン更新中の処理
	void Update()override;
	// シーン中の固定更新
	void FixedUpdate()override;
	// シーンを出るときの処理
	void Terminate()override;

	// シーンを描画する処理
	void Draw() override;

	// 自身のシーンの種類取得関数 一旦Noneを返す
	SceneType GetType() const override { return SceneType::Title; }
	
private:

#ifdef _DEBUG
	bool isUpdate{ false }; // Update関数を通ったか
	bool isFixedUpdate{ false }; // FixedUpdate関数を通ったか
#endif // _DEBUG
};