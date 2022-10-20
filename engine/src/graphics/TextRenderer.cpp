#include "TextRenderer.h"
#include "Renderer2D.h"
#include "Shader.h"

#include <cstring>
#include <glad/glad.h>


namespace Kinemo
{
    void TextRenderer::DrawText(const Font& font, const Math::Vec3& position, const char* text)
    {
        // Draw text over everything.
        glDisable(GL_DEPTH_TEST);

        // Generate VAO and VBO.
        uint vao, vbo;

        glGenVertexArrays(1, &vao);
        glGenBuffers(1, &vbo);

        glBindVertexArray(vao);

        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, 4 * 4 * sizeof(float), 0, GL_DYNAMIC_DRAW);

        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (const void*)0);
        glEnableVertexAttribArray(0);

        Math::Vec3 pen = position;

        // Draw all characters.
        int len = std::strlen(text);
        for (int i = 0; i < len; i++)
        {
            const Font::Character& c = font.GetCharacter(text[i]);

            float yOffset = c.size.y - c.bearing.y;

            float vertices[4 * 4] =
            {
                pen.x + c.bearing.x + c.size.x, position.y - yOffset, 1, 1,
                pen.x + c.bearing.x + c.size.x, position.y + c.size.y - yOffset, 1, 0,
                pen.x + c.bearing.x, position.y - yOffset, 0, 1,
                pen.x + c.bearing.x, position.y + c.size.y - yOffset, 0, 0
            };

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, c.texture);

            glBindBuffer(GL_ARRAY_BUFFER, vbo);
            glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
            glBindBuffer(GL_ARRAY_BUFFER, 0);

            glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

            pen.x += c.advance;
        }

        // Clean up.
        glDeleteVertexArrays(1, &vao);
        glDeleteBuffers(1, &vbo);
        glEnable(GL_DEPTH_TEST);
    }
}
