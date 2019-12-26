#pragma once

#include "events/Event.h"
#include "events/InputEvents.h"
#include <string>
#include <functional>

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
	protected:
		WindowProperties m_WindowProperties;
		double m_CursorX, m_CursorY;

	public:
		using EventCallbackFn = std::function<void(Events::Event&)>;

		virtual ~Window() {}

		virtual void Clear() const = 0;
		virtual void Update() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool vsync) = 0;
		virtual bool IsClosing() const = 0;

		virtual void SetTitle(const std::string& title) = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProperties& properties = WindowProperties());

	}; // class Window
} // namespace Kinemo