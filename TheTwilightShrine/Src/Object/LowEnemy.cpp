#include <format>
#include <TSLib.h>
#include "../Constant/GameConstant.h"
#include "LowEnemy.h"

LowEnemy::LowEnemy(const Transform& _transform) : transform{ _transform }, clipIndex{ LOWENEMY_START_ANIMATION_INDEX }
{
#ifdef _DEBUG
	handle = Gfx::LoadModel("Res/3DModel/Enemy/LowEnemy.glb");
	instance = Gfx::CreateAnimInstance(handle);
	Gfx::PlayAnim(instance, clipIndex, true);
#endif // _DEBUG
}

void LowEnemy::Update()
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

void LowEnemy::FixedUpdate()
{

}

void LowEnemy::Draw()
{
#ifdef _DEBUG
	Gfx::DrawAnimatedModel(instance, transform);

	std::string playerClipIndexStr{ std::format("LowEnemyClipIndex : {}", clipIndex) };
	Gfx::DrawString(playerClipIndexStr.c_str(), { 0.0f, 40.0f });
#endif // _DEBUG
}