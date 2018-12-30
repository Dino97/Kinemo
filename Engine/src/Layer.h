#pragma once

#include "Core.h"
#include "events/Event.h"

namespace Kinemo
{
	class KINEMO_API Layer
	{
	protected:
		std::string m_DebugName;

	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Events::Event& event) {}
	};
}