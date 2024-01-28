#include "Physics.h"

#include <iostream>

namespace Kinemo
{
    static PhysicsWorld s_PhysicsWorld;

    bool Physics::CheckBox(const BoundingBox& box)
    {
        for(const auto& bb : s_PhysicsWorld.m_Colliders)
        {
            if(bb.Intersects(box))
                return true;
        }

        return false;
    }

    bool Physics::Raycast(const Vec3& ray)
    {
        return true;
    }

    PhysicsWorld& Physics::GetActivePhysicsWorld()
    {
        return s_PhysicsWorld;
    }
}
