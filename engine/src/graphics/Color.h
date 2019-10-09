#pragma once

namespace Kinemo
{
	class Color
	{
	public:
		float r, g, b;

		Color(float red, float green, float blue) :
			r(red),
			g(green),
			b(blue)
		{}

		static const Color Red;
		static const Color Green;
		static const Color Blue;
	};

	const Color Color::Red		= Color(1.0f, 0.0f, 0.0f);
	const Color Color::Green	= Color(0.0f, 1.0f, 0.0f);
	const Color Color::Blue		= Color(0.0f, 0.0f, 1.0f);
}