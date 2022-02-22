#include "Timer.h"

#include <chrono>
#include <new>

struct Members
{
	std::chrono::time_point<std::chrono::high_resolution_clock> m_Start;
};

Timer::Timer() : m_Members(new (m_Reserved) Members())
{
	Reset();
}

void Timer::Reset()
{
	m_Members->m_Start = std::chrono::high_resolution_clock::now();
}

float Timer::Elapsed()
{
	return ElapsedMs() / 1000;
}

float Timer::ElapsedMs()
{
	return ElapsedUs() / 1000;
}

float Timer::ElapsedUs()
{
	return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - m_Members->m_Start).count();
}