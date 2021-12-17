#version 330 core

in vec2 v2f_texcoords;

out vec4 color;

uniform sampler2D screenTexture;

void main()
{
    vec4 col = texture(screenTexture, v2f_texcoords);
    vec4 inverted_col = vec4(vec3(1.0) - col.xyz, 1.0);
    color = inverted_col;
}