#pragma once

namespace Kinemo
{
    class Lua
    {
    public:
        static void Init();
        static void RunScript(const char* path);
        static void Update(float dt);
    };
}