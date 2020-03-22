#pragma once

#include "math/Mat4.h"

namespace Kinemo
{
    class Camera
    {
    public:
        Camera(const Math::Mat4& projectionMatrix);

        inline const Math::Mat4& GetView() const { return m_ViewMatrix; }
        inline const Math::Mat4& GetProjection() const { return m_ProjectionMatrix; }
        inline const Math::Mat4& GetViewProj() const { return m_ViewProjectionMatrix; }

        void SetPosition(const Math::Vec3& position) { m_Position = -position; RecalculateViewProjMatrix(); }

    private:
        void RecalculateViewProjMatrix();
        
    private:
        Math::Mat4 m_ViewMatrix;
        Math::Mat4 m_ProjectionMatrix;
        Math::Mat4 m_ViewProjectionMatrix;

        Math::Vec3 m_Position;
    };
}