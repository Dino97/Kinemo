#include "Timer.h"

#include <chrono>

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
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - m_Members->m_Start).count();
}