#pragma once
#include <TSLib.h>

// Objectを生成するシステムを作成する
class ObjectFactory
{
public:
	ObjectFactory() = default;
	~ObjectFactory() = default;

	// Playerの生成
	static void CreatePlayer(const Transform& _transform);

	// 雑魚敵の生成
	static void CreateLowEnemy(const Transform& _transform);

	// ボスの生成
	static void CreateBoss(const Transform& _transform);
};