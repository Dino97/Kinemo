#pragma once

#include "Renderable2D.h"

namespace Kinemo {
	
	class IRenderer
	{
	public:
		virtual void Submit(Renderable2D* renderable) = 0;
		virtual void Flush() = 0;
	};
}