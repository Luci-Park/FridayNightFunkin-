#pragma once
#include "LResource.h"
namespace fnf
{
	class Resources
	{
	public:
		template<typename T>
		static T* Find(const std::wstring& key)
		{
			std::map<std::wstring, Resource*>::iterator iter = mResources.find(key);
			if (iter != mResources.end())
			{
				return dynamic_cast<T*>(iter->second);
			}
			return nullptr;
		}

		template<typename T>
		static T* Load(const std::wstring& key, const std::wstring& path)
		{
			T* resource = Resources::Find<T>(key);
			if (resource != nullptr)
			{
				return resource;
			}
			resource = new T();
			if (FAILED(resource->Load(path)))
			{
				assert(false);//에러 검출용 코드, 0일때 에러남.
				return nullptr;
			}
			resource->SetKey(key);
			resource->SetPath(path);
			mResources.insert(std::make_pair(key, resource));

			return dynamic_cast<T*>(resource);
		}
	private:
		static std::map<std::wstring, Resource*>mResources;
	};
}

