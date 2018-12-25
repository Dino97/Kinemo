#version 330 core

in vec2 TexCoords;

out vec4 FragColor;

uniform sampler2D spriteTexture;

void main()
{
	FragColor = texture(spriteTexture, vec2(TexCoords.x, 1.0 - TexCoords.y));
}