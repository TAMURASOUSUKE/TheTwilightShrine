#pragma once
#include "SceneBase.h"

// 実際のタイトルシーンを作成する
class TitleScene final : public SceneBase
{
	TitleScene() = default;
	~TitleScene() = default;

	TitleScene(const TitleScene& _other) = delete;
	TitleScene& operator=(const TitleScene& _other) = delete;
};