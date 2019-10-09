#include "Texture2D.h"

#include <glad/glad.h>
#include "platform/opengl/GLTexture2D.h"

namespace Kinemo
{
	void Texture2D::SetMinFilter(Filter minFilter) const
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
	}

	void Texture2D::SetMagFilter(Filter magFilter) const
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, magFilter);
	}

	Texture2D* Texture2D::CreateFromFile(const char* path)
	{
		GLTexture2D* result = new GLTexture2D(path);

		return result;
	}
}