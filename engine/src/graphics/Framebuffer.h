#pragma once

#include "Texture2D.h"

namespace Kinemo
{
    class Framebuffer
    {
    public:
        Framebuffer();
        ~Framebuffer();

        Framebuffer(const Framebuffer&) = delete;
        Framebuffer& operator=(const Framebuffer&) = delete;

        Framebuffer(Framebuffer&&) = default;
        Framebuffer& operator=(Framebuffer&&) = default;

        void Bind() const;
        void Unbind() const;

        void AttachTexture2D(int index, const Texture2D& texture);

        bool IsComplete() const;

    private:
        unsigned int m_Handle;
    };
}