#include "VertexArray.h"

#include <glad/glad.h>

namespace Kinemo { namespace Graphics {

	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &m_Handle);
	}

	VertexArray::~VertexArray()
	{
		glDeleteVertexArrays(1, &m_Handle);
	}

	void VertexArray::Bind() const 
	{
		glBindVertexArray(m_Handle);	
	}

	void VertexArray::Unbind() const 
	{
		glBindVertexArray(0);
	}
}}