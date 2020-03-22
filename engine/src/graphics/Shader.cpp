#include "Shader.h"

#include <glad/glad.h>
#include <iostream>

#include "utils/FileUtilities.h"

namespace Kinemo
{
	Shader::Shader(const char* vertexPath, const char* fragmentPath)
	{
		std::string vertSrcString = FileUtilities::ReadFile(vertexPath);
		std::string fragSrcString = FileUtilities::ReadFile(fragmentPath);

		const char* vertexShaderSource = vertSrcString.c_str();
		const char* fragmentShaderSource = fragSrcString.c_str();

		// VERTEX SHADER
		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader);

		// check for shader compile errors
		int success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}

		// FRAGMENT SHADER
		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);

		// check for shader compile errors
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		}

		m_ShaderHandle = glCreateProgram();

		glAttachShader(m_ShaderHandle, vertexShader);
		glAttachShader(m_ShaderHandle, fragmentShader);
		glLinkProgram(m_ShaderHandle);

		// CHECK FOR LINK ERRORS
		glGetShaderiv(m_ShaderHandle, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(m_ShaderHandle, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	void Shader::Bind() const
	{
		glUseProgram(m_ShaderHandle);
	}

	void Shader::Unbind() const
	{
		glUseProgram(0);
	}

	void Shader::SetUniform(const char* uniformName, int value)
	{
		glUniform1i(glGetUniformLocation(m_ShaderHandle, uniformName), value);
	}

	void Shader::SetUniform(const char* uniformName, int count, const int* value)
	{
		glUniform1iv(glGetUniformLocation(m_ShaderHandle, uniformName), count, value);
	}

	void Shader::SetUniform(const char* uniformName, Kinemo::Math::Vec3 value)
	{
		glUniform3f(glGetUniformLocation(m_ShaderHandle, uniformName), value.x, value.y, value.z);
	}

	void Shader::SetUniform(const char* uniformName, Kinemo::Math::Mat4 mat4)
	{
		glUniformMatrix4fv(glGetUniformLocation(m_ShaderHandle, uniformName), 1, GL_FALSE, mat4.elements);
	}
}