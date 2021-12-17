#version 330 core

layout (location = 0) in vec3 a_pos;
layout (location = 1) in vec2 a_texcoords;

out vec2 v2f_texcoords;

void main()
{
    gl_Position = vec4(a_pos, 1.0);
    v2f_texcoords = a_texcoords;
}