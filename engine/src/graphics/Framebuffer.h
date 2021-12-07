#pragma once

#include "Texture2D.h"
#include "Color.h"

namespace Kinemo
{
    class Framebuffer
    {
    public:
        Framebuffer(unsigned int width, unsigned int height);
        ~Framebuffer();

        Framebuffer(const Framebuffer&) = delete;
        Framebuffer& operator=(const Framebuffer&) = delete;

        Framebuffer(Framebuffer&&) = default;
        Framebuffer& operator=(Framebuffer&&) = default;

        void Bind() const;
        void Unbind() const;

        void SetClearColor(const Color& color);
        void Clear();
        
        void CreateColorBuffer();
        void CreateDepthStencilBuffer();

        bool IsComplete() const;

    private:
        unsigned int m_Handle;
        unsigned int m_Width, m_Height;
        int m_ClearFlags;
    };
}