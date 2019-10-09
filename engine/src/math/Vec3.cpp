#include "Vec3.h"
#include <cmath>

namespace Kinemo { namespace Math {

	Vec3::Vec3()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	Vec3::Vec3(const float& x, const float& y, const float& z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vec3 Vec3::Lerp(const Vec3& vec1, const Vec3& vec2, float alpha)
	{
		Vec3 result;

		// clamp alpha
		if (alpha > 1)
			alpha = 1;
		else if (alpha < 0)
			alpha = 0;

		result.x = vec1.x * (1 - alpha) + vec2.x * alpha;
		result.y = vec1.y * (1 - alpha) + vec2.y * alpha;
		result.z = vec1.z * (1 - alpha) + vec2.z * alpha;

		return result;
	}

	float Vec3::Distance(const Vec3& vec1, const Vec3& vec2)
	{
		Vec3 res = vec2 - vec1;

		return sqrt(res.x * res.x + res.y * res.y + res.z * res.z);
	}

	const Vec3& Vec3::Add(const Vec3& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	const Vec3& Vec3::Subtract(const Vec3& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}

	const Vec3& Vec3::Multiply(const Vec3& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		return *this;
	}

	const Vec3& Vec3::Divide(const Vec3& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
		return *this;
	}

	Vec3 operator+(Vec3 left, const Vec3& right)
	{
		return left.Add(right);
	}

	Vec3 operator-(Vec3 left, const Vec3& right)
	{
		return left.Subtract(right);
	}

	Vec3 operator*(Vec3 left, const Vec3& right)
	{
		return left.Multiply(right);
	}

	Vec3 operator/(Vec3 left, const Vec3& right)
	{
		return left.Divide(right);
	}

	Vec3& Vec3::operator+=(const Vec3& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	Vec3& Vec3::operator-=(const Vec3& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}

	Vec3& Vec3::operator*=(const Vec3& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		return *this;
	}

	Vec3& Vec3::operator/=(const Vec3& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
		return *this;
	}

	bool Vec3::operator==(const Vec3& other)
	{
		return x == other.x && y == other.y && z == other.z;
	}

	bool Vec3::operator!=(const Vec3& other)
	{
		return x != other.x && y != other.y && z != other.z;
	}

	std::ostream& operator<<(std::ostream& stream, const Vec3& vector)
	{
		stream << "vec3:( " << vector.x << ", " << vector.y << ", " << vector.z << ")";
		return stream;
	}

}}