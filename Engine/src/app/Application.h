#pragma once

#include <list>

#include "Core.h"
#include "Window.h"
#include "utils/Timer.h"
#include "entity/Scene.h"
#include "GameObject.h"
#include "LayerStack.h"

namespace Kinemo
{
	class KINEMO_API Application
	{
	private:
		Window* m_Window;
		Timer m_Timer;
		unsigned int m_FPS;
		unsigned int m_Width, m_Height;
		//Scene m_CurrentScene;
		std::list<Kinemo::GameObject*> m_GameObjects;
		Kinemo::LayerStack m_LayerStack;

	public:
		Application(const char* title, unsigned int width, unsigned int height, bool fullscreen);
		~Application();

		virtual void OnInit();
		virtual void OnUpdate();
		void OnRender();

		inline unsigned int GetFPS() { return m_FPS; }
		inline bool IsKeyDown(int keycode) const { return m_Window->IsKeyDown(keycode); }

		inline void RegisterGameObject(Kinemo::GameObject* object) { m_GameObjects.push_back(object); }

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		void Start();

	public:
		//void LoadScene(Scene scene);
		//Scene& GetLoadedScene() { return m_CurrentScene; }
	};
}