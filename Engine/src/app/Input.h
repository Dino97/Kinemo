#pragma once

#include "Core.h"

namespace Kinemo
{
	class KINEMO_API Input
	{
	public:
		inline static bool IsKeyDown(int keycode) { return s_Instance->IsKeyDownImpl(keycode); }
		inline static bool IsMouseButtonDown(int button) { return s_Instance->IsMouseButtonDownImpl(button); }
		inline static float GetMouseX() { return s_Instance->GetMouseXImpl(); };
		inline static float GetMouseY() { return s_Instance->GetMouseYImpl(); };

	protected:
		virtual bool IsKeyDownImpl(int keycode) const = 0;
		virtual bool IsMouseButtonDownImpl(int button) const = 0;
		virtual float GetMouseXImpl() const = 0;
		virtual float GetMouseYImpl() const = 0;

	private:
		static Input* s_Instance;
	};
}