#include "WindowsInput.h"
#include "app/Application.h"

#include <GLFW/glfw3.h>

namespace Kinemo
{
	Input* Input::s_Instance = new WindowsInput();

	bool WindowsInput::IsKeyDownImpl(int keycode) const
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		int state = glfwGetKey(window, keycode);

		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WindowsInput::IsMouseButtonDownImpl(int button) const
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		int state = glfwGetMouseButton(window, button);

		return state == GLFW_PRESS;
	}

	float WindowsInput::GetMouseXImpl() const
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());

		double xPos, yPos;
		glfwGetCursorPos(window, &xPos, &yPos);

		return static_cast<float>(xPos);
	}

	float WindowsInput::GetMouseYImpl() const
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());

		double xPos, yPos;
		glfwGetCursorPos(window, &xPos, &yPos);

		return static_cast<float>(yPos);
	}
}