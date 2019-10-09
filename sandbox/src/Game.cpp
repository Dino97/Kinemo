#include <iostream>

#include "Kinemo.h"
#include "Player.h"
#include "Sandbox2D.h"

using namespace Kinemo;

constexpr unsigned int SCREEN_WIDTH = 1280;
constexpr unsigned int SCREEN_HEIGHT = 720;

class Game : public Kinemo::Application
{
private:
	GUI::Texture* btn;
	Shader* sh;
	Math::Mat4 projection;
	Math::Mat4 model;
	Player player;
	Math::Vec3 pos;

	Graphics::Renderer2D renderer;
	Sprite *sp1, *sp2;
	Texture2D* tex;
	
public:
	Game() : Application("Game", SCREEN_WIDTH, SCREEN_HEIGHT, false) {}

	void OnInit() override
	{
		Application::OnInit();
		
		//btn = new GUI::Texture(10, SCREEN_HEIGHT - 10, 50, 50, "/home/dino/Projects/Kinemo/sandbox/resources/textures/Dirt01.png");
		sh = new Shader("/home/dino/Projects/Kinemo/sandbox/resources/shaders/SpriteShader.vert", "/home/dino/Projects/Kinemo/sandbox/resources/shaders/SpriteShader.frag");
		
		projection = Math::Mat4::Orthographic(0.0f, SCREEN_WIDTH, 0.0f, SCREEN_HEIGHT, -1.0f, 1.0f);
		model = Math::Mat4::Identity();

		sh->Bind();
		sh->SetUniformMat4("pr_matrix", projection);

		PushLayer(new Sandbox2D());

		KM_INFO("Game initialised!");

		sp1 = new Sprite(10, 10, 64, 64);
		sp2 = new Sprite(100, 40, 32, 64);
		sh->Bind();
		tex = Texture2D::CreateFromFile("/home/dino/Projects/Kinemo/sandbox/resources/textures/Dirt01.png");

		sh->Bind();
		tex->Bind();
	}

	void OnUpdate(float deltaTime) override
	{
		Application::OnUpdate(deltaTime);

		renderer.Begin();
		
		renderer.Submit(*sp1);
		renderer.Submit(*sp2);

		renderer.End();

		renderer.Flush();

		//btn->Draw(*sh);

		if (Input::IsKeyDown(65))
			pos.x -= 5;

		if (Input::IsKeyDown(68))
			pos.x += 5;

		if (Input::IsKeyDown(83))
			pos.y -= 5;

		if (Input::IsKeyDown(87))
			pos.y += 5;

		model = model.Translate(pos);
		sh->Bind();
		sh->SetUniformMat4("ml_matrix", model);
	}
};

int main()
{
	Game game;
	game.Start();

	return 0;
}