#include "LuaPhysics.h"

#include <iostream>

namespace Lua
{
    LUA_FUNC(CheckBox)
    {
        double x, y;

        lua_pushstring(L, "x");
        lua_rawget(L, -2);
        x = lua_tonumber(L, -1);

        lua_pop(L, 1);

        lua_pushstring(L, "y");
        lua_rawget(L, -2);
        y = lua_tonumber(L, -1);

        std::cout << x << ", " << y << std::endl;

        if(y > 0)
        {
            lua_pushboolean(L, false);
            std::cout << "false" << std::endl;
        }
        else
        {
            lua_pushboolean(L, true);
            std::cout << "true" << std::endl;
        }

        return 1;
    }

    LUA_FUNC(New)
    {
        lua_newtable(L);

        return 1;
    }

    void LuaPhysics::Register(lua_State* L)
    {
        // Physics.
        lua_newtable(L);

        lua_pushstring(L, "check_box");
        lua_pushcfunction(L, CheckBox);
        lua_rawset(L, -3);

        lua_setglobal(L, "Physics");


        // Bounding box.
        lua_newtable(L);

        lua_pushstring(L, "new");
        lua_pushcfunction(L, New);
        lua_rawset(L, -3);

        lua_setglobal(L, "BoundingBox");
    }
}
