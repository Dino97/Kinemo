#include "Application.h"

#include "utils/Timer.h"
#include "math/Mat4.h"
#include "math/Vec2.h"
#include "graphics/Texture2D.h"
#include "graphics/Shader.h"

#include <iostream>
#include <map>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "ft2build.h"
#include FT_FREETYPE_H

struct Character
{
	GLuint TextureID;
	Kinemo::Math::Vec2 Size;
	Kinemo::Math::Vec2 Bearing;
	GLuint Advance;
};

std::map<GLchar, Character> Characters;
GLuint VAO, VBO;

void RenderText(Kinemo::Shader& shader, std::string text, GLfloat x, GLfloat y, GLfloat scale, Kinemo::Math::Vec3 color);

Application::Application(const char* title, unsigned int width, unsigned int height, bool fullscreen)
{
	m_Window = new Window(title, width, height, fullscreen);
	m_Width = width;
	m_Height = height;
}

Application::~Application()
{
	delete m_Window;
}

void Application::OnInit()
{
	std::cout << glGetString(GL_RENDERER) << " " << glGetString(GL_VERSION) << std::endl;
}

void Application::OnUpdate()
{
	//m_CurrentScene.Update();
}

void Application::OnRender()
{

}

void Application::Start()
{
	using namespace Kinemo;
	using namespace Math;

	OnInit();

	Timer time;
	float timer = 0;


	/*
	Shader shader("../Game/resources/shaders/SpriteShader.vert", "../Game/resources/shaders/SpriteShader.frag");
	shader.Bind();

	//Mat4 projection = Mat4::Orthographic((int)m_Width / -2, (int)m_Width / 2, (int)m_Height / -2, (int)m_Height / 2, -1.0f, 1.0f);
	Mat4 projection = Mat4::Orthographic(0.0f, m_Width, 0.0f, m_Height, -1.0f, 1.0f);
	shader.SetUniformMat4("pr_matrix", projection);

	Shader sh("../Game/resources/shaders/TextShader.vert", "../Game/resources/shaders/TextShader.frag");
	sh.Bind();
	sh.SetUniformMat4("pr_matrix", projection);

	Mat4 view;

	FT_Library ft;
	if (FT_Init_FreeType(&ft))
		std::cout << "Could not init FreeType library!" << std::endl;

	FT_Face face;
	if(FT_New_Face(ft, "../Game/resources/fonts/arial.ttf", 0, &face))
		std::cout << "Failed to load font!" << std::endl;

	FT_Set_Pixel_Sizes(face, 0, 48);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	for (GLubyte c = 0; c < 128; c++)
	{
		if (FT_Load_Char(face, c, FT_LOAD_RENDER))
		{
			std::cout << "Failed to load glyph!" << std::endl;
			continue;
		}

		GLuint texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, face->glyph->bitmap.width, face->glyph->bitmap.rows, 0, GL_RED, GL_UNSIGNED_BYTE, face->glyph->bitmap.buffer);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		Character character = {
			texture,
			Vec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
			Vec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
			face->glyph->advance.x
		};
		Characters.insert(std::pair<GLchar, Character>(c, character));
	}
	glBindTexture(GL_TEXTURE_2D, 0);

	FT_Done_Face(face);
	FT_Done_FreeType(ft);

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 4, NULL, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (const void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	*/


	while (m_Window->WindowShouldRun())
	{
		m_Window->Clear();

		OnUpdate();

		// renderer.Begin() for batch render
		OnRender(); // only submit data here
		// renderer.End()

		// renderer.Flush()

		//RenderText(sh, "FPS: 3642", 25.0f, 25.0f, 0.5f, Vec3(0.5f, 0.8f, 0.2f));

		m_Window->SwapBuffers();

		m_FPS++;
		if (time.Elapsed() - timer > 1.0f)
		{
			timer += 1.0f;
			printf("%d fps\n", m_FPS);
			m_FPS = 0;
		}
	}
}

void RenderText(Kinemo::Shader& shader, std::string text, GLfloat x, GLfloat y, GLfloat scale, Kinemo::Math::Vec3 color)
{
	shader.Bind();
	shader.SetUniform3f("textColor", color);
	glActiveTexture(GL_TEXTURE0);
	glBindVertexArray(VAO);
	
	std::string::const_iterator c;
	for (c = text.begin(); c != text.end(); c++)
	{
		Character ch = Characters[*c];

		GLfloat xpos = x + ch.Bearing.x * scale;
		GLfloat ypos = y - (ch.Size.y - ch.Bearing.y) * scale;

		GLfloat w = ch.Size.x * scale;
		GLfloat h = ch.Size.y * scale;

		GLfloat vertices[6][4] = 
		{
			{ xpos,		ypos + h,	0.0, 0.0 },
			{ xpos,		ypos,		0.0, 1.0 },
			{ xpos + w,	ypos,		1.0, 1.0 },

			{ xpos,		ypos + h,	0.0, 0.0 },
			{ xpos + w,	ypos,		1.0, 1.0 },
			{ xpos + w,	ypos + h,	1.0, 0.0 }
		};

		glBindTexture(GL_TEXTURE_2D, ch.TextureID);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glDrawArrays(GL_TRIANGLES, 0, 6);

		x += (ch.Advance >> 6) * scale;
	}

	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}