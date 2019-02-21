#include <iostream>

#include "Kinemo.h"
#include "Player.h"

constexpr unsigned int SCREEN_WIDTH = 1280;
constexpr unsigned int SCREEN_HEIGHT = 720;

class ForegroundLayer : public Kinemo::Layer
{
	void OnUpdate() override
	{

	}
};

class Game : public Kinemo::Application
{
	using GUITexture = Kinemo::GUI::Texture;
	using Shader = Kinemo::Shader;
	using Mat4 = Kinemo::Math::Mat4;

private:
	GUITexture* btn;
	Shader* sh;
	Mat4 projection;
	Mat4 model;
	Player player;
	Kinemo::Math::Vec3 pos;
	
public:
	Game() : Application("Game", SCREEN_WIDTH, SCREEN_HEIGHT, false) {}

	void OnInit() override
	{
		Application::OnInit();
		
		btn = new GUITexture(10, SCREEN_HEIGHT - 10, 50, 50, "resources/textures/Button01.png");
		sh = new Shader("resources/shaders/SpriteShader.vert", "resources/shaders/SpriteShader.frag");
		projection = Mat4::Orthographic(0.0f, SCREEN_WIDTH, 0.0f, SCREEN_HEIGHT, -1.0f, 1.0f);
		model = Mat4::Identity();

		sh->Bind();
		sh->SetUniformMat4("pr_matrix", projection);

		RegisterGameObject(&player);

		PushLayer(new ForegroundLayer());

		KM_INFO("Game initialised!");
	}

	void OnUpdate() override
	{
		btn->Draw(*sh);

		if (Kinemo::Input::IsKeyDown(65))
			pos.x -= 5;

		if (Kinemo::Input::IsKeyDown(68))
			pos.x += 5;

		if (Kinemo::Input::IsKeyDown(83))
			pos.y -= 5;

		if (Kinemo::Input::IsKeyDown(87))
			pos.y += 5;

		model = model.Translate(pos);
		sh->Bind();
		sh->SetUniformMat4("ml_matrix", model);

		GetWindow().SetTitle(std::to_string(GetFPS()));
	}
};

int main()
{
	Game game;
	game.Start();

	return 0;
}