#pragma once

#include "Core.h"
#include "math/Vec2.h"

#include <unordered_map>


namespace Kinemo
{
    // Pre-rendered font object
    class Font
    {
    public:
        struct Character
        {
            uint texture;
            Vec2 size;
            Vec2 bearing;
            uint advance;
        };

        Font(const char* path);
        ~Font();

        void SetSize(uint size);
        const Character& GetCharacter(const char code) const { return m_Characters.at(code); }

    private:
        std::unordered_map<char, Character> m_Characters;
        uint m_VAO, m_VBO;
    };
}