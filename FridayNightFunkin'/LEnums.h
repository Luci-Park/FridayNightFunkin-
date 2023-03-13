#pragma once


enum class eSceneType
{
	Title,
	Play,
	Ending,
	End,
};

enum class eLayerType
{
	BG,
	Monster,
	Player,
	Bullet,
	Test,
	Effect,
	UI,
	End = 16,
};

enum class eComponentType
{
	Transform,
	SpriteRenderer,
	Animator,
	Collider,
	Audio,
	End,
};