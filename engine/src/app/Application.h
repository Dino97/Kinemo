#pragma once

#include <list>
#include <memory>

#include "Core.h"
#include "Window.h"
#include "utils/Timer.h"
#include "gameobject/GameObject.h"
#include "graphics/layers/LayerStack.h"

namespace Kinemo
{
	class Application
	{
	public:
		Application(const char* title, unsigned int width, unsigned int height, bool fullscreen);
		~Application();

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

		virtual void OnInit();
		virtual void OnUpdate(float deltaTime);
		void OnEvent(Events::Event& event);
		void OnRender();

		bool InputCallback(Events::Event& event);

		inline void RegisterGameObject(GameObject* object) { m_GameObjects.push_back(object); }

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		void Start();
	private:
		std::unique_ptr<Window> m_Window;
		Timer m_Timer;
		std::list<GameObject*> m_GameObjects;
		LayerStack m_LayerStack;

		static Application* s_Instance;

	};
}