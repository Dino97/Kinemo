#include "Application.h"

#include "utils/Timer.h"
#include "math/Mat4.h"
#include "math/Vec2.h"
#include "graphics/Texture2D.h"
#include "graphics/Shader.h"
#include "utils/Log.h"

#include "graphics/Renderer2D.h"

#include <iostream>
#include <map>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "ft2build.h"
#include FT_FREETYPE_H

namespace Kinemo
{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application(const char* title, unsigned int width, unsigned int height, bool fullscreen)
	{
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	void Application::OnEvent(Events::Event& event)
	{
		Events::EventDispatcher dispatcher(event);
		dispatcher.Dispatch<Events::KeyPressedEvent>(BIND_EVENT_FN(InputCallback));

		KM_CORE_INFO("{0}", event.ToString());
	}

	bool Application::InputCallback(Events::Event& event)
	{
		return true;
	}

	void Application::InternalInit()
	{
		Log::Init();
		Renderer2D::Init();

		KM_CORE_INFO("Kinemo Engine initialised!");
		KM_CORE_INFO("Graphics: {0}", glGetString(GL_RENDERER));
		KM_CORE_INFO("Version: {0}", glGetString(GL_VERSION));
	}

	void Application::InternalUpdate(float deltaTime)
	{
		for (Layer* layer : m_LayerStack)
			layer->OnUpdate(deltaTime);
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
	}

	void Application::Start()
	{
		InternalInit();
		OnInit();

		Timer time;
		float timer = 0;

		double frameTime, lastFrameTime = 0, deltaTime;

		while (!m_Window->IsClosing())
		{
			frameTime = glfwGetTime();
			deltaTime = frameTime - lastFrameTime;
			lastFrameTime = frameTime;

			m_Window->Clear();

			InternalUpdate(deltaTime);
			OnUpdate(deltaTime);

			m_Window->Update();

			if (time.Elapsed() - timer > 1.0f)
			{
				timer += 1.0f;
				std::cout << (int)(1 / deltaTime) << " fps" << std::endl;
				KM_CORE_INFO("Quads: {0}, draw calls: {1}", Renderer2D::GetStats().quads, Renderer2D::GetStats().drawCalls);
			}
		}
	}
}