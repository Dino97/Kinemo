#include "Font.h"

#include <glad/glad.h>

#include <ft2build.h>
#include FT_FREETYPE_H


namespace Kinemo
{
    Font::Font(const char* path)
    {
        FT_Library ft;
        FT_Face face;

        FT_Init_FreeType(&ft);
        FT_New_Face(ft, path, 0, &face);
        FT_Set_Char_Size(face, 0, 11 * 64, 90, 90);
        
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

        // Render textures for first 128 characters.
        for (uint i = 0; i < 128; i++)
        {
            FT_Load_Char(face, i, FT_LOAD_RENDER);

            uint width = face->glyph->bitmap.width;
            uint height = face->glyph->bitmap.rows;

            uint tex;
            glGenTextures(1, &tex);
            glBindTexture(GL_TEXTURE_2D, tex);

            glTexImage2D(
                GL_TEXTURE_2D, 
                0, 
                GL_RED, 
                width, 
                height,
                0, 
                GL_RED, 
                GL_UNSIGNED_BYTE, 
                face->glyph->bitmap.buffer
            );

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            
            Character character = 
            {
                tex, 
                { static_cast<float>(width), static_cast<float>(height) }, 
                { static_cast<float>(face->glyph->bitmap_left), static_cast<float>(face->glyph->bitmap_top) }, 
                face->glyph->advance.x / 64     
            };

            m_Characters.insert(std::pair<char, Character>(i, character));
        }

        // Clean up.
        FT_Done_Face(face);
        FT_Done_FreeType(ft);
    }

    Font::~Font()
    {
        for (auto& character : m_Characters)
        {
            glDeleteTextures(1, &character.second.texture);
        }
    }
}