#include <memory>
#include <utility>
#include <TSLib.h>
#include "ObjectManager.h"
#include "ObjectFactory.h"

// ここから具体ヘッダをインクルード
#include "Player.h"
#include "LowEnemy.h"
#include "Boss.h"

void ObjectFactory::CreatePlayer()
{
	std::unique_ptr<ObjectBase> player{ std::make_unique<Player()>(const Transform & _transform)}; // player生成
	ObjectManager::Instance().Register(std::move(player)); // Managerに登録
}

void ObjectFactory::CreateLowEnemy()
{
	std::unique_ptr<ObjectBase> lowEnemy{ std::make_unique<LowEnemy(const Transform & _transform)>()}; // 雑魚敵生成
	ObjectManager::Instance().Register(std::move(lowEnemy)); // Managerに登録
}

void ObjectFactory::CreateBoss()
{
	std::unique_ptr<ObjectBase> boss{ std::make_unique<Boss(const Transform & _transform)>()}; // boss生成
	ObjectManager::Instance().Register(std::move(boss)); // Managerに登録
}