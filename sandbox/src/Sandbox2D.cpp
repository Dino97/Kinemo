#include "Sandbox2D.h"
#include <iostream>

using namespace Kinemo;

Sandbox2D::Sandbox2D() :
	camera(Math::Mat4::Orthographic(0.0f, 1280.0f, 0.0f, 720.0f, -1.0f, 1.0f))
{
	m_DebugName = "Sandbox2D";
}

Sandbox2D::~Sandbox2D()
{ }

void Sandbox2D::OnAttach()
{
	//Add(sp1);
	background = new Sprite({-1.0, -1.0f}, {2.0f, 2.0f});
	//Add(background);

	shader = new Shader("resources/shaders/SpriteShader.vert", "resources/shaders/SpriteShader.frag");
	Math::Mat4 projection = Math::Mat4::Orthographic(0.0f, 1280, 0.0f, 720, -1.0f, 1.0f);

	shader->Bind();
	shader->SetUniform("pr_matrix", projection);

	int samplers[32];
	for (int i = 0; i < 32; i++)
		samplers[i] = i;
	shader->SetUniform("textures", 32, samplers);


	texture1 = Texture2D::CreateFromFile("resources/textures/BG.png");
	texture2 = Texture2D::CreateFromFile("resources/textures/Dirt01.png");

	Renderer2D::Init();
}

void Sandbox2D::OnUpdate(float deltaTime)
{
	cameraController.Update(deltaTime);

	shader->Bind();
	shader->SetUniform("vw_matrix", cameraController.GetCamera().GetView());

	Renderer2D::ResetStats();
	Renderer2D::Begin();

	float textureSize = 8;

	for (int i = 0; i < 1280 / textureSize; i++)
	{
		for (int j = 0; j < 720 / textureSize; j++)
		{
			//Renderer2D::DrawQuad({10.0f * i, 10.0f * j, 0.0f}, {8.0f, 8.0f}, {1.0f, 0.0f, 0.0f, 1.0f});

			if (i == j)
				Renderer2D::DrawQuad({textureSize * i, textureSize * j, 0.0f}, {textureSize, textureSize}, *((GLTexture2D*)texture1));
			else
				Renderer2D::DrawQuad({textureSize * i, textureSize * j, 0.0f}, {textureSize, textureSize}, *((GLTexture2D*)texture2));
		}
	}

	Renderer2D::End();
	Renderer2D::Flush();

	Layer2D::OnUpdate(deltaTime);
}