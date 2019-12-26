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
	Sprite *sp1;
	Shader *shader;
	Texture2D *texture;
	Sprite *tiles[16];

	float pos = 0.0f;
	float shipSpeed = 500.0f;
};