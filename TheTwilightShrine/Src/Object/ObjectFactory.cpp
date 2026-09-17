#include <memory>
#include <utility>
#include "ObjectManager.h"
#include "ObjectFactory.h"

// ここから具体ヘッダをインクルード
#include "Player.h"
#include "LowEnemy.h"
#include "Boss.h"

void ObjectFactory::CreatePlayer(const Transform& _transform)
{
	std::unique_ptr<ObjectBase> player{ std::make_unique<Player>(_transform)}; // player生成

	// Managerに登録
	if (!ObjectManager::Instance().Register(std::move(player))) return; // 失敗したらそのまま返す
}

void ObjectFactory::CreateLowEnemy(const Transform& _transform)
{
	std::unique_ptr<ObjectBase> lowEnemy{ std::make_unique<LowEnemy>(_transform)}; // 雑魚敵生成

	// Managerに登録
	if (!ObjectManager::Instance().Register(std::move(lowEnemy))) return; // 失敗したらそのまま返す
}

void ObjectFactory::CreateBoss(const Transform& _transform)
{
	std::unique_ptr<ObjectBase> boss{ std::make_unique<Boss>(_transform)}; // boss生成
	
	// Managerに登録
	if (!ObjectManager::Instance().Register(std::move(boss))) return; // 失敗したらそのまま返す
}