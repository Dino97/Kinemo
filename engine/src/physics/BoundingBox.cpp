#include "BoundingBox.h"

#include "math/Vec2.h"

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

    void BoundingBox::Include(const BoundingBox& box)
    {
        Include(box.GetMin());
        Include(box.GetMax());
    }

    bool BoundingBox::Raycast(const Vec2& origin, const Vec2& direction) const
    {
        bool retVal = false;

        return retVal;
    }
}
