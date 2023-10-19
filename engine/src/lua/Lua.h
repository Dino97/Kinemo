#pragma once

#include <lua.hpp>

#define LUA_FUNC(func) int func(lua_State* L)

namespace Lua
{
    class LuaModule
    {
    public:
        virtual void Register(lua_State* L) = 0;
    };
}
