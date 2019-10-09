#pragma once
#include "Kinemo.h"

class Sandbox2D : public Kinemo::Layer2D
{
public:
	Sandbox2D();
	~Sandbox2D();

	virtual void OnAttach() override;
	virtual void OnUpdate(float deltaTime) override;
	
private:

};