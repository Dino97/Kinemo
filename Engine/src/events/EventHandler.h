#pragma once

#include <iostream>

namespace Kinemo { namespace Events {

	class EventHandler
	{
	private:

	public:
		template<class T, class... Args>
		void InvokeEvent(Args&&... eventArgs)
		{
			std::cout << "Event invoked" << std::endl;
		}

		template<class T>
		void Subscribe(void(*func)())
		{

		}

		void Unsubscribe();

	}; // class EventHandler

}} // namespace Kinemo::Events