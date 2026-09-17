#include <format>
#include <TSLib.h>
#include "../Constant/GameConstant.h"
#include "Player.h"

Player::Player(const Transform& _transform) : transform{ _transform }, clipIndex{PLAYER_START_ANIMATION_INDEX}
{
#ifdef _DEBUG
	handle = Gfx::LoadModel("Res/3DModel/Player/Player.glb");
	instance = Gfx::CreateAnimInstance(handle);
	Gfx::PlayAnim(instance, clipIndex, true);
#endif // _DEBUG
}

Player::~Player()
{
#ifdef _DEBUG
	Gfx::DestroyAnim(instance);
	Gfx::Unload(handle);
#endif // _DEBUG
}

void Player::Update()
{
#ifdef _DEBUG
	if (instance.IsValid())
	{
		if (Input::IsKeyPushed(KeyCode::Button::D1)) clipIndex--;
		if (Input::IsKeyPushed(KeyCode::Button::D2)) clipIndex++;
		clipIndex = std::max(0, clipIndex);
		if (Input::IsKeyPushed(KeyCode::Button::P)) Gfx::CrossFadeAnim(instance, clipIndex, 0.2f, true);
		Gfx::UpdateAnim(instance, Time::DeltaTime());
	}
#endif // _DEBUG
}

void Player::FixedUpdate()
{

}

void Player::Draw()
{
#ifdef _DEBUG
	Gfx::DrawAnimatedModel(instance, transform);

	std::string playerClipIndexStr{ std::format("PlayerClipIndex : {}", clipIndex) };
	Gfx::DrawString(playerClipIndexStr.c_str(), { 0.0f, 20.0f });
#endif // _DEBUG
}
