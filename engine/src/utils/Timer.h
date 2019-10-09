#pragma once

#include "Core.h"

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
	virtual void Reset();

	// Elapsed time in seconds
	virtual float Elapsed();

	// Elapsed time in milliseconds
	virtual float ElapsedMs();
};