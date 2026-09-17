#pragma once
// ゲーム中に関係する定数や構造体、列挙体を定義する

// ObjectのID
enum class ObjectID
{
	None,
	Player,
	Enemy,
	Field
};

constexpr int PLAYER_START_ANIMATION_INDEX{ 1 }; // プレイヤーのIdleMotion
constexpr int LOWENEMY_START_ANIMATION_INDEX{ 2 }; // 雑魚敵のIdleMotion
constexpr int BOSS_START_ANIMATION_INDEX{ 2 }; // ボスのIdleMotion