#include "SceneManager.h"

void SceneManager::Register(const std::unique_ptr<SceneBase>& _scene)
{

}

bool  SceneManager::ChangeScene(SceneType _nextScene)
{

}

void SceneManager::Update()
{
	for (const std::unique_ptr<SceneBase>& scene : sceneBases)
	{
		if (currentScene != scene->GetType()) continue; // シーンが違えば動かさない
		scene->Update();
	}
}

void SceneManager::FixedUpdate()
{
	for (const std::unique_ptr<SceneBase>& scene : sceneBases)
	{
		if (currentScene != scene->GetType()) continue; // シーンが違えば動かさない
		scene->FixedUpdate();
	}
}

void SceneManager::Draw()
{
	for (const std::unique_ptr<SceneBase>& scene : sceneBases)
	{
		if (currentScene != scene->GetType()) continue; // シーンが違えば動かさない
		scene->Draw();
	}
}