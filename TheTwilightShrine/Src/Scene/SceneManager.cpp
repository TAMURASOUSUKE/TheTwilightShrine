#include <TSLib.h>
#include "SceneManager.h"

bool  SceneManager::ChangeScene(SceneType _nextScene)
{
	if (_nextScene == currentScene) return false; // 同じシーンの時は処理をしない

	scene->Terminate(); // シーンを出るときの処理を行う

	currentScene = _nextScene; // 新しいシーンにする

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