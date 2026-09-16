#include <utility>
#include <TSLib.h>
#include "SceneFactory.h"
#include "SceneManager.h"

SceneManager::SceneManager()
{
	SceneFactory::Initialize(); // シーン生成関数登録
}

void SceneManager::Shutdown()
{
	if (scene) scene->Terminate(); // 終わるときもシーンを出る処理
	scene.reset();
	currentScene = SceneType::None;
	pendingScene = SceneType::None;
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

bool  SceneManager::RequestSceneChange(SceneType _nextScene)
{
	if (_nextScene == SceneType::None) return false; 
	if (_nextScene == currentScene) return false; // 自分のシーンと同じなら要求を作らない

	// 最初の予約を優先する
	if (pendingScene != SceneType::None) return false; // None以外なら予約が入っている

	pendingScene = _nextScene; // 次のシーンを予約
	return true;
}

void SceneManager::ApplyPendingSceneChange()
{
	if (pendingScene == SceneType::None) return;

	SceneType next{ pendingScene }; // 先に遷移先を取り出して空にしてからチェンジする これによりInitializeで遷移が呼ばれても消されないようにする
	pendingScene = SceneType::None; 

	ChangeScene(next);
}


bool  SceneManager::ChangeScene(SceneType _nextScene)
{
	if (_nextScene == SceneType::None) return false;
	if (_nextScene == currentScene) return false; // 同じシーンの時は処理をしない

	// 生成に失敗しても現在のシーンを残せるように先に生成する
	auto nextScene{ SceneFactory::CreateScene(_nextScene) };
	if (!nextScene)
	{
		DEBUG_LOG_ERROR("シーンの生成に失敗しました\n");
		return false;
	}

	if (scene) scene->Terminate(); // シーンを出るときの処理を行う

	// ここで所有権を移して旧シーンを破棄
	scene = std::move(nextScene);
	currentScene = scene->GetType(); // シーンタイプを更新する

	scene->Initialize(); // シーンに入るの処理を行う

	DEBUG_LOG("シーンの切り替えに成功しました\n");
	return true;
}