#pragma once

#include "Component.h"
#include "graphics/Sprite.h"

class SpriteComponent : public Component
{
private:
	Kinemo::Sprite* m_Sprite;

public:

	void ComponentRender() override { m_Sprite->Draw(); }
};