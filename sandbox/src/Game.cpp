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
	
public:
	Game() : Application("Game", SCREEN_WIDTH, SCREEN_HEIGHT, false) {}

	void OnInit() override
	{
		Application::OnInit();

		VFS::Mount("resources/textures", "textures");
		VFS::Mount("resources/shaders", "shaders");
		
		sh = new Shader("resources/shaders/SpriteShader.vert", "resources/shaders/SpriteShader.frag");
		model = Math::Mat4::Identity();

		PushLayer(new Sandbox2D());
		
		KM_INFO("Game initialised!");

		KM_INFO("360 degrees = {0} rads", 360.0 * Math::DegToRad);
	}

	void OnUpdate(float deltaTime) override
	{
		Application::OnUpdate(deltaTime);

		if (Input::IsKeyDown(KEYCODE_A))
			pos.x -= 5;

		if (Input::IsKeyDown(KEYCODE_D))
			pos.x += 5;

		if (Input::IsKeyDown(KEYCODE_S))
			pos.y -= 5;

		if (Input::IsKeyDown(KEYCODE_W))
			pos.y += 5;

		model = model.Translate(pos);
		sh->Bind();
		sh->SetUniform("ml_matrix", model);
	}
};

int main()
{
	Game game;
	game.Start();

	return 0;
}