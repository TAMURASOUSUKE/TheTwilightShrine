#include <TSLib.h>
#include "GameScene.h"

void GameScene::Initialize()
{
	DEBUG_LOG("GameSceneのInitializeを通りました!\n");
}

void GameScene::Update()
{
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
	DEBUG_LOG("GameSceneのTerminateを通りました!\n");
}

void GameScene::Draw()
{
	Gfx::DrawString("GameScene", Vector2::Zero);
}