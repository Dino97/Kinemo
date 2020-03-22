#pragma once
#include "Kinemo.h"

using namespace Kinemo;

class Sandbox2D : public Graphics::Layer2D
{
public:
	Sandbox2D();
	~Sandbox2D();

	virtual void OnAttach() override;
	virtual void OnUpdate(float deltaTime) override;
	
private:
	OrthographicCameraController cameraController;

	Shader *shader;
	Texture2D *texture1, *texture2;
	Sprite *background;
};