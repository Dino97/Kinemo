#version 330 core

in vec2 TexCoords;
in vec4 Color;
in float TextureId;

out vec4 FragColor;

uniform sampler2D textures[32];

void main()
{
	int texId = int(TextureId);
	FragColor = texture(textures[texId], vec2(TexCoords.x, 1.0 - TexCoords.y));
	//FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
}