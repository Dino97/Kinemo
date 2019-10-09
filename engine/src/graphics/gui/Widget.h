#pragma once

#include "Core.h"
#include "math/Vec2.h"

namespace Kinemo { namespace GUI {

	class Widget
	{
	private:
		Math::Vec2 m_Position;
		Math::Vec2 m_Scale;

	public:
		Widget(float x, float y, float width, float height) :
			m_Position(x, y),
			m_Scale(width, height)
		{}

		//Widget(Rect rect);
	};

}} // namespace Kinemo::GUI