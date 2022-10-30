#include "Input.h"
#include "app/Application.h"

#include <GLFW/glfw3.h>

namespace Kinemo
{
	Input* Input::s_Instance = new Input();

	static int lastState[512] = {0};


	static inline GLFWwindow* GetWindow()
	{
		return static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
	}

	bool Input::GetKeyImpl(int keycode)
	{
		int state = glfwGetKey(GetWindow(), keycode);

		return state == GLFW_PRESS;
	}

	bool Input::GetKeyDownImpl(int keycode)
	{
		bool retVal = false;
		int curState = glfwGetKey(GetWindow(), keycode);

		if (curState == GLFW_PRESS && curState != lastState[keycode])
			retVal = true;

		lastState[keycode] = curState;

		return retVal;
	}

	bool Input::GetKeyUpImpl(int keycode)
	{
		bool retVal = false;
		int curState = glfwGetKey(GetWindow(), keycode);

		if (curState == GLFW_RELEASE && curState != lastState[keycode])
			retVal = true;

		lastState[keycode] = curState;

		return retVal;
	}

	bool Input::GetMouseButtonDownImpl(int button)
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		int state = glfwGetMouseButton(window, button);

		return state == GLFW_PRESS;
	}

	float Input::GetMouseXImpl() const
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());

		double xPos, yPos;
		glfwGetCursorPos(window, &xPos, &yPos);

		return static_cast<float>(xPos);
	}

	float Input::GetMouseYImpl() const
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());

		double xPos, yPos;
		glfwGetCursorPos(window, &xPos, &yPos);

		return static_cast<float>(yPos);
	}
}