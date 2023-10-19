#pragma once

struct lua_State;

namespace Lua
{
    class LuaInput
    {
    public:
        static void Register(lua_State* L);
    };
}
