#pragma once

#include "app/Window.h"
#include "Core.h"

struct GLFWwindow;

namespace Kinemo
{
	class KINEMO_API WindowsWindow : public Window
	{
	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int m_Width, m_Height;
			bool vSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;

	public:
		WindowsWindow(const WindowProperties& properties);

		void Init(const WindowProperties& properties);

		void Clear() const override;
		void Update() const override;

		void SetEventCallback(const EventCallbackFn& callback) override;
		void SetVSync(bool vsync) override;
		bool IsClosing() const override;

		void SetTitle(const std::string& title) override;

		inline virtual void* GetNativeWindow() const { return m_Window; }
	};
}