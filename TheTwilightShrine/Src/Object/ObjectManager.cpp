#include <utility>
#include <algorithm>
#include "ObjectManager.h"

bool ObjectManager::Register(std::unique_ptr<ObjectBase>  _object)
{
	if (!_object)return false;
	// 保留させる
	pendingObjects.emplace_back(std::move(_object)); 
	return  true;
 }

void ObjectManager::Reset()
{
	objects.clear();
	pendingObjects.clear();
}

void  ObjectManager::Update()
{
	for (const auto& object : objects)
	{
		// 死んでいる物は飛ばす
		if (!object->IsActive()) continue;
		object->Update();
	}

	// 死んでいるオブジェクトがあれば消す
	Destroy();

	// 全ての更新が終わった後に登録
	CommitPendingObjects();
}

void ObjectManager::FixedUpdate()
{
	for (const auto& object : objects)
	{
		// 死んでいる物は飛ばす
		if (!object->IsActive()) continue;
		object->FixedUpdate();
	}
}

void ObjectManager::Draw()
{
	for (const auto& object : objects)
	{
		// 死んでいる物は飛ばす
		if (!object->IsActive()) continue;
		object->Draw();
	}
}

void ObjectManager::CommitPendingObjects()
{
	for (auto& object : pendingObjects)
	{
		if (!object) continue; // 不正なものは弾く
		objects.emplace_back(std::move(object));
	}
	pendingObjects.clear(); // 何らかの理由で残った物は消す
}

void ObjectManager::Destroy()
{
	// 芯でいているオブジェクトを破棄
	std::erase_if(objects, [](const std::unique_ptr<ObjectBase>& _object) { return !_object->IsActive(); });
}