#include <format>
#include <string>
#include <algorithm>
#include "GameScene.h"

void GameScene::Initialize()
{
	camera.transform.SetPosition({0.0f, 0.0f, -80.0f});
	light.directional.direction = { 10.0f, -10.0f, 0.0f };

	player = Gfx::LoadModel("Res/3DModel/Player/Player.glb");
	lowEnemy = Gfx::LoadModel()
	playerInstance = Gfx::CreateAnimInstance(player);
	playerTransform.SetPosition(Vector3::Zero);
	Gfx::PlayAnim(playerInstance, playerClipIndex, true);
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

	if (playerInstance.IsValid())
	{
		if (Input::IsKeyPushed(KeyCode::Button::D1)) playerClipIndex--;
		if (Input::IsKeyPushed(KeyCode::Button::D2)) playerClipIndex++;
		playerClipIndex = std::max(0, playerClipIndex);
		if (Input::IsKeyPushed(KeyCode::Button::P)) Gfx::CrossFadeAnim(playerInstance, playerClipIndex, 0.5f, true);
		Gfx::UpdateAnim(playerInstance, Time::DeltaTime());
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
	Gfx::DrawAnimatedModel(playerInstance, playerTransform);

	std::string playerClipIndexStr{ std::format("PlayerClipIndex : {}", playerClipIndex)};
	Gfx::DrawString("GameScene", Vector2::Zero);
	Gfx::DrawString(playerClipIndexStr.c_str(), {0.0f, 20.0f});
}