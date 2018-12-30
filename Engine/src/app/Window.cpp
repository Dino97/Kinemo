#include "Window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream> // for dev testing

Window::Window(const char* title, unsigned int width, unsigned int height, bool fullscreen)
{
	// Init glfw
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_Window = glfwCreateWindow(width, height, title, fullscreen ? glfwGetPrimaryMonitor() : NULL, NULL);
	glfwMakeContextCurrent(m_Window);

	SetVSync(true);

	glfwSetWindowUserPointer(m_Window, this);

	// Set callbacks
	glfwSetKeyCallback(m_Window, key_callback);
	glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
	glfwSetCursorPosCallback(m_Window, mouse_position_callback);

	// Init openGL
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		// log this
	}

	glEnable(GL_DEPTH_TEST);
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	for (int i = 0; i < MAX_KEYS; i++)
	{
		m_Keys[i] = false;
	}
}

Window::~Window()
{
	glfwDestroyWindow(m_Window);
}

bool Window::WindowShouldRun() const
{
	return !glfwWindowShouldClose(m_Window);
}

void Window::Clear() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // dark gray
	//glClearColor(0.3f, 0.6f, 0.85f, 1.0f); // sky blue
}

void Window::SwapBuffers() const
{
	glfwPollEvents();
	glfwSwapBuffers(m_Window);
}

void Window::SetVSync(bool vsync)
{
	// vSync off = 0, on = 1
	glfwSwapInterval(vsync == true ? 1 : 0);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Window* win = (Window*)glfwGetWindowUserPointer(window);

	win->m_Keys[key] = action == GLFW_RELEASE ? 0 : 1;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	Window* win = (Window*)glfwGetWindowUserPointer(window);
}

void mouse_position_callback(GLFWwindow* window, double x, double y)
{
	Window* win = (Window*)glfwGetWindowUserPointer(window);

	win->m_CursorX = x;
	win->m_CursorY = y;
}