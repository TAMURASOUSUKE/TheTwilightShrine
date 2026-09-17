#include "ObjectManager.h"

bool ObjectManager::Register(std::unique_ptr<ObjectBase>  _object)
{
	if (!_object)return false;
 }

void ObjectManager::Reset()
{
	objects.clear();
	reservedObjects.clear();
}

void  ObjectManager::Update()
{
	for (const auto& object : objects)
	{
		// 死んでいる物は飛ばす
		if (!object->IsActive()) continue;
		object->Update();
	}
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