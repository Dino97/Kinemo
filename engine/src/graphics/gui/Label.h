#pragma once

namespace Kinemo {

	class Rect;

	namespace GUI {

		enum class Alignment
		{
			NONE = 0,
			LEFT,
			CENTER,
			RIGHT
		};
		
		class Label
		{
		private:
			const char* m_Text;
			//Font m_Font;
			Alignment m_Alignment;

		public:
			Label(Rect rect, const char* text);

			void SetText(const char* text);
			void SetAlignment(Alignment alignment);

		};
	}
}