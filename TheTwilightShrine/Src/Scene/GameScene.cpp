#include "../Object/ObjectManager.h"
#include "../Object/ObjectFactory.h"
#include "GameScene.h"

void GameScene::Initialize()
{
	CreateCharacter();
	DEBUG_LOG("GameSceneのInitializeを通りました!\n");
}

void GameScene::Update()
{
	ObjectManager::Instance().Update();

#ifdef _DEBUG
	if (!isUpdate)
	{
		DEBUG_LOG("GameSceneのUpdateを通りました!\n");
		isUpdate = true;
	}

#endif // _DEBUG
}

void GameScene::FixedUpdate()
{
	ObjectManager::Instance().FixedUpdate();

#ifdef _DEBUG
	if (!isFixedUpdate)
	{
		DEBUG_LOG("GameSceneのFixedUpdateを通りました!\n");
		isFixedUpdate = true;
	}
#endif // _DEBUG
}

void GameScene::Terminate()
{
	ObjectManager::Instance().Reset(); // 出るときには全て掃除
	DEBUG_LOG("GameSceneのTerminateを通りました!\n");
}

void GameScene::Draw()
{
	ObjectManager::Instance().Draw();
	Gfx::DrawString("GameScene", Vector2::Zero);
}

void GameScene::CreateCharacter()
{
	// 各トランスフォームの作成
	Transform playerTransform{};
	Transform lowEnemyTransform{};
	Transform bossTransform{};

	// 座標指定
	playerTransform.SetPosition({ -2.0f, 0.0f, 0.0f });
	lowEnemyTransform.SetPosition(Vector3::Zero);
	bossTransform.SetPosition({ 2.0f, 0.0f, 0.0f });

	// 実際の生成
	ObjectFactory::CreatePlayer(playerTransform);
	ObjectFactory::CreateLowEnemy(lowEnemyTransform);
	ObjectFactory::CreateBoss(bossTransform);
}