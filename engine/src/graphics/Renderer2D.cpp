#include "Renderer2D.h"
#include "Sprite.h"
#include <glad/glad.h>

namespace Kinemo { namespace Graphics {

	constexpr unsigned int SPRITES_PER_BATCH = 50000;
	constexpr unsigned int SPRITE_SIZE		 = 4 * sizeof(VertexData);
	constexpr unsigned int BUFFER_SIZE		 = SPRITE_SIZE * SPRITES_PER_BATCH;
	constexpr unsigned int NUM_OF_INDICES	 = 6 * SPRITES_PER_BATCH;

	Renderer2D::Renderer2D()
		: submitedSpritesCount(0)
	{
		glGenVertexArrays(1, &m_VAO);
		glGenBuffers(1, &m_VBO);
		glGenBuffers(1, &m_IBO);

		glBindVertexArray(m_VAO);

		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
		glBufferData(GL_ARRAY_BUFFER, BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);

		// position
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(VertexData), (const void*)0);
		glEnableVertexAttribArray(0);

		// UVs
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(VertexData), (const void*)(offsetof(VertexData, uv)));
		glEnableVertexAttribArray(1);

		// index buffer
		unsigned short indices[NUM_OF_INDICES];

		for(int i = 0, offset = 0; i < NUM_OF_INDICES; i+=6, offset+=4)
		{
			indices[i + 0] = offset + 2;
			indices[i + 1] = offset + 1;
			indices[i + 2] = offset + 0;

			indices[i + 3] = offset + 2;
			indices[i + 4] = offset + 3;
			indices[i + 5] = offset + 1;
		}

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	}

	Renderer2D::~Renderer2D()
	{
		glDeleteVertexArrays(1, &m_VAO);
		glDeleteBuffers(1, &m_VBO);
		glDeleteBuffers(1, &m_IBO);
	}

	void Renderer2D::Begin()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
		m_Buffer = (VertexData*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
	}

	void Renderer2D::Submit(const Sprite& sprite)
	{
		const Math::Vec2& position = sprite.GetPosition();
		const Math::Vec2& size = sprite.GetSize();

		m_Buffer->position = position;
		m_Buffer->uv = Math::Vec2(0, 0);
		m_Buffer++;

		m_Buffer->position = Math::Vec2(position.x + size.x, position.y);
		m_Buffer->uv = Math::Vec2(1, 0);
		m_Buffer++;

		m_Buffer->position = Math::Vec2(position.x, position.y + size.y);
		m_Buffer->uv = Math::Vec2(0, 1);
		m_Buffer++;

		m_Buffer->position = Math::Vec2(position.x + size.x, position.y + size.y);
		m_Buffer->uv = Math::Vec2(1, 1);
		m_Buffer++;

		submitedSpritesCount++;
	}

	void Renderer2D::End()
	{
		glUnmapBuffer(GL_ARRAY_BUFFER);
	}

	void Renderer2D::Flush()
	{
		glBindVertexArray(m_VAO);
		glDrawElements(GL_TRIANGLES, submitedSpritesCount * 6, GL_UNSIGNED_SHORT, NULL);
		glBindVertexArray(0);
	}
}}