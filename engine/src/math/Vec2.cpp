#include "Vec2.h"

namespace Kinemo { namespace Math {

	Vec2::Vec2()
	{
		x = 0.0f;
		y = 0.0f;
	}

	Vec2::Vec2(const float& x, const float& y)
	{
		this->x = x;
		this->y = y;
	}
	
	float Vec2::Magnitude() const
	{
		return sqrt(SqrMagnitude());
	}

	float Vec2::SqrMagnitude() const
	{
		return x * x + y * y;
	}

	Vec2 Vec2::Lerp(const Vec2& vec1, const Vec2& vec2, float alpha)
	{
		Vec2 result;

		if (alpha > 1)
			alpha = 1;
		else if (alpha < 0)
			alpha = 0;

		result.x = vec1.x * (1 - alpha) + vec2.x * alpha;
		result.y = vec1.y * (1 - alpha) + vec2.y * alpha;

		return result;
	}

	float Vec2::Distance(const Vec2& vec1, const Vec2& vec2)
	{
		Vec2 res = vec2 - vec1;
		return res.Magnitude();
	}

	const Vec2& Vec2::Add(const Vec2& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	const Vec2& Vec2::Subtract(const Vec2& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	const Vec2& Vec2::Multiply(const Vec2& other)
	{
		x *= other.x;
		y *= other.y;
		return *this;
	}

	const Vec2& Vec2::Divide(const Vec2& other)
	{
		x /= other.x;
		y /= other.y;
		return *this;
	}

	Vec2 operator+(Vec2 left, const Vec2& right)
	{
		return left.Add(right);
	}

	Vec2 operator-(Vec2 left, const Vec2& right)
	{
		return left.Subtract(right);
	}

	Vec2 operator*(Vec2 left, const Vec2& right)
	{
		return left.Multiply(right);
	}

	Vec2 operator/(Vec2 left, const Vec2& right)
	{
		return left.Divide(right);
	}

	Vec2& Vec2::operator+=(const Vec2& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	Vec2& Vec2::operator-=(const Vec2& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Vec2& Vec2::operator*=(const Vec2& other)
	{
		x *= other.x;
		y *= other.y;
		return *this;
	}

	Vec2& Vec2::operator/=(const Vec2& other)
	{
		x /= other.x;
		y /= other.y;
		return *this;
	}

	bool Vec2::operator==(const Vec2& other) const
	{
		return x == other.x && y == other.y;
	}

	bool Vec2::operator!=(const Vec2& other) const
	{
		return x != other.x && y != other.y;
	}

	std::ostream& operator<<(std::ostream& stream, const Vec2& vector)
	{
		stream << "vec2:( " << vector.x << ", " << vector.y << ")";
		return stream;
	}

}}