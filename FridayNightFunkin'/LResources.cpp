#include "LResources.h"
namespace fnf
{
	std::map<eResourceKeys, Resource*>Resources::mResources;
	const std::wstring Resources::mResourcePaths[eResourceKeys::SIZE]
	= {
		L"Backgrounds\\Week1\\stage.bmp",
		L"Backgrounds\\Week2\\tiles\\tiles001.bmp",
		L"Backgrounds\\Week3\\Pico Background 0.bmp",
		L"Backgrounds\\Week4\\Sunset.bmp",
	};
}
