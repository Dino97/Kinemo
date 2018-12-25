#pragma once

#include "Kinemo.h"

class Player : public Kinemo::Events::IEventListener
{
private:

public:
	Player()
	{
		RegisterEventCallback(Player::OnButtonClicked);
	}

	void MoveLeft(float value)
	{

	}

	void MoveRight(float value)
	{

	}

	void OnButtonClicked(const Kinemo::Events::MouseButtonPressedEvent* eventData)
	{
		std::cout << "Button " << eventData->button << " pressed at:" << eventData->x << ", " << eventData->y << std::endl;
	}
};