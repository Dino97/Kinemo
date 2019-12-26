#pragma once

#include "events/Event.h"

namespace Kinemo
{
	class Layer
	{
	protected:
		std::string m_DebugName;

	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(float deltaTime) {}
		virtual void OnEvent(Events::Event& event) {}
	};
}