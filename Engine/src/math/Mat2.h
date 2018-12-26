#pragma once

#include "Core.h"

namespace Kinemo { namespace Math {
	
	struct KINEMO_API Mat2
	{
		float elements[4];

		Mat2();
		Mat2(const float& diagonal);

		float Determinant();
	};

} }