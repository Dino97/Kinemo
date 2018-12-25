#pragma once

struct GLFWwindow;

// come up with better name
enum class WindowType
{
	Windowed,
	Fullscreen,
	Borderless
};

class Window
{
private:
	GLFWwindow* m_Window;
	double m_CursorX, m_CursorY;

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
};