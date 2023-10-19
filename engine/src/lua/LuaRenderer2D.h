#pragma once

#include "Lua.h"

namespace Lua
{
    class LuaRenderer2D
    {
    public:
        static void Register(lua_State* L);
    };
}
