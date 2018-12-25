#pragma once

#include "IRenderer.h"
#include <queue>

namespace Kinemo { 

	class SimpleRenderer2D : public IRenderer
	{
	private:
		std::queue<Renderable2D*> m_Queue;
	public:
		virtual void Submit(Renderable2D* renderable) override;
		virtual void Flush() override;
	};
}