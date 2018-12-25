#include "Renderable2D.h"

#include <glad/glad.h>

namespace Kinemo {

	Renderable2D::Renderable2D()
	{
		float vertices[] =
		{
			-0.5f,  0.5f, 0.0f,		 0.0f, 1.0f,
			 0.5f,  0.5f, 0.0f,		 1.0f, 1.0f,
			 0.5f, -0.5f, 0.0f,		 1.0f, 0.0f,

			 0.5f, -0.5f, 0.0f,		 1.0f, 0.0f,
			-0.5f, -0.5f, 0.0f,		 0.0f, 0.0f,
			-0.5f,  0.5f, 0.0f,		 0.0f, 1.0f
		};

		glGenVertexArrays(1, &m_VAO);
		glGenBuffers(1, &m_VBO);

		glBindVertexArray(m_VAO);

		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (const GLvoid*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (const GLvoid*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	void Renderable2D::Draw()
	{
		glBindVertexArray(m_VAO);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);
	}
}