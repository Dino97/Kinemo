#pragma once
#include "core/Camera.h"
#include "math/Vec3.h"

namespace Kinemo
{
    class OrthographicCameraController
    {
    public:
        OrthographicCameraController(Camera camera) : m_Camera(camera) {}

        void Update(float dt);

        inline Camera& GetCamera() { return m_Camera; }
        inline const Camera& GetCamera() const {return m_Camera; }

    private:
        Camera m_Camera;

        Vec3 m_CameraPos;
	    float cameraSpeed = 500.0f;
    };
}