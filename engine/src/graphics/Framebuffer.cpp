#include "Framebuffer.h"

#include <glad/glad.h>
#include <iostream>

#if 1
    #define CHECK_FRAMEBUFFER_BINDING()   { int framebuffer; \
										    glGetIntegerv(GL_FRAMEBUFFER_BINDING, &framebuffer); \
										    if (framebuffer != m_Handle) \
										    std::cout << "WARNING: Framebuffer is not bound." << std::endl; }
#else
    #define CHECK_FRAMEBUFFER_BINDING()
#endif

namespace Kinemo
{
    Framebuffer::Framebuffer(unsigned int width, unsigned int height) :
        m_Width(width),
        m_Height(height),
        m_ClearFlags(0)
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

    void Framebuffer::SetClearColor(const Color& color)
    {
        CHECK_FRAMEBUFFER_BINDING();
        glClearColor(color.r, color.g, color.b, color.a);
    }

    void Framebuffer::Clear()
    {
        CHECK_FRAMEBUFFER_BINDING();
        glClear(m_ClearFlags);
    }

    void Framebuffer::CreateColorBuffer()
    {
        CHECK_FRAMEBUFFER_BINDING();

        m_ColorBuffer = std::make_unique<Texture2D>(m_Width, m_Height, Texture2D::Channels::RGB, nullptr);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_ColorBuffer->GetHandle(), 0);

        m_ClearFlags |= GL_COLOR_BUFFER_BIT;
    }

    void Framebuffer::CreateDepthStencilBuffer()
    {
        CHECK_FRAMEBUFFER_BINDING();

        unsigned int depthStencilHandle;
        glGenTextures(1, &depthStencilHandle);
        glBindTexture(GL_TEXTURE_2D, depthStencilHandle);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH24_STENCIL8, m_Width, m_Height, 0, GL_DEPTH_STENCIL, GL_UNSIGNED_INT_24_8, nullptr);

        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthStencilHandle, 0);

        m_ClearFlags |= (GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    }

    bool Framebuffer::IsComplete() const
    {
        CHECK_FRAMEBUFFER_BINDING();
        return glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE;
    }
}