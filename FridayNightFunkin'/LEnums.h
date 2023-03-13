#pragma once


enum class eSceneType
{
	Splash1,
	Splash2,
	Splash3,
	Splash4,
	Title,
	Campaign,
	Tutorial,
	Week1,
	Week2,
	Week3,
	GameOver,
	Size
};

enum class eLayerType
{
	BG,
	Player,
	Opponent,
	GameCanvas,
	Notes,
	Effect,
	UI,
	Size = 16,
};

enum class eComponentType
{
	Transform,
	SpriteRenderer,
	Animator,
	Collider,
	Audio,
	Size
};