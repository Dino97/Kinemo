#pragma once

#include "Vec2.h"
#include "Vec3.h"
#include "Mat2.h"
#include "Mat4.h"

namespace Kinemo::Math
{
	constexpr float degToRad = M_PI / 180.0;
	constexpr float radToDeg = 180.0 / M_PI;
	
	template<typename T>
	constexpr T Clamp(const T& value, const T& min, const T& max)
	{
		return std::max(min, std::min(value, max));
	}

	template<typename T>
	constexpr T Clamp01(const T& value)
	{
		return Clamp(value, 0, 1);
	}
}
