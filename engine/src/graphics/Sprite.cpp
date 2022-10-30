#include "Sprite.h"

#include <glad/glad.h>

namespace Kinemo
{
#if 0
	Sprite::Sprite(const char* spritePath, float x, float y, float width, float height)
	{
		float vertices[] =
		{
			// Position				UVs
			x, y, 0.0f,				0.0f, 1.0f,
			x + width, y, 0.0f,		1.0f, 1.0f,
			x, y - height, 0.0f,	0.0f, 0.0f,
			x + width, y - height,  0.0f,    1.0f, 0.0f
		};

		unsigned short indices[] =
		{
			0, 1, 2,
			1, 3, 2
		};

		glGenVertexArrays(1, &m_VAO);
		glGenBuffers(1, &m_VBO);
		glGenBuffers(1, &m_IBO);

		glBindVertexArray(m_VAO);

		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (const void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (const void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		glBindVertexArray(0);

		// Load the texture
		m_Texture = Texture2D::CreateFromFile(spritePath);
	}
	
	Sprite::~Sprite()
	{
		glDeleteBuffers(1, &m_VBO);
		glDeleteBuffers(1, &m_IBO);
		glDeleteVertexArrays(1, &m_VAO);
	}

	void Sprite::Draw()
	{
		m_Texture->Bind();
		glBindVertexArray(m_VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, NULL);
		glBindVertexArray(0);
		m_Texture->Unbind();
	}
#else
	Sprite::Sprite(float x, float y, float w, float h)
		: m_Position(x, y), m_Size(w, h)
	{}

	Sprite::Sprite(const Vec2& position, const Vec2& size)
		: m_Position(position), m_Size(size)
	{}
#endif
}