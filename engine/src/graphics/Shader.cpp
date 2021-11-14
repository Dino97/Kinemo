#include "Shader.h"

#include <glad/glad.h>
#include <iostream>

#include "utils/FileUtilities.h"

namespace Kinemo
{
	static void CompileShader(uint32_t shader, const std::string& source);

	template<typename ...Shaders>
	static void LinkProgram(uint32_t program, Shaders... shaders);

	Shader::Shader(const char* vertexPath, const char* fragmentPath)
	{
		std::string vertexSource = FileUtilities::ReadFile(vertexPath);
		std::string fragmentSource = FileUtilities::ReadFile(fragmentPath);

		uint32_t vertexShader = glCreateShader(GL_VERTEX_SHADER);
		uint32_t fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		CompileShader(vertexShader, vertexSource);
		CompileShader(fragmentShader, fragmentSource);

		m_Handle = glCreateProgram();
		LinkProgram(m_Handle, vertexShader, fragmentShader);

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_Handle);
	}

	void Shader::Bind() const
	{
		glUseProgram(m_Handle);
	}

	void Shader::Unbind() const
	{
		glUseProgram(0);
	}

	void Shader::SetUniform(const char* uniformName, int value)
	{
		glUniform1i(glGetUniformLocation(m_Handle, uniformName), value);
	}

	// used for loading samplers
	void Shader::SetUniform(const char* uniformName, int count, const int* value)
	{
		glUniform1iv(glGetUniformLocation(m_Handle, uniformName), count, value);
	}

	void Shader::SetUniform(const char* uniformName, const Math::Vec3& value)
	{
		glUniform3f(glGetUniformLocation(m_Handle, uniformName), value.x, value.y, value.z);
	}

	void Shader::SetUniform(const char* uniformName, const Math::Mat4& mat4)
	{
		glUniformMatrix4fv(glGetUniformLocation(m_Handle, uniformName), 1, GL_FALSE, mat4.elements);
	}

	// *** Helper functions ***
	static void CompileShader(uint32_t shader, const std::string& source)
	{
		const char* shaderSource = source.c_str();
		int success;
		char infoLog[512];

		glShaderSource(shader, 1, &shaderSource, 0);
		glCompileShader(shader);

		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 512, 0, infoLog);
			std::cerr << "ERROR::SHADER_COMPILATION_FAILED\n" << infoLog << std::endl;
		}
	}

	template<typename ...Shaders>
	static void LinkProgram(uint32_t program, Shaders... shaders)
	{
		int success;
		char infoLog[512];

		int dummy[sizeof...(Shaders)] = { (glAttachShader(program, shaders), 0)... };
		glLinkProgram(program);

		// Check for linking errors
		glGetShaderiv(program, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(program, 512, NULL, infoLog);
			std::cerr << "ERROR::SHADER_LINKING_FAILED\n" << infoLog << std::endl;
		}
	}
}