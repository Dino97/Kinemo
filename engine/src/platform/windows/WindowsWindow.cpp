#include "WindowsWindow.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Kinemo
{
	WindowsWindow::WindowsWindow(const WindowProperties& properties)
	{
		Init(properties);
	}

	void WindowsWindow::Init(const WindowProperties& properties)
	{
		m_Data.Title = properties.Title;
		m_Data.m_Width = properties.Width;
		m_Data.m_Height = properties.Height;

		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_Window = glfwCreateWindow(m_Data.m_Width, m_Data.m_Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{

		}

		glfwSetWindowUserPointer(m_Window, &m_Data);

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch(action)	
			{
				case GLFW_PRESS:
				{
					Events::KeyPressedEvent event(key, 0);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					Events::KeyReleasedEvent event(key);
					data.EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					Events::KeyPressedEvent event(key, 1);
					data.EventCallback(event);
					break;
				}
			}
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					Events::MouseButtonPressedEvent event(button);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					Events::MouseButtonReleasedEvent event(button);
					data.EventCallback(event);
					break;
				}
			}
		});

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	Window* Window::Create(const WindowProperties& properties)
	{
		return new WindowsWindow(properties);
	}
	
	void WindowsWindow::Clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // dark gray
	}
	
	void WindowsWindow::Update() const
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetEventCallback(const EventCallbackFn& callback)
	{
		m_Data.EventCallback = callback;
	}

	void WindowsWindow::SetVSync(bool vsync)
	{
		glfwSwapInterval(vsync ? 1 : 0);
	}

	bool WindowsWindow::IsClosing() const
	{
		return glfwWindowShouldClose(m_Window);
	}

	void WindowsWindow::SetTitle(const std::string& title)
	{
		m_WindowProperties.Title = title;

		glfwSetWindowTitle(m_Window, title.c_str());
	}
}