#include "LuaPhysics.h"

#include "physics/Physics.h"

#include <iostream>

using namespace Kinemo;

namespace Lua
{
    LUA_FUNC(CheckBox)
    {
        float xPos, yPos, xExtents, yExtents;

        lua_pushstring(L, "x");
        lua_rawget(L, -2);
        xExtents = static_cast<float>(lua_tonumber(L, -1));

        lua_pop(L, 1);


        lua_pushstring(L, "y");
        lua_rawget(L, -2);
        yExtents = static_cast<float>(lua_tonumber(L, -1));

        lua_pop(L, 2);


        lua_pushstring(L, "x");
        lua_rawget(L, -2);
        xPos = static_cast<float>(lua_tonumber(L, -1));

        lua_pop(L, 1);


        lua_pushstring(L, "y");
        lua_rawget(L, -2);
        yPos = static_cast<float>(lua_tonumber(L, -1));

        lua_pop(L, 1);

        
        BoundingBox box = {{xPos, yPos}, {xExtents, yExtents}};
        lua_pushboolean(L, Physics::CheckBox(box));

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
