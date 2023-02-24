#include "LResources.h"
namespace fnf
{
	std::map<eResourceKeys, Resource*>Resources::mResources;
	const std::vector<std::wstring> Resources::mResourcePaths
		= {L"Backgrounds\\Week1\\stage.bmp"};
}
