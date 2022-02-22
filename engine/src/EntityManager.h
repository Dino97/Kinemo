#pragma once

#include <cstdint>
#include <stack>

using Entity = uint32_t;

class EntityManager
{
public:
    Entity CreateEntity()
    {
        if (m_FreeEntities.empty() == false)
        {
            Entity e = m_FreeEntities.top();
            m_FreeEntities.pop();

            return e;
        }

        return m_NextEntity++;
    }

    void DestroyEntity(Entity entity)
    {
        m_FreeEntities.push(entity);
    }

private:
    std::stack<Entity> m_FreeEntities;
    Entity m_NextEntity;
};
