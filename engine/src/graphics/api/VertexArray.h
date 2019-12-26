#pragma once

namespace Kinemo { namespace Graphics {

	class VertexArray
	{
	public:
		VertexArray();
		~VertexArray();

		void Bind() const;
		void Unbind() const;

	private:
		unsigned int m_Handle;
	};
}}