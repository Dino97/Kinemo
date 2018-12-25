#include "GLTexture2D.h"

#include <glad/glad.h>
#include "utils/stb_image.h"

namespace Kinemo {
	GLTexture2D::GLTexture2D(const char* path)
	{
		unsigned char* data = stbi_load(path, &m_Width, &m_Height, &m_Channels, 0);

		glGenTextures(1, &m_TextureHandle);
		glBindTexture(GL_TEXTURE_2D, m_TextureHandle);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		stbi_image_free(data);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void GLTexture2D::Bind() const
	{
		glBindTexture(GL_TEXTURE_2D, m_TextureHandle);
	}

	void GLTexture2D::Unbind() const
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}