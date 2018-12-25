#include "Texture.h"

#include <glad/glad.h>
#include "graphics/Shader.h"

namespace Kinemo { namespace GUI {

	Texture::Texture(float x, float y, float width, float height, const char* path) :
		Widget(x, y, width, height), m_Sprite(path, x, y, width, height)
	{}

	Texture::~Texture()
	{}

	void Texture::Draw(const Shader& shader)
	{
		shader.Bind();
		m_Sprite.Draw();
		shader.Unbind();
	}

}}