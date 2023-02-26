#pragma once
#include "LEntity.h"
namespace ci
{
	class Resource : public Entity
	{
	public:
		Resource();
		virtual ~Resource();
		
		virtual HRESULT Load(const std::wstring& path) = 0;

	private:
	};
}