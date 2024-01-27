#pragma once

#include "BoundingBox.h"
#include "math/Vec3.h"

#include <vector>

namespace Kinemo
{
    class PhysicsWorld
    {
    public:
        std::vector<BoundingBox> m_Colliders;

    private:
    };

    class Physics
    {
    public:
        static bool CheckBox(const BoundingBox& box);
        static bool Raycast(const Vec3& ray);

        static PhysicsWorld& GetActivePhysicsWorld();
    };
}
