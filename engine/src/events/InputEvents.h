#pragma once

#include "Event.h"

#include <sstream>

namespace Kinemo { namespace Events {

	class KeyEvent : public Event
	{
	protected:
		int m_KeyCode;

		KeyEvent(int keycode) : 
			m_KeyCode(keycode) 
		{}

	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	}; // class KeyEvent

	class KeyPressedEvent : public KeyEvent
	{
	private:
		int m_RepeatCount;

	public:
		KeyPressedEvent(int keycode, int repeatCount) :
			KeyEvent(keycode),
			m_RepeatCount(repeatCount)
		{}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	}; // class KeyPressedEvent

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode) :
			KeyEvent(keycode)
		{}
		
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	}; // class KeyReleasedEvent

	class MouseButtonEvent : public Event
	{
	protected:
		int m_Button;

		MouseButtonEvent(int button) :
			m_Button(button)
		{}

	public:
		inline int GetButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
	}; // class MouseButtonEvent

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button) :
			MouseButtonEvent(button)
		{}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	}; // class MouseButtonPressedEvent

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button) :
			MouseButtonEvent(button)
		{}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

	class MouseMovedEvent : public Event
	{
	private:
		float m_MouseX, m_MouseY;

	public:
		MouseMovedEvent(float x, float y) :
			m_MouseX(x),
			m_MouseY(y)
		{}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
	}; // class MouseMovedEvent

	class MouseScrolledEvent : public Event
	{
	private:
		float m_XOffset, m_YOffset;

	public:
		MouseScrolledEvent(float xOffset, float yOffset) :
			m_XOffset(xOffset),
			m_YOffset(yOffset)
		{}

		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_XOffset << ", " << m_YOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
	}; // class MouseScrolledEvent
}}