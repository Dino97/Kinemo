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
	
public:
	Game() : Application("Game", SCREEN_WIDTH, SCREEN_HEIGHT, false) {}

	void OnInit() override
	{
		Application::OnInit();

		VFS::Mount("resources/textures", "textures");
		VFS::Mount("resources/shaders", "shaders");

		PushLayer(new Sandbox2D());

		Application::GetWindow().SetVSync(false);
		
		KM_INFO("Game initialised!");
	}
};

int main()
{
	Game game;
	game.Start();

	return 0;
}