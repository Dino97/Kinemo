#pragma once

#include "Component.h"
#include "math/Vec3.h"

class TransformComponent : public Component
{
	using Vec3 = Kinemo::Math::Vec3;

private:
	Vec3 m_Position, m_Rotation, m_Scale;

public:

	inline Vec3& GetPosition() { return m_Position; }
	inline Vec3& GetRotation() { return m_Rotation; }
	inline Vec3& GetScale() { return m_Scale; }
};