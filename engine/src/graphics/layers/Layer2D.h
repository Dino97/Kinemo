#pragma once
#include "Layer.h"
#include "graphics/Sprite.h"
#include "graphics/Renderer2D.h"

#include <vector>
#include <memory>

namespace Kinemo
{
	class Layer2D : public Layer
	{
	public:
		Layer2D() {}

		void Add(Sprite* sprite) 
		{
			m_Sprites.push_back(sprite);
		}

	private:
		std::vector<Sprite*> m_Sprites;
		
	};
}