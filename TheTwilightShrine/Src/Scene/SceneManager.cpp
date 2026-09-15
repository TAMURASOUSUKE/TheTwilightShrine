#include <TSLib.h>
#include "SceneManager.h"

bool SceneManager::Register(const std::unique_ptr<SceneBase>& _scene)
{
	if (!_scene)
	{
		DEBUG_LOG_ERROR("シーンの登録に失敗しました\n");
		return false;
	}
	scenes.push_back(std::move(_scene)); // シーンを登録
	return true;
}

bool  SceneManager::ChangeScene(SceneType _nextScene)
{
	if (_nextScene == currentScene) return false; // 同じシーンの時は処理をしない

	for (const std::unique_ptr<SceneBase>& scene : scenes)
	{
		if (currentScene != scene->GetType()) continue; // シーンが違えば動かさない
		scene->Terminate(); // シーンを出るときの処理を行う
	}

	currentScene = _nextScene; // 新しいシーンにする

	for (const std::unique_ptr<SceneBase>& scene : scenes)
	{
		if (currentScene != scene->GetType()) continue; // シーンが違えば動かさない
		scene->Initialize(); // シーンに入るの処理を行う
	}

	DEBUG_LOG("シーンの切り替えに成功しました\n");
	return true;
}

void SceneManager::Update()
{
	for (const std::unique_ptr<SceneBase>& scene : scenes)
	{
		if (currentScene != scene->GetType()) continue; // シーンが違えば動かさない
		scene->Update();
	}
}

void SceneManager::FixedUpdate()
{
	for (const std::unique_ptr<SceneBase>& scene : scenes)
	{
		if (currentScene != scene->GetType()) continue; // シーンが違えば動かさない
		scene->FixedUpdate();
	}
}

void SceneManager::Draw()
{
	for (const std::unique_ptr<SceneBase>& scene : scenes)
	{
		if (currentScene != scene->GetType()) continue; // シーンが違えば動かさない
		scene->Draw();
	}
}