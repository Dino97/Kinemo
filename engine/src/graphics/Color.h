#pragma once

namespace Kinemo
{
	class Color
	{
	public:
		float r, g, b, a;

		Color(float red, float green, float blue, float alpha = 1.0f) :
			r(red),
			g(green),
			b(blue),
			a(alpha)
		{}

		static const Color Red;
		static const Color Green;
		static const Color Blue;
		static const Color White;
		static const Color Black;
	};
}