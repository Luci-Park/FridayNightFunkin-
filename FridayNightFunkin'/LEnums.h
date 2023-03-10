#pragma once
enum class eSceneType
{
	Splash,
	Title,
	Options,
	StoryMode,
	Tutorial,
	Week1,
	Week2,
	Week3,
	Week4,
	SIZE
};


enum class eLayerType
{
	Background,
	BackgroundCharacters,
	Player1,
	Player2,
	Notes,
	Particles,
	UI,
	SIZE = 16
};


enum class eComponentType
{
	Transform,
	SpriteRenderer,
	Animator,
	Collider,
	Audio,
	SIZE
};
