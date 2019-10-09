#pragma once

#include "math/Vec2.h"

namespace Kinemo 
{ 
	class Sprite;

	namespace Graphics {

		struct VertexData
		{
			Math::Vec2 position;
			Math::Vec2 uv;
		};

		class Renderer2D
		{
		public:
			Renderer2D();
			~Renderer2D();

			void Begin();
			void Submit(const Sprite& sprite);
			void End();
			void Flush();

		private:
			VertexData* m_Buffer;
			unsigned int m_VAO, m_VBO, m_IBO;
			unsigned int submitedSpritesCount;
		};
	}
}