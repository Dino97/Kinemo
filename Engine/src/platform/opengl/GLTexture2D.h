#pragma once

#include "Core.h"
#include "graphics/Texture2D.h"

namespace Kinemo {
	class KINEMO_API GLTexture2D : public Texture2D
	{
	private:
		unsigned int m_TextureHandle;

	public:
		GLTexture2D(const char* path);

		void Bind() const override;
		void Unbind() const override;
	};
}