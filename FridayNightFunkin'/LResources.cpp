#include "LResources.h"
namespace ci
{
	std::map<eResourceKeys, Resource*>Resources::mResources;
	const std::wstring Resources::mResourcePaths[eResourceKeys::SIZE]
	= {
		L"Player\\Cadence.bmp",
		L"Backgrounds\\Week2\\tiles\\tiles001.bmp",
		L"Backgrounds\\Week3\\Pico Background 0.bmp",
		L"Backgrounds\\Week4\\Sunset.bmp",
	};
}
