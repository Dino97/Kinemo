#pragma once

#include "KinemoTypes.h"

namespace Kinemo
{
	class Grid
	{
	private:
		float m_CellSizeX, m_CellSizeY;
		uint m_VAO, m_VBO;

	public:
		Grid(float xSize, float ySize, float width, float height);

		// Use dynamic array to store verts
		void SetSize(float xSize, float ySize, float width, float height);

		void Draw();
	};
}