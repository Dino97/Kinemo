#include "Grid.h"

#include <glad/glad.h>

namespace Kinemo
{
	Grid::Grid(float xSize, float ySize, float width, float height)
		: m_CellSizeX(xSize), m_CellSizeY(ySize)
	{
		// SetSize(xSize, ySize, width, height);




		float verts[] =
		{
			100, 100, 0,
			-100, -100, 0
		};

		glGenVertexArrays(1, &m_VAO);
		glGenBuffers(1, &m_VBO);

		glBindVertexArray(m_VAO);

		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	void Grid::Draw()
	{
		glBindVertexArray(m_VAO);
		glDrawArrays(GL_LINES, 0, 2);
		glBindVertexArray(0);
	}
}