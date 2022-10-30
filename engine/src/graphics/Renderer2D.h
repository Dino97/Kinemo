#pragma once

#include "math/Vec2.h"
#include "math/Vec3.h"
#include "math/Vec4.h"
#include "Texture2D.h"

namespace Kinemo 
{
	struct Vertex
	{
		Vec3 position;
		Vec2 texCoords;
		Vec4 color;
		float textureId;
	};

	class Renderer2D
	{
		public:

			static void Init();
			static void Shutdown();

			static void Begin();
			static void Flush();
			static void End();
			
			static void DrawQuad(const Vec3& position, const Vec2& size, const Vec4& color);
			static void DrawQuad(const Vec3& position, const Vec2& size, const Texture2D& texture);

			template<typename T>
			static void Render(const T&);

			struct Stats
			{
				unsigned int quads;
				unsigned int drawCalls;
				unsigned int textureUnits;
			};

			static const Stats& GetStats();
			static void ResetStats();
	};
}