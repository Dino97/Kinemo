#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoords;
layout (location = 2) in vec4 color;
layout (location = 3) in float textureId;

out vec2 TexCoords;
out vec4 Color;
out float TextureId;

uniform mat4 ml_matrix = mat4(1.0);
uniform mat4 vw_matrix = mat4(1.0);
uniform mat4 pr_matrix = mat4(1.0);

void main()
{
	gl_Position = pr_matrix * vw_matrix * ml_matrix * vec4(position.xyz, 1.0f);
	TexCoords = texCoords;
	Color = color;
	TextureId = textureId;
}