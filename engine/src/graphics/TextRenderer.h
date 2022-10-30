#pragma once

#include "Font.h"
#include "math/Math.h"


namespace Kinemo
{
    class TextRenderer
    {
    public:
        static void DrawText(const Font& font, const Vec3& position, const char* text);
        
    private:
    
    };
}
