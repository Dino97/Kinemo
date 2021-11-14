#pragma once

#include "events/Event.h"
#include "events/InputEvents.h"
#include <string>
#include <functional>

struct GLFWwindow;

namespace Kinemo
{
	enum class WindowMode
	{
		Windowed,
		Fullscreen,
		Borderless
	};

	struct WindowProperties
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;
		bool VSync;
		WindowMode Mode;

		WindowProperties(const std::string& title = "Kinemo Engine", unsigned int width = 1280, unsigned int height = 720) :
			Title(title),
			Width(width),
			Height(height),
			VSync(true),
			Mode(WindowMode::Windowed)
		{}
	};

	class Window
	{
	public:
		Window(const WindowProperties& properties = WindowProperties());
		~Window();

		void Clear() const;
		void Update() const;

		void SetVSync(bool vsync);
		bool IsClosing() const;
		void SetTitle(const std::string& title);

		inline GLFWwindow* GetNativeWindow() const { return m_Window; }

		using EventCallbackFn = std::function<void(Events::Event&)>;
		void SetEventCallback(const EventCallbackFn& callback);

		struct WindowData
		{
			EventCallbackFn EventCallback;
		};

	protected:
		WindowProperties m_WindowProperties;
		GLFWwindow* m_Window;
		WindowData m_Data;
		EventCallbackFn EventCallback;
		double m_CursorX, m_CursorY;
	};
}