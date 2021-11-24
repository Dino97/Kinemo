#include "Framebuffer.h"

#include <glad/glad.h>

namespace Kinemo
{
    Framebuffer::Framebuffer()
    {
        glGenFramebuffers(1, &m_Handle);
    }

    Framebuffer::~Framebuffer()
    {
        glDeleteFramebuffers(1, &m_Handle);
    }

    void Framebuffer::Bind() const
    {
        glBindFramebuffer(GL_FRAMEBUFFER, m_Handle);
    }

    void Framebuffer::Unbind() const
    {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    void Framebuffer::AttachTexture2D(int index, const Texture2D& texture)
    {
        if (index >= 8)
        {
            // query GL_MAX_COLOR_ATTACHMENTS
        }

        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + index, GL_TEXTURE_2D, texture.GetHandle(), 0);
    }

    bool Framebuffer::IsComplete() const
    {
        Bind();
        return glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE;
    }
}