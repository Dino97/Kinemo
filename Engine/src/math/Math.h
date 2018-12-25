#pragma once

#include "Vec2.h"
#include "Vec3.h"
#include "Mat2.h"
#include "Mat4.h"

namespace Kinemo { namespace Math {

	template<class T>
	T Clamp(T value, T min, T max)
	{
		return T > max ? max : value;
	}

}}
