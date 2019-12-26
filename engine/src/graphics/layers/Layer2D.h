#pragma once
#include "Layer.h"
#include "graphics/Sprite.h"
#include "graphics/Renderer2D.h"

#include <vector>
#include <memory>

namespace Kinemo { namespace Graphics {

	class Layer2D : public Layer
	{
	public:
		virtual void OnUpdate(float deltaTime) override;

		void Add(Sprite* sprite);

	private:
		Renderer2D renderer;
		std::vector<Sprite*> m_Sprites;
	};
}}