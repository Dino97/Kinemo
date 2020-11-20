#include "Renderer2D.h"
#include "Sprite.h"
#include "utils/Log.h"

#include <glad/glad.h>
#include <cstdint>
#include <cstring>
#include <array>

namespace Kinemo 
{
	static constexpr unsigned int MaxSprites 		= 10000;
	static constexpr unsigned int MaxVertexCount	= 4 * MaxSprites;
	static constexpr unsigned int MaxIndexCount		= 6 * MaxSprites;
	static constexpr unsigned int MaxTextures		= 32;

	struct RendererData
	{
		GLuint vao = 0;
		GLuint vbo = 0;
		GLuint ibo = 0;

		unsigned int indexCount = 0;

		Vertex* vertexBuffer;
		Vertex* vertexBufferPosition;

		GLuint whiteTexture;

		std::array<GLuint, MaxTextures> textureSlots;
		uint32_t nextTextureSlot = 1;

		Renderer2D::Stats stats;
	};

	static RendererData s_Data;

	void Renderer2D::Init()
	{
		s_Data.vertexBuffer = new Vertex[MaxVertexCount];

		glGenVertexArrays(1, &s_Data.vao);
		glGenBuffers(1, &s_Data.vbo);
		glGenBuffers(1, &s_Data.ibo);

		glBindVertexArray(s_Data.vao);
		
		glBindBuffer(GL_ARRAY_BUFFER, s_Data.vbo);
		glBufferData(GL_ARRAY_BUFFER, MaxVertexCount * sizeof(Vertex), nullptr, GL_DYNAMIC_DRAW);
		
		// Position
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)offsetof(Vertex, position));
		glEnableVertexAttribArray(0);

		// Texture coordinates
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)offsetof(Vertex, texCoords));
		glEnableVertexAttribArray(1);

		// Color
		glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)offsetof(Vertex, color));
		glEnableVertexAttribArray(2);

		// Texture index
		glVertexAttribPointer(3, 1, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)offsetof(Vertex, textureId));
		glEnableVertexAttribArray(3);

		uint16_t indices[MaxIndexCount];
		uint16_t offset = 0;

		for (int i = 0; i < MaxIndexCount; i += 6)
		{
			indices[i + 0] = 0 + offset;
			indices[i + 1] = 1 + offset;
			indices[i + 2] = 2 + offset;

			indices[i + 3] = 2 + offset;
			indices[i + 4] = 3 + offset;
			indices[i + 5] = 0 + offset;

			offset += 4;
		}

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, s_Data.ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glBindVertexArray(0);

		glGenTextures(1, &s_Data.whiteTexture);
		glBindTexture(GL_TEXTURE_2D, s_Data.whiteTexture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		uint32_t color = 0xFFFFFFFF;
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1, 1, 0, GL_RGB, GL_UNSIGNED_BYTE, &color);
		
		s_Data.textureSlots[0] = s_Data.whiteTexture;
		memset(&s_Data.textureSlots[0] + 1, 0, (s_Data.textureSlots.size() - 1) * sizeof(GLuint));

		int MaxTextureImageUnits;
		glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &MaxTextureImageUnits);

		KM_CORE_INFO("Max texture units: {0}", MaxTextureImageUnits);
	}

	void Renderer2D::Shutdown()
	{
		glDeleteVertexArrays(1, &s_Data.vao);
		glDeleteBuffers(1, &s_Data.vbo);
		glDeleteBuffers(1, &s_Data.ibo);

		glDeleteTextures(1, &s_Data.whiteTexture);

		delete[] s_Data.vertexBuffer;
	}

	void Renderer2D::Begin()
	{
		s_Data.vertexBufferPosition = s_Data.vertexBuffer;
	}

	void Renderer2D::Flush()
	{
		for (uint32_t i = 0; i < s_Data.nextTextureSlot; i++)
		{
			glActiveTexture(GL_TEXTURE0 + i);
			glBindTexture(GL_TEXTURE_2D, s_Data.textureSlots[i]);
		}

		glBindVertexArray(s_Data.vao);
		glDrawElements(GL_TRIANGLES, s_Data.indexCount, GL_UNSIGNED_SHORT, nullptr);

		s_Data.indexCount = 0;
		s_Data.stats.drawCalls++;
	}
	
	void Renderer2D::End()
	{
		GLsizeiptr bufferSize = (uint8_t*)s_Data.vertexBufferPosition - (uint8_t*)s_Data.vertexBuffer;
		glBindBuffer(GL_ARRAY_BUFFER, s_Data.vbo);
		glBufferSubData(GL_ARRAY_BUFFER, 0, bufferSize, s_Data.vertexBuffer);
	}

	void Renderer2D::DrawQuad(const Math::Vec3& position, const Math::Vec2& size, const Math::Vec4& color)
	{
		if (s_Data.indexCount >= MaxIndexCount)
		{
			End();
			Flush();
			Begin();
		}

		float textureId = 0.0f;

		// Bottom left
		s_Data.vertexBufferPosition->position = Math::Vec3(position.x, position.y, position.z);
		s_Data.vertexBufferPosition->texCoords = Math::Vec2(0.0f, 0.0f);
		s_Data.vertexBufferPosition->color = color;
		s_Data.vertexBufferPosition->textureId = textureId;
		s_Data.vertexBufferPosition++;

		// Bottom left
		s_Data.vertexBufferPosition->position = Math::Vec3(position.x + size.x, position.y, position.z);
		s_Data.vertexBufferPosition->texCoords = Math::Vec2(1.0f, 0.0f);
		s_Data.vertexBufferPosition->color = color;
		s_Data.vertexBufferPosition->textureId = textureId;
		s_Data.vertexBufferPosition++;

		// Bottom left
		s_Data.vertexBufferPosition->position = Math::Vec3(position.x + size.x, position.y + size.y, position.z);
		s_Data.vertexBufferPosition->texCoords = Math::Vec2(1.0f, 1.0f);
		s_Data.vertexBufferPosition->color = color;
		s_Data.vertexBufferPosition->textureId = textureId;
		s_Data.vertexBufferPosition++;

		// Bottom left
		s_Data.vertexBufferPosition->position = Math::Vec3(position.x, position.y + size.y, position.z);
		s_Data.vertexBufferPosition->texCoords = Math::Vec2(0.0f, 1.0f);
		s_Data.vertexBufferPosition->color = color;
		s_Data.vertexBufferPosition->textureId = textureId;
		s_Data.vertexBufferPosition++;

		s_Data.indexCount += 6;
		s_Data.stats.quads++;
	}

	void Renderer2D::DrawQuad(const Math::Vec3& position, const Math::Vec2& size, const Texture2D& texture)
	{
		if (s_Data.indexCount >= MaxIndexCount)
		{
			End();
			Flush();
			Begin();
		}

		float textureId = 0;
		GLuint handle = texture.GetHandle();
		for (uint32_t i = 0; i < s_Data.nextTextureSlot; i++)
		{
			if (s_Data.textureSlots[i] == handle)
			{
				textureId = handle;
				break;
			}
		}

		if (textureId == 0.0f)
		{
			textureId = handle;
			s_Data.textureSlots[s_Data.nextTextureSlot] = handle;
			s_Data.nextTextureSlot++;
		}

		Math::Vec4 color = {1.0f, 1.0f, 1.0f, 1.0f};

		// Bottom left
		s_Data.vertexBufferPosition->position = Math::Vec3(position.x, position.y, position.z);
		s_Data.vertexBufferPosition->texCoords = Math::Vec2(0.0f, 0.0f);
		s_Data.vertexBufferPosition->color = color;
		s_Data.vertexBufferPosition->textureId = textureId;
		s_Data.vertexBufferPosition++;

		// Bottom left
		s_Data.vertexBufferPosition->position = Math::Vec3(position.x + size.x, position.y, position.z);
		s_Data.vertexBufferPosition->texCoords = Math::Vec2(1.0f, 0.0f);
		s_Data.vertexBufferPosition->color = color;
		s_Data.vertexBufferPosition->textureId = textureId;
		s_Data.vertexBufferPosition++;

		// Bottom left
		s_Data.vertexBufferPosition->position = Math::Vec3(position.x + size.x, position.y + size.y, position.z);
		s_Data.vertexBufferPosition->texCoords = Math::Vec2(1.0f, 1.0f);
		s_Data.vertexBufferPosition->color = color;
		s_Data.vertexBufferPosition->textureId = textureId;
		s_Data.vertexBufferPosition++;

		// Bottom left
		s_Data.vertexBufferPosition->position = Math::Vec3(position.x, position.y + size.y, position.z);
		s_Data.vertexBufferPosition->texCoords = Math::Vec2(0.0f, 1.0f);
		s_Data.vertexBufferPosition->color = color;
		s_Data.vertexBufferPosition->textureId = textureId;
		s_Data.vertexBufferPosition++;

		s_Data.indexCount += 6;
		s_Data.stats.quads++;
	}

	const Renderer2D::Stats& Renderer2D::GetStats()
	{
		return s_Data.stats;
	}

	void Renderer2D::ResetStats()
	{
		s_Data.stats.drawCalls = 0;
		s_Data.stats.quads = 0;
	}
}