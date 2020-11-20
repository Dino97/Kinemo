#pragma once

#include "graphics/Shader.h"
#include "math/Mat4.h"

namespace Kinemo 
{
	class Shader
	{
	public:
		Shader(const char* vertexPath, const char* fragmentPath);
		~Shader();

		Shader(const Shader&) = delete;
		Shader& operator=(const Shader&) = delete;

		Shader(Shader&&) = default;
		Shader& operator=(Shader&&) = default;

		void Bind() const;
		void Unbind() const;

		void SetUniform(const char* uniformName, int value);
		void SetUniform(const char* uniformName, int count, const int* value);
		void SetUniform(const char* uniformName, Kinemo::Math::Vec3 value);
		void SetUniform(const char* uniformName, Kinemo::Math::Mat4 mat4);

	private:
		unsigned int m_Handle;
	};
}