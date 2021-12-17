#pragma once

#include "Texture2D.h"
#include "Color.h"

#include <memory>

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

        const std::unique_ptr<Texture2D>& GetColorBuffer() const { return m_ColorBuffer; }
        //const std::unique_ptr<Texture2D>& GetDepthStencilBuffer() const { return m_ColorBuffer; } // TO-DO

        bool IsComplete() const;

    private:
        std::unique_ptr<Texture2D> m_ColorBuffer/*, m_DepthStencilBuffer*/;
        unsigned int m_Handle;
        unsigned int m_Width, m_Height;
        int m_ClearFlags;
    };
}