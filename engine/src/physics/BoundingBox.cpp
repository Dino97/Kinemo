#include "BoundingBox.h"

#include "math/Vec2.h"

#include <iostream>

namespace Kinemo
{
    BoundingBox::BoundingBox() :
        m_Center({0, 0}),
        m_Extents({0, 0})
    {}

    BoundingBox::BoundingBox(const Vec2& center, const Vec2& extents) :
        m_Center(center),
        m_Extents(extents)
    {}

    void BoundingBox::Include(const Vec2& point)
    {
        Vec2 centerOffset;

        if (point.x > m_Center.x + m_Extents.x)
        {
            float diff = point.x - (m_Center.x + m_Extents.x);
            m_Extents.x += diff / 2.0f;
            centerOffset.x = diff / 2.0f;
        }
        else if (point.x < m_Center.x - m_Extents.x)
        {
            float diff = point.x - (m_Center.x - m_Extents.x);
            m_Extents.x += -diff / 2.0f;
            centerOffset.x = diff / 2.0f;
        }

        if (point.y > m_Center.y + m_Extents.y)
        {
            float diff = point.y - (m_Center.y + m_Extents.y);
            m_Extents.y += diff / 2.0f;
            centerOffset.y = diff / 2.0f;
        }
        else if (point.y < m_Center.y - m_Extents.y)
        {
            float diff = point.y - (m_Center.y - m_Extents.y);
            m_Extents.y += -diff / 2.0f;
            centerOffset.y = diff / 2.0f;
        }

        m_Center += centerOffset;
    }

    void BoundingBox::Include(const BoundingBox& other)
    {
        Include(other.GetMin());
        Include(other.GetMax());
    }

    bool BoundingBox::Raycast(const Vec2& origin, const Vec2& direction) const
    {
        bool retVal = false;

        return retVal;
    }

    bool BoundingBox::Intersects(const BoundingBox& other) const
    {
        bool collisionX = m_Center.x + m_Extents.x >= other.m_Center.x - other.m_Extents.x &&
            other.m_Center.x + other.m_Extents.x >= m_Center.x - m_Extents.x;
        bool collisionY = m_Center.y + m_Extents.y >= other.m_Center.y - other.m_Extents.y &&
            other.m_Center.y + other.m_Extents.y >= m_Center.y - m_Extents.y;

        return collisionX && collisionY;
    }

	std::ostream& operator<<(std::ostream& stream, const BoundingBox& other)
    {
        stream << "Center: " << other.m_Center << ", " << "Extents: " << other.m_Extents;

        return stream;
    }
}
