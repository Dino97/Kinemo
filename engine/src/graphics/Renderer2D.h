#pragma once

#include "math/Vec2.h"
#include "math/Vec3.h"
#include "math/Vec4.h"
#include "Texture2D.h"

namespace Kinemo 
{
	struct Vertex
	{
		Math::Vec3 position;
		Math::Vec2 texCoords;
		Math::Vec4 color;
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
			
			static void DrawQuad(const Math::Vec3& position, const Math::Vec2& size, const Math::Vec4& color);
			static void DrawQuad(const Math::Vec3& position, const Math::Vec2& size, const Texture2D& texture);

			struct Stats
			{
				unsigned int quads;
				unsigned int drawCalls;
			};

			static const Stats& GetStats();
			static void ResetStats();
	};
}