#pragma once

namespace Kinemo
{
	enum Filter
	{
		NEAREST = 0x2600,
		LINEAR
	};

	class Texture2D
	{
	public:
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		void SetMinFilter(Filter minFilter) const;
		void SetMagFilter(Filter magFilter) const;

		inline int GetWidth() const { return m_Width; }
		inline int GetHeight() const { return m_Height; }

		static Texture2D* CreateFromFile(const char* path);
		
	protected:
		int m_Width, m_Height, m_Channels;
	};
}