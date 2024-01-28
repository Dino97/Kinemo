#pragma once

/* Includes */
/*============================================================*/

#include "lua.hpp"
#include "lua/LuaInput.h"
#include "lua/LuaPhysics.h"
#include "lua/LuaRenderer2D.h"
#include "lua/LuaTexture2D.h"


/* Defines and types */
/*============================================================*/

void RunLuaScript(lua_State* L, const char* path)
{
    int res = luaL_dofile(L, path);

    if (res != LUA_OK)
    {
        std::cout << lua_tostring(L, -1) << std::endl;
    }
}

void LuaUpdate(lua_State* L, float dt)
{
    lua_getglobal(L, "update");
    lua_pushnumber(L, dt);
   
    if(LUA_OK != lua_pcall(L, 1, 0, 0))
    {
        const char* errorMsg = lua_tostring(L, -1);
        std::cout << errorMsg << std::endl;
    }
}
