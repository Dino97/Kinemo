#pragma once

#include "Widget.h"
#include "graphics/Texture2D.h"
#include "graphics/Sprite.h"

namespace Kinemo
{
	class Shader;
}

namespace Kinemo { namespace GUI {

	class Texture : public Widget
	{
	private:
		Sprite m_Sprite;

	public:
		Texture(float x, float y, float width, float height, const char* path);
		~Texture();

		void Draw(const Shader& shader);
	};

}}