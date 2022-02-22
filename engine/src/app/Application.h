#pragma once

#include "Window.h"
#include "graphics/layers/LayerStack.h"
#include "utils/Timer.h"

#include <memory>

namespace Kinemo
{
	class Application
	{
	public:
		Application(const char* title, unsigned int width, unsigned int height, bool fullscreen);
		virtual ~Application() {}

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

		void Start();

		virtual void OnInit() {}
		virtual void OnUpdate(float deltaTime) {}
		void OnEvent(Events::Event& event);

		bool InputCallback(Events::Event& event);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

	private:
		void InternalInit();
		void InternalUpdate(float deltaTime);

	private:
		static Application* s_Instance;

		std::unique_ptr<Window> m_Window;
		Timer m_Timer;
		LayerStack m_LayerStack;
	};
}