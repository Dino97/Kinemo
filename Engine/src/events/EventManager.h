#pragma once

#include "Event.h"

namespace Kinemo { namespace Events {

	class EventManager
	{
	private:

	public:
		void Subscribe(EventType eventType, void(*callback));
		void Unsubscribe(EventType eventType, );
		void Invoke(Event& e);
	}; // class EventManager

}}