#pragma once

namespace Kinemo { namespace Events {

	class IEventListener
	{
	protected:

		template<class Event, class Class>
		void RegisterEventCallback(void(Class::*callback)(const Event*))
		{

		}
	}; // class IEventListener

}} // namespace Kinemo::Events