#include "Sandbox2D.h"
#include <iostream>

Sandbox2D::Sandbox2D()
{ 
	m_DebugName = "Sandbox2D";
}

Sandbox2D::~Sandbox2D()
{ }

void Sandbox2D::OnAttach()
{
	std::cout << "Layer " << m_DebugName << " attached" << std::endl;

	//Kinemo::Sprite sprite1("/home/dino/Projects/Kinemo/sandbox/resources/textures/Dirt01.png", 0, 0, 32, 32);
	//Add(&sprite1);
}

void Sandbox2D::OnUpdate(float deltaTime)
{
	
}