#pragma once

#include "BoundingBox.h"

namespace Kinemo
{
    class PhysicsWorld
    {
    public:
    };

    class Physics
    {
    public:
        static bool CheckBox(const BoundingBox& box);
        static bool Raycast(const Vec3& ray);
        
    private:
        PhysicsWorld m_World;
    };
}
