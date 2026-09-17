#pragma once
#include <vector>
#include  <memory>
#include "../Constant/GameConstant.h"
#include "ObjectBase.h"

// 各オブジェクトを管理するファイル
class ObjectManager
{
public:
	~ObjectManager() = default;

	// シングルトンのインスタンスを取得する
	static ObjectManager& Instance()
	{
		static ObjectManager instance;
		return instance;
	}


	// 登録関数
	bool Register(std::unique_ptr<ObjectBase>  _object);

	// 登録したもの等をリセットする関数
	void Reset();

	// 全体の更新
	void  Update();

	// 全体の固定更新
	void FixedUpdate();

	// 全体の描画
	void Draw();

private:
	// シングルトンのためコンストラクタはprivate
	ObjectManager() = default;

private:
	std::vector<std::unique_ptr<ObjectBase>> objects{}; // 登録されたオブジェクト
	std::vector<std::unique_ptr<ObjectBase>> reservedObjects{}; // 登録予約されたオブジェクト

};