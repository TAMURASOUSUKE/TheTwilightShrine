#include "SceneFactory.h"

std::map< SceneType, std::function<std::unique_ptr<SceneBase>()>> SceneFactory::creationMap; // staticなメンバの実体

// 具体ヘッダをインクルード
#include "GameScene.h"
#include "TitleScene.h"

void SceneFactory::Initialize()
{
	creationMap[SceneType::Title] = []() { return std::make_unique<TitleScene>(); }; // タイトルシーン
	creationMap[SceneType::Game] = []() { return std::make_unique<GameScene>(); }; // ゲームシーン
}

std::unique_ptr<SceneBase> SceneFactory::CreateScene(SceneType _type)
{
	auto it{ creationMap.find(_type) };
	if (it != creationMap.end()) return it->second(); // 検索した結果の関数を呼び出す
	return nullptr;
}