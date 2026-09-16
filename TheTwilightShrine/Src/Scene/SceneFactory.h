#pragma once
#include <memory>
#include <map>
#include <functional>
#include "../Constant/SceneConstant.h"
#include "SceneBase.h"

// シーン生成を行うファイル
class SceneFactory
{
public:
	// シーン生成を行う関数をmapに登録する
	static void Initialize();

	// 指定されたシーンを生成する
	static std::unique_ptr<SceneBase> CreateScene(SceneType _type);

private:
	static std::map< SceneType, std::function<std::unique_ptr<SceneBase>()>> creationMap; // タイプをキーに生成を行う関数を返すマップ
};