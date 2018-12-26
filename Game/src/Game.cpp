#include "Kinemo.h"
#include <iostream>

constexpr unsigned int SCREEN_WIDTH = 1280;
constexpr unsigned int SCREEN_HEIGHT = 720;

class Game : public Application
{
	using GUITexture = Kinemo::GUI::Texture;
	using Shader = Kinemo::Shader;
	using Mat4 = Kinemo::Math::Mat4;

private:
	GUITexture* btn;
	Shader* sh;
	Mat4 projection;
	
public:
	Game() : Application("Game", SCREEN_WIDTH, SCREEN_HEIGHT, false) {}

	void OnInit() override
	{
		Application::OnInit();
		
		btn = new GUITexture(10, SCREEN_HEIGHT - 10, 50, 50, "resources/textures/Button01.png");
		sh = new Shader("resources/shaders/SpriteShader.vert", "resources/shaders/SpriteShader.frag");
		projection = Mat4::Orthographic(0.0f, SCREEN_WIDTH, 0.0f, SCREEN_HEIGHT, -1.0f, 1.0f);

		sh->Bind();
		sh->SetUniformMat4("pr_matrix", projection);

		Kinemo::Log::Init();
	}

	void OnUpdate() override
	{
		btn->Draw(*sh);
	}
};

int main()
{
	Game game;
	game.Start();

	return 0;
}