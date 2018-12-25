#pragma once

#include "KinemoTypes.h"

namespace Kinemo {

	class Renderable2D
	{
	private:
		uint m_VAO, m_VBO;
	public:
		Renderable2D();

		void Draw();
	};
}