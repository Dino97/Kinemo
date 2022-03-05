#pragma once

#include "graphics/Renderer2D.h"
#include <lua.hpp>
#include "Kinemo.h"

#define LUA_FUNC(func) int func(lua_State* L)

LUA_FUNC(DrawQuad)
{
    lua_pushstring(L, "x");
    lua_rawget(L, -4);
    float x = static_cast<float>(lua_tonumber(L, -1));
    lua_pop(L, 1);

    lua_pushstring(L, "y");
    lua_rawget(L, -4);
    float y = static_cast<float>(lua_tonumber(L, -1));
    lua_pop(L, 1);

    lua_pushstring(L, "x");
    lua_rawget(L, -3);
    float width = static_cast<float>(lua_tonumber(L, -1));
    lua_pop(L, 1);

    lua_pushstring(L, "y");
    lua_rawget(L, -3);
    float height = static_cast<float>(lua_tonumber(L, -1));
    lua_pop(L, 1);

    auto sprite = static_cast<Kinemo::Texture2D*>(lua_touserdata(L, -1));
    Kinemo::Renderer2D::DrawQuad({x, y, 0.1f}, {width, height}, *sprite);

    return 0;
}

void RegisterRenderer2D(lua_State* L)
{
    lua_newtable(L);

    lua_pushstring(L, "DrawQuad");
    lua_pushcfunction(L, DrawQuad);
    lua_rawset(L, -3);

    lua_setglobal(L, "Renderer2D");
}
