#pragma once

#include "Core.h"

struct GLFWwindow;

#define MAX_KEYS 1024

class Window
{
private:
	GLFWwindow* m_Window;
	double m_CursorX, m_CursorY;

	bool m_Keys[MAX_KEYS];

public:
	Window(const char* title, unsigned int width, unsigned int height, bool fullscreen);
	~Window();

	bool WindowShouldRun() const;

	void Clear() const;
	void SwapBuffers() const;

	void SetVSync(bool vsync);

	GLFWwindow* GetWindow() const { return m_Window; }

	friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	friend void mouse_position_callback(GLFWwindow* window, double x, double y);

	inline bool IsKeyDown(int keycode) const { return m_Keys[keycode]; }

	// come up with better name
	enum class WindowType
	{
		Windowed,
		Fullscreen,
		Borderless
	};
}; // class Window