#pragma once

#include "Core.h"
#include "graphics/Shader.h"
#include "math/Mat4.h"

namespace Kinemo {

	class Shader
	{
	private:
		unsigned int m_ShaderHandle;

	public:
		Shader(const char* vertexPath, const char* fragmentPath);

		void Bind() const;
		void Unbind() const;

		void SetUniformMat4(const char* uniformName, Kinemo::Math::Mat4 mat4);
		void SetUniform3f(const char* uniformName, Kinemo::Math::Vec3 value);
	};
}