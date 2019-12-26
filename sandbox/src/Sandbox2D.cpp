#include "Sandbox2D.h"
#include <iostream>

using namespace Kinemo;

Sandbox2D::Sandbox2D()
{
	m_DebugName = "Sandbox2D";
}

Sandbox2D::~Sandbox2D()
{ }

void Sandbox2D::OnAttach()
{
	sp1 = new Sprite(10, 10, 64, 64);
	Add(sp1);

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			int id = i * 4 + j;
			tiles[id] = new Sprite(300 + j * 64, 300 + i * 64, 64, 64);
			Add(tiles[id]);
		}
	}

	shader = new Shader("resources/shaders/SpriteShader.vert", "resources/shaders/SpriteShader.frag");
	Math::Mat4 projection = Math::Mat4::Orthographic(0.0f, 1280, 0.0f, 720, -1.0f, 1.0f);

	shader->Bind();
	shader->SetUniform("pr_matrix", projection);

	texture = Texture2D::CreateFromFile("resources/textures/Spaceship.png");
}

void Sandbox2D::OnUpdate(float deltaTime)
{
	shader->Bind();
	texture->Bind();
	Layer2D::OnUpdate(deltaTime);

	if(Input::IsKeyDown(KEYCODE_A))
		sp1->SetPosition(pos -= deltaTime * shipSpeed, 10);

	if(Input::IsKeyDown(KEYCODE_D))
		sp1->SetPosition(pos += deltaTime * shipSpeed, 10);
}