#include "Window.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Kinemo
{
	Window::Window(const WindowProperties& properties)
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		GLFWmonitor* monitor = properties.Mode == WindowMode::Windowed ? nullptr : glfwGetPrimaryMonitor();
		m_Window = glfwCreateWindow(properties.Width, properties.Height, properties.Title.c_str(), monitor, nullptr);
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

	Window::~Window()
	{
		glfwDestroyWindow(m_Window);
	}
	
	void Window::Clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // dark gray
	}
	
	void Window::Update() const
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void Window::SetEventCallback(const EventCallbackFn& callback)
	{
		m_Data.EventCallback = callback;
	}

	void Window::SetVSync(bool vsync)
	{
		glfwSwapInterval(vsync ? 1 : 0);
	}

	bool Window::IsClosing() const
	{
		return glfwWindowShouldClose(m_Window);
	}

	void Window::SetTitle(const std::string& title)
	{
		m_WindowProperties.Title = title;

		glfwSetWindowTitle(m_Window, title.c_str());
	}
}