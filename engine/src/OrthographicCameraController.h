#pragma once
#include "Camera.h"
#include "math/Vec3.h"

namespace Kinemo
{
    class OrthographicCameraController
    {
    public:
        void Update(float dt);

        inline Camera& GetCamera() { return m_Camera; }
        inline const Camera& GetCamera() const {return m_Camera; }

    private:
        Camera m_Camera;

        Math::Vec3 m_CameraPos;
	    float cameraSpeed = 500.0f;
    };
}