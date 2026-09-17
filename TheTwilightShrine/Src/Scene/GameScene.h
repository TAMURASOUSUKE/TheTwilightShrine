#pragma once
#include <TSLib.h>
#include "SceneBase.h"

// 実際のゲームシーンを作成する
class GameScene final : public SceneBase
{
public:
	GameScene() = default;
	~GameScene() = default;

	GameScene(const GameScene& _other) = delete;
	GameScene& operator=(const GameScene& _other) = delete;

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
	SceneType GetType() const override { return SceneType::Game; }

private:
	// シーン内のキャラクター作成をFactoryに依頼する
	void CreateCharacter();

private:

#ifdef _DEBUG
	bool isUpdate{ false }; // Update関数を通ったか
	bool isFixedUpdate{ false }; // FixedUpdate関数を通ったか

	Camera camera{};
	SceneLight light{};

#endif // _DEBUG

};