#version 330 core

layout (location = 0) in vec2 position;
layout (location = 1) in vec2 texCoords;

out vec2 TexCoords;

uniform mat4 ml_matrix = mat4(1.0);
uniform mat4 vw_matrix = mat4(1.0);
uniform mat4 pr_matrix = mat4(1.0);

void main()
{
	gl_Position = pr_matrix * vw_matrix * ml_matrix * vec4(position, 0.0f, 1.0f);
	TexCoords = texCoords;
}