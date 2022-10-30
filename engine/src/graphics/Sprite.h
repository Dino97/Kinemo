#pragma once

#include "math/Vec2.h"
#include "Texture2D.h"
#include "Shader.h"

namespace Kinemo
{
	class Sprite
	{
#if 0
	private:
		unsigned int m_VAO, m_VBO, m_IBO;
		Kinemo::Texture2D* m_Texture;

	public:
		Sprite(const char* spritePath, float x, float y, float width, float height);
		~Sprite();

		void Draw();
#else
	public:
		Sprite(float x, float y, float w, float h);
		Sprite(const Vec2& position, const Vec2& size);

		const Vec2& GetPosition() const { return m_Position; };
		const Vec2& GetSize() const { return m_Size; };

		void SetPosition(float x, float y) { m_Position.x = x; m_Position.y = y;}

	private:
		Vec2 m_Position;
		Vec2 m_Size;
#endif
	};
}