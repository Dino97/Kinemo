#include "Shader.h"

#include <glad/glad.h>
#include <iostream>

#include "utils/FileUtilities.h"

#if 1
	#define CHECK_SHADER_BINDING()    { int program; \
										glGetIntegerv(GL_CURRENT_PROGRAM, &program); \
										if (program != m_Handle) \
										std::cout << "WARNING: Shader is not bound." << std::endl; }
#else
	#define CHECK_SHADER_BINDING() 
#endif

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
		CHECK_SHADER_BINDING();
		glUniform1i(glGetUniformLocation(m_Handle, uniformName), value);
	}

	void Shader::SetUniform(const char* uniformName, float value)
	{
		CHECK_SHADER_BINDING();
		glUniform1f(glGetUniformLocation(m_Handle, uniformName), value);
	}

	// used for loading samplers
	void Shader::SetUniform(const char* uniformName, int count, const int* value)
	{
		CHECK_SHADER_BINDING();
		glUniform1iv(glGetUniformLocation(m_Handle, uniformName), count, value);
	}

	void Shader::SetUniform(const char* uniformName, const Vec3& value)
	{
		CHECK_SHADER_BINDING();
		glUniform3f(glGetUniformLocation(m_Handle, uniformName), value.x, value.y, value.z);
	}

	void Shader::SetUniform(const char* uniformName, const Mat4& mat4)
	{
		CHECK_SHADER_BINDING();
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
		glGetProgramiv(program, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(program, 512, NULL, infoLog);
			std::cerr << "ERROR::SHADER_LINKING_FAILED\n" << infoLog << std::endl;
		}
	}
}