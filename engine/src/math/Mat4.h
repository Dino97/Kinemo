#pragma once

#include "Vec3.h"

namespace Kinemo { namespace Math {

	struct Mat4
	{
		float elements[16];

		Mat4();
		Mat4(float diagonal);

		static Mat4 Identity();

		static Mat4 Orthographic(float left, float right, float bottom, float top, float near, float far);
		static Mat4 Perspective(float fov, float aspectRatio, float near, float far);

		static Mat4 Translate(const Vec3& translation);
		static Mat4 Rotate(float angle, const Vec3& axis);
		static Mat4 Scale(const Vec3& scale);

		const Mat4& operator*(const Mat4& other);

		Mat4& Multiply(const Mat4& other);
	};
}}