#include "Mat2.h"

namespace Kinemo
{
	Mat2::Mat2()
	{
		elements[0] = 0.0f;
		elements[1] = 0.0f;
		elements[2] = 0.0f;
		elements[3] = 0.0f;
	}

	Mat2::Mat2(const float& diagonal)
	{
		elements[0] = diagonal;
		elements[1] = 0.0f;
		elements[2] = 0.0f;
		elements[3] = diagonal;
	}

	float Mat2::Determinant()
	{
		return elements[0] * elements[3] - elements[1] * elements[2];
	}
}
