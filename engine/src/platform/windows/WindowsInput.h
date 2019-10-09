#pragma once

#include "app/Input.h"

namespace Kinemo
{
	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyDownImpl(int keycode) const override;
		virtual bool IsMouseButtonDownImpl(int button) const override;
		virtual float GetMouseXImpl() const override;
		virtual float GetMouseYImpl() const override;
	};
}