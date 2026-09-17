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

#ifdef _DEBUG
	bool isUpdate{ false }; // Update関数を通ったか
	bool isFixedUpdate{ false }; // FixedUpdate関数を通ったか

	Camera camera{};
	SceneLight light{};

	// モデル動作テスト(本来はResourceManagerの役目)
	ModelHandle player{};
	ModelHandle lowEnemy{};
	ModelHandle boss{};
	AnimInstanceHandle playerInstance{};
	AnimInstanceHandle lowEnemyInstance{};
	AnimInstanceHandle bossInstance{};
	Transform playerTransform{};
	Transform lowEnemyTransform{};
	Transform bossTransform{};
	int playerClipIndex{ 0 }; // PlayerのClipIndex
	int lowEnemyClipIndex{ 0 }; // 雑魚敵のClipIndex
	int bossClipIndex{ 0 }; // ボスのClipIndex

#endif // _DEBUG

};