#pragma once

#include <ostream>

namespace Kinemo
{
	struct Vec2;

	struct Vec3
	{
		float x, y, z;

		Vec3();
		Vec3(const float& x, const float& y, const float& z);
		Vec3(const Vec2& other);

		float Magnitude() const;
		float SqrMagnitude() const;
		
		Vec3 Normalized() const;

		static Vec3 Lerp(const Vec3& vec1, const Vec3& vec2, float alpha);
		static float Distance(const Vec3& vec1, const Vec3& vec2);

		const Vec3& Add(const Vec3& other);
		const Vec3& Subtract(const Vec3& other);
		const Vec3& Multiply(const Vec3& other);
		const Vec3& Divide(const Vec3& other);

		friend Vec3 operator+(Vec3 left, const Vec3& right);
		friend Vec3 operator-(Vec3 left, const Vec3& right);
		friend Vec3 operator*(Vec3 left, const Vec3& right);
		friend Vec3 operator/(Vec3 left, const Vec3& right);

		Vec3 operator-() const;

		Vec3& operator+=(const Vec3& other);
		Vec3& operator-=(const Vec3& other);
		Vec3& operator*=(const Vec3& other);
		Vec3& operator/=(const Vec3& other);

		bool operator==(const Vec3& other) const;
		bool operator!=(const Vec3& other) const;

		friend std::ostream& operator<<(std::ostream& stream, const Vec3& vector);
	};
}
