#pragma once

#include <ostream>
#include <cmath>

#include "Core.h"

namespace Kinemo { namespace Math {

	struct KINEMO_API Vec2
	{
		float x, y;

		Vec2();
		Vec2(const float& x, const float& y);

		//float Magnitude() const;
		//Vec2 Normalized() const;

		static Vec2 Lerp(const Vec2& vec1, const Vec2& vec2, float alpha);
		static float Distance(const Vec2& vec1, const Vec2& vec2);

		const Vec2& Add(const Vec2& other);
		const Vec2& Subtract(const Vec2& other);
		const Vec2& Multiply(const Vec2& other);
		const Vec2& Divide(const Vec2& other);

		friend Vec2 operator+(Vec2 left, const Vec2& right);
		friend Vec2 operator-(Vec2 left, const Vec2& right);
		friend Vec2 operator*(Vec2 left, const Vec2& right);
		friend Vec2 operator/(Vec2 left, const Vec2& right);

		Vec2& operator+=(const Vec2& other);
		Vec2& operator-=(const Vec2& other);
		Vec2& operator*=(const Vec2& other);
		Vec2& operator/=(const Vec2& other);

		bool operator==(const Vec2& other);
		bool operator!=(const Vec2& other);

		friend std::ostream& operator<<(std::ostream& stream, const Vec2& vector);
	};

}}