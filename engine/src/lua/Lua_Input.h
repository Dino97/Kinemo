#pragma once

#include "app/Input.h"
#include <lua.hpp>

#include <iostream>

#define LUA_FUNC(func) int func(lua_State* L)

LUA_FUNC(GetButtonDown)
{
    int button = lua_tonumber(L, -1);
    bool ret = Kinemo::Input::IsKeyDown(button);
    lua_pushboolean(L, ret);

    return 1;
}

LUA_FUNC(GetMouseButtonDown)
{
    int button = lua_tonumber(L, -1);
    bool ret = Kinemo::Input::IsMouseButtonDown(button);
    lua_pushboolean(L, ret);

    return 1;
}

LUA_FUNC(GetMousePosition)
{
    float x = Kinemo::Input::GetMouseX();
    float y = Kinemo::Input::GetMouseY();
    lua_pushnumber(L, x);
    lua_pushnumber(L, y);

    return 2;
}

void RegisterInput(lua_State* L)
{
    lua_newtable(L);

    lua_pushstring(L, "GetButtonDown");
    lua_pushcfunction(L, GetButtonDown);
    lua_rawset(L, -3);

    lua_pushstring(L, "GetMouseButtonDown");
    lua_pushcfunction(L, GetMouseButtonDown);
    lua_rawset(L, -3);

    lua_pushstring(L, "GetMousePosition");
    lua_pushcfunction(L, GetMousePosition);
    lua_rawset(L, -3);

    lua_setglobal(L, "Input");
}
