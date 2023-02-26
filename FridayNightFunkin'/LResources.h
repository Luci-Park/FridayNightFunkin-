#pragma once
#include "LResource.h"
namespace ci
{
	enum eResourceKeys
	{
		StageBackground, HauntedBackground, NightCityBackground, LimousineBackground,
		SIZE
	};
	class Resources
	{
	public:
		template<typename T>
		static T* Find(eResourceKeys key)
		{
			auto iter = mResources.find(key);
			if (iter != mResources.end())
			{
				return dynamic_cast<T*>(iter->second);
			}
			return nullptr;
		}

		template<typename T>
		static T* Load(eResourceKeys key)
		{
			T* resource = Resources::Find<T>(key);
			if (resource != nullptr)
			{
				return resource;
			}
			resource = new T();
			std::wstring path = mResourcePaths[(UINT)key];
			if (FAILED(resource->Load(path)))
			{
				assert(false);//에러 검출용 코드, 0일때 에러남.
				return nullptr;
			}
			mResources.insert(std::make_pair(key, resource));

			return dynamic_cast<T*>(resource);
		}
		
	private:
		static std::map<eResourceKeys, Resource*>mResources;
		const static std::wstring mResourcePaths[];
	};
}

