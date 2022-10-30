#include "Camera.h"

namespace Kinemo
{
    Camera::Camera(const Mat4& projectionMatrix) :
        m_ViewMatrix(Mat4::Identity()),
        m_ProjectionMatrix(projectionMatrix)
    {
        RecalculateViewProjMatrix();
    }

    void Camera::RecalculateViewProjMatrix()
    {
        m_ViewMatrix = Mat4::Translate(m_Position);

        m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
    }
}