#include <TSLib.h>
#include "SceneFactory.h"
#include "SceneManager.h"

SceneManager::SceneManager()
{
	SceneFactory::Initialize(); // シーン生成関数登録
}

bool  SceneManager::ChangeScene(SceneType _nextScene)
{
	if (_nextScene == currentScene) return false; // 同じシーンの時は処理をしない

	if(currentScene != SceneType::None) scene->Terminate(); // シーンを出るときの処理を行う(最初のシーン設定時にTerminateが走らないようにする)

	scene = SceneFactory::CreateScene(_nextScene); // 新しいシーンを生成
	currentScene = scene->GetType(); // シーンタイプを更新する

	scene->Initialize(); // シーンに入るの処理を行う
	
	DEBUG_LOG("シーンの切り替えに成功しました\n");
	return true;
}

void SceneManager::Update()
{
	if (!scene) return;
	scene->Update();
}

void SceneManager::FixedUpdate()
{
	if (!scene) return;
	scene->FixedUpdate();
}

void SceneManager::Draw()
{
	if (!scene) return;
	scene->Draw();
}