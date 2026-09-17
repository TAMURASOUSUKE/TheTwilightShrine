#include <format>
#include <string>
#include <algorithm>
#include "GameScene.h"

void GameScene::Initialize()
{
#ifdef _DEBUG
	camera.transform.SetPosition({ 0.0f, 0.9f, -5.0f });
	Gfx::SetCamera(camera);
	light.directional.direction = { 10.0f, -10.0f, 0.0f };

	player = Gfx::LoadModel("Res/3DModel/Player/Player.glb");
	lowEnemy = Gfx::LoadModel("Res/3DModel/LowEnemy/LowEnemy.glb");
	boss = Gfx::LoadModel("Res/3DModel/Boss/Boss.glb");

	playerInstance = Gfx::CreateAnimInstance(player);
	lowEnemyInstance = Gfx::CreateAnimInstance(lowEnemy);
	bossInstance = Gfx::CreateAnimInstance(boss);

	playerTransform.SetPosition({ -2.0f, 0.0f, 0.0f });
	bossTransform.SetPosition(Vector3::Zero);
	lowEnemyTransform.SetPosition({2.0f, 0.0f, 0.0f});
		
	Gfx::PlayAnim(playerInstance, playerClipIndex, true);
	Gfx::PlayAnim(lowEnemyInstance, lowEnemyClipIndex, true);
	Gfx::PlayAnim(bossInstance, bossClipIndex, true);


#endif // _DEBUG
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
	if (lowEnemyInstance.IsValid())
	{
		if (Input::IsKeyPushed(KeyCode::Button::D3)) lowEnemyClipIndex--;
		if (Input::IsKeyPushed(KeyCode::Button::D4)) lowEnemyClipIndex++;
		lowEnemyClipIndex = std::max(0, lowEnemyClipIndex);
		if (Input::IsKeyPushed(KeyCode::Button::E)) Gfx::CrossFadeAnim(lowEnemyInstance, lowEnemyClipIndex, 0.5f, true);
		Gfx::UpdateAnim(lowEnemyInstance, Time::DeltaTime());
	}
	if (bossInstance.IsValid())
	{
		if (Input::IsKeyPushed(KeyCode::Button::D5)) bossClipIndex--;
		if (Input::IsKeyPushed(KeyCode::Button::D6)) bossClipIndex++;
		bossClipIndex = std::max(0, bossClipIndex);
		if (Input::IsKeyPushed(KeyCode::Button::B)) Gfx::CrossFadeAnim(bossInstance, bossClipIndex, 0.5f, true);
		Gfx::UpdateAnim(bossInstance, Time::DeltaTime());
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
#ifdef _DEBUG
	Gfx::DrawAnimatedModel(playerInstance, playerTransform);
	Gfx::DrawAnimatedModel(lowEnemyInstance, lowEnemyTransform);
	 Gfx::DrawAnimatedModel(bossInstance, bossTransform);

	std::string playerClipIndexStr{ std::format("PlayerClipIndex : {}", playerClipIndex) };
	std::string lowEnemyClipIndexStr{ std::format("LowEnemyClipIndex : {}", lowEnemyClipIndex) };
	std::string bossClipIndexStr{ std::format("BossClipIndex : {}", bossClipIndex) };
	Gfx::DrawString(playerClipIndexStr.c_str(), { 0.0f, 20.0f });
	Gfx::DrawString(lowEnemyClipIndexStr.c_str(), { 0.0f, 40.0f });
	Gfx::DrawString(bossClipIndexStr.c_str(), { 0.0f, 60.0f });
#endif // _DEBUG

	Gfx::DrawString("GameScene", Vector2::Zero);
}