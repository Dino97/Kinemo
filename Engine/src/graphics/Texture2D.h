#pragma once

#include "Core.h"

namespace Kinemo
{
	enum Filter
	{
		NEAREST = 0x2600,
		LINEAR
	};

	class KINEMO_API Texture2D
	{
	protected:
		int m_Width, m_Height, m_Channels;

	public:
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		void SetMinFilter(Filter minFilter) const;
		void SetMagFilter(Filter magFilter) const;

		static Texture2D* CreateFromFile(const char* path);
	};
}