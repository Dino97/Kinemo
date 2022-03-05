#pragma once

#include "graphics/Sprite.h"
#include <lua.hpp>

#define LUA_FUNC(func) int func(lua_State* L)

LUA_FUNC(Load)
{
    const char* path = lua_tostring(L, -1);

    auto texture = new Kinemo::Texture2D(path);
    lua_pushlightuserdata(L, texture);

    return 1;
}

void RegisterTexture2D(lua_State* L)
{
    lua_newtable(L);

    lua_pushstring(L, "Load");
    lua_pushcfunction(L, Load);
    lua_rawset(L, -3);

    lua_setglobal(L, "Texture2D");
}
