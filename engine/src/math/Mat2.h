#pragma once

namespace Kinemo
{
	struct Mat2
	{
		float elements[4];

		Mat2();
		Mat2(const float& diagonal);

		float Determinant();
	};
}
