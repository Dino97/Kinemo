#pragma once

namespace Kinemo
{
	enum class Filter
	{
		NEAREST = 0x2600,
		LINEAR
	};

	class Texture2D
	{
	public:
		Texture2D(const char* path);
		~Texture2D();

		Texture2D(const Texture2D&) = delete;
		Texture2D& operator=(const Texture2D&) = delete;

		Texture2D(Texture2D&&) = default;
		Texture2D& operator=(Texture2D&&) = default;

		virtual void Bind() const;
		virtual void Unbind() const;

		void MinFilter(Filter minFilter) const;
		void MagFilter(Filter magFilter) const;

		inline int Width() const { return m_Width; }
		inline int Height() const { return m_Height; }
		inline unsigned int GetHandle() const { return m_Handle; }
		
	private:
		int m_Width, m_Height, m_Channels;
		unsigned int m_Handle;
	};
}