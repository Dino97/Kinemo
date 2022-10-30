#include "Texture2D.h"

#include <glad/glad.h>
#include "stb_image.h"

namespace Kinemo
{
	static constexpr int KinemoToOpenGLChannels(Texture2D::Channels channels)
	{
		return GL_RED + static_cast<int>(channels);
	}

	static constexpr int KinemoToOpenGLFilter(TextureFilter filter)
	{
		return GL_NEAREST + static_cast<int>(filter);
	}

	Texture2D::Texture2D(const char* path)
	{
		int channels;
		unsigned char* data = stbi_load(path, &m_Width, &m_Height, &channels, 0);

		glGenTextures(1, &m_Handle);
		glBindTexture(GL_TEXTURE_2D, m_Handle);

		glTexImage2D(GL_TEXTURE_2D, 0, channels == 3 ? GL_RGB : GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, KinemoToOpenGLFilter(TextureFilter::Nearest));
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, KinemoToOpenGLFilter(TextureFilter::Nearest));

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		stbi_image_free(data);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	Texture2D::Texture2D(int width, int height, Channels channels, unsigned char* data) :
		m_Width(width), m_Height(height)
	{
		glGenTextures(1, &m_Handle);
		glBindTexture(GL_TEXTURE_2D, m_Handle);

		auto format = KinemoToOpenGLChannels(channels);
		glTexImage2D(GL_TEXTURE_2D, 0, format, m_Width, m_Height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, KinemoToOpenGLFilter(TextureFilter::Nearest));
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, KinemoToOpenGLFilter(TextureFilter::Nearest));

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		glBindTexture(GL_TEXTURE_2D, 0);
	}

	Texture2D::~Texture2D()
	{
		glDeleteTextures(1, &m_Handle);
	}

	void Texture2D::Bind() const
	{
		glBindTexture(GL_TEXTURE_2D, m_Handle);
	}

	void Texture2D::Unbind() const
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void Texture2D::SetFilter(TextureFilter filter) const
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, KinemoToOpenGLFilter(filter));
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, KinemoToOpenGLFilter(filter));
	}
}