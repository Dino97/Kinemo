#pragma once

#include "math/Vec2.h"
#include <ostream>

namespace Kinemo
{
    class BoundingBox
    {
    public:
        BoundingBox();
        BoundingBox(const Vec2& center, const Vec2& extents);

        BoundingBox(const BoundingBox&) = default;
        BoundingBox(BoundingBox&&) = default;

        void Include(const Vec2& point);
        void Include(const BoundingBox& other);

        bool Raycast(const Vec2& origin, const Vec2& direction) const;
        bool Intersects(const BoundingBox& other) const;

        const Vec2& GetCenter() const { return m_Center; }
        void SetCenter(const Vec2& center) { m_Center = center; }

        const Vec2& GetExtents() const { return m_Extents; }
        void SetExtents(const Vec2& extents) { m_Extents = extents; }

        Vec2 GetMin() const { return m_Center - m_Extents; }
        Vec2 GetMax() const { return m_Center + m_Extents; }

		friend std::ostream& operator<<(std::ostream& stream, const BoundingBox& other);

    private:
        Vec2 m_Center;
        Vec2 m_Extents;
    };
}
