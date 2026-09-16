#include "TitleScene.h"
#include <TSLib.h>

void TitleScene::Initialize()
{
	DEBUG_LOG("TitleSceneのInitializeを通りました!\n");
}

void TitleScene::Update()
{
	if (!isUpdate)
	{
		DEBUG_LOG("TitleSceneのUpdateを通りました!\n");
		isUpdate = true;
	}
}

void TitleScene::FixedUpdate()
{
	if (!isFixedUpdate)
	{
		DEBUG_LOG("TitleSceneのFixedUpdateを通りました!\n");
		isFixedUpdate = true;
	}
}

void TitleScene::Terminate()
{
	DEBUG_LOG("TitleSceneのTerminateを通りました!\n");
}

void TitleScene::Draw()
{
	Gfx::DrawString("TitleScene", Vector2::Zero);
}