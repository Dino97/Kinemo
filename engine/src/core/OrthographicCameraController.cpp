#include "OrthographicCameraController.h"
#include "app/Input.h"

namespace Kinemo
{
    void OrthographicCameraController::Update(float dt)
    {
        if (Input::GetKeyDown(KEYCODE_A))
            m_CameraPos.x -= cameraSpeed * dt;
        if (Input::GetKeyDown(KEYCODE_D))
            m_CameraPos.x += cameraSpeed * dt;
        if (Input::GetKeyDown(KEYCODE_W))
            m_CameraPos.y += cameraSpeed * dt;
        if (Input::GetKeyDown(KEYCODE_S))
            m_CameraPos.y	-= cameraSpeed * dt;

        m_Camera.SetPosition(m_CameraPos);
    }
}