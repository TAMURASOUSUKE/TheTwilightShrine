#pragma once

// Objectを生成するシステムを作成する
class ObjectFactory
{
public:
	ObjectFactory() = default;
	~ObjectFactory() = default;

	// Playerの生成
	static void CreatePlayer();

	// 雑魚敵の生成
	static void CreateLowEnemy();

	// ボスの生成
	static void CreateBoss();
};