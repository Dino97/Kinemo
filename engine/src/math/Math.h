#pragma once

#include "Vec2.h"
#include "Vec3.h"
#include "Mat2.h"
#include "Mat4.h"

namespace Kinemo { namespace Math {

	template<class T>
	T Clamp(const T& value, const T& min, const T& max)
	{
		return std::max(min, std::min(value, max));
	}
}}
