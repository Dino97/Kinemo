#pragma once

#include <KinemoTypes.h>
#include "Texture2D.h"
#include "Shader.h"

namespace Kinemo
{
	class Sprite
	{
	private:
		uint m_VAO, m_VBO, m_IBO;
		Kinemo::Texture2D* m_Texture;

	public:
		Sprite(const char* spritePath, float x, float y, float width, float height);
		~Sprite();

		void Draw();
	};
}