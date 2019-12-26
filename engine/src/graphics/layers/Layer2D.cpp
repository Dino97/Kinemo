#include "Layer2D.h"

#include <iostream>

namespace Kinemo { namespace Graphics {

	void Layer2D::OnUpdate(float deltaTime)
	{
		renderer.Begin();

		for(Sprite* s : m_Sprites)
			renderer.Submit(*s);

		renderer.End();
		renderer.Flush();
	}

	void Layer2D::Add(Sprite* sprite)
	{
		m_Sprites.push_back(sprite);
	}
}}