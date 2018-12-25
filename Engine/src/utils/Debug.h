#pragma once

#include <cassert>

#if KINEMO_DEBUG
	#define ASSERT(expression) assert(expression)
#else
	#define ASSERT(expression) expression
#endif

#define LOG_INFO
#define LOG_WARNING
#define LOG_ERROR

namespace Kinemo {
	namespace Debug {

	}
}