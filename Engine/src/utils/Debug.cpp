#include "Debug.h"

#include <iostream>

namespace Kinemo {
	namespace Debug {

		void Log(const char* message)
		{
			std::cout << "DEBUG: " << message << std::endl;
		}
	}
}