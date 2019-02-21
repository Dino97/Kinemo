#pragma once

#include <list>

#include "Core.h"
#include "Window.h"
#include "utils/Timer.h"
#include "gameobject/GameObject.h"
#include "LayerStack.h"

namespace Kinemo
{
	class KINEMO_API Application
	{
	private:
		std::unique_ptr<Window> m_Window;
		Timer m_Timer;
		unsigned int m_FPS;
		std::list<Kinemo::GameObject*> m_GameObjects;
		Kinemo::LayerStack m_LayerStack;

		static Application* s_Instance;

	public:
		Application(const char* title, unsigned int width, unsigned int height, bool fullscreen);
		~Application();

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

		virtual void OnInit();
		virtual void OnUpdate();
		void OnEvent(Events::Event& event);
		void OnRender();

		bool InputCallback(Events::Event& event);

		inline unsigned int GetFPS() { return m_FPS; }

		inline void RegisterGameObject(Kinemo::GameObject* object) { m_GameObjects.push_back(object); }

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		void Start();
	};
}