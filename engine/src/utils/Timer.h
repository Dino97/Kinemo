#pragma once

struct Members;

class Timer
{
private:
	unsigned char m_Reserved[32];
	Members* m_Members;

public:
	// Create and start the timer
	Timer();

	// Resets the timer
	void Reset();

	// Elapsed time in seconds
	float Elapsed();

	// Elapsed time in milliseconds
	float ElapsedMs();

	// Elapsed time in microseconds
	float ElapsedUs();
};