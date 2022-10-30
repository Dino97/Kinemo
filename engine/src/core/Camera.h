#pragma once

#include "math/Mat4.h"

namespace Kinemo
{
    class Camera
    {
    public:
        Camera(const Mat4& projectionMatrix);

        inline const Mat4& GetView() const { return m_ViewMatrix; }
        inline const Mat4& GetProjection() const { return m_ProjectionMatrix; }
        inline const Mat4& GetViewProj() const { return m_ViewProjectionMatrix; }

        void SetPosition(const Vec3& position) { m_Position = -position; RecalculateViewProjMatrix(); }

    private:
        void RecalculateViewProjMatrix();
        
    private:
        Mat4 m_ViewMatrix;
        Mat4 m_ProjectionMatrix;
        Mat4 m_ViewProjectionMatrix;

        Vec3 m_Position;
    };
}