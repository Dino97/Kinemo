#include "Mat4.h"

#include <cstring>

namespace Kinemo { namespace Math {

	Mat4::Mat4()
	{
		for (int i = 0; i < 16; i++)
			elements[i] = 0.0f;
	}

	Mat4::Mat4(float diagonal)
	{
		for (int i = 0; i < 16; i++)
			elements[i] = 0.0f;

		elements[0] = diagonal;
		elements[5] = diagonal;
		elements[10] = diagonal;
		elements[15] = diagonal;
	}

	Mat4 Mat4::Identity()
	{
		return Mat4(1.0f);
	}

	Mat4 Mat4::Orthographic(float left, float right, float bottom, float top, float near, float far)
	{
		Mat4 result;

		result.elements[0] = 2.0f / (right - left);
		result.elements[5] = 2.0f / (top - bottom);
		result.elements[10] = 2.0f / (near - far);
		result.elements[15] = 1.0f;

		result.elements[12] = (left + right) / (left - right);
		result.elements[13] = (bottom + top) / (bottom - top);
		result.elements[14] = (near + far) / (near - far);

		return result;
	}

	Mat4 Mat4::Perspective(float fov, float aspectRatio, float near, float far)
	{
		Mat4 result;

		float t = tan(0.5f * fov);

		result.elements[0] = 1 / (aspectRatio * t);
		result.elements[5] = 1 / t;
		result.elements[10] = (far + near) / (near - far);
		result.elements[11] = -1.0f;
		result.elements[14] = (2.0f * far * near) / (near - far);

		return result;
	}

	Mat4 Mat4::Translate(const Vec3& translation)
	{
		Mat4 result(1.0f);

		result.elements[12] = translation.x;
		result.elements[13] = translation.y;
		result.elements[14] = translation.z;

		return result;
	}

	Mat4 Mat4::Rotate(float angle, const Vec3& axis)
	{
		Mat4 result(1.0f);

		float r = angle * (M_PI / 180);
		float c = cos(r);
		float s = sin(r);
		float omc = 1.0f - c;

		float x = axis.x;
		float y = axis.y;
		float z = axis.z;

		result.elements[0 + 0 * 4] = x * x * omc + c;
		result.elements[1 + 0 * 4] = y * x * omc + z * s;
		result.elements[2 + 0 * 4] = x * z * omc - y * s;

		result.elements[0 + 1 * 4] = x * y * omc - z * s;
		result.elements[1 + 1 * 4] = y * y * omc + c;
		result.elements[2 + 1 * 4] = y * z * omc + x * s;
						
		result.elements[0 + 2 * 4] = x * z * omc + y * s;
		result.elements[1 + 2 * 4] = y * z * omc - x * s;
		result.elements[2 + 2 * 4] = z * z * omc + c;


		return result;
	}

	Mat4 Mat4::Scale(const Vec3& scale)
	{
		Mat4 result(1.0f);

		result.elements[0] = scale.x;
		result.elements[5] = scale.y;
		result.elements[10] = scale.z;

		return result;
	}

	Mat4& Mat4::Multiply(const Mat4& other)
	{
		float data[16];
		for (int y = 0; y < 4; ++y)
		{
			for (int x = 0; x < 4; ++x)
			{
				float sum = 0.0f;

				for (int e = 0; e < 4; ++e)
				{
					sum += elements[x + e * 4] * other.elements[e + y * 4];
				}
				data[x + y * 4] = sum;
			}
		}
		memcpy(elements, data, 16 * sizeof(float));

		return *this;
	}
}}