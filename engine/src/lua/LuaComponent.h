#pragma once

namespace Kinemo
{
    class LuaComponent
    {
        using StartFunc = void (*)(void);
        using UpdateFunc = void (*)(float);

    public:
        void Start()
        {
            if (m_StartFunc != nullptr) 
                m_StartFunc();
        }

        void Update(float dt)
        {
            if (m_UpdateFunc != nullptr)
                m_UpdateFunc(dt);
        }

    private:
        StartFunc m_StartFunc;
        UpdateFunc m_UpdateFunc;
    };
}