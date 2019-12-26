#pragma once

namespace Kinemo { namespace Math {
	
	struct Mat2
	{
		float elements[4];

		Mat2();
		Mat2(const float& diagonal);

		float Determinant();
	};

} }