#pragma once

#include "lua.hpp"
#include <iostream>

struct LuaBind
{
    lua_State* L;
    const char* name;

    LuaBind& Function(const char* name, lua_CFunction function)
    {
        std::cout << lua_gettop(L) << std::endl;
        lua_pushstring(L, name);
        lua_pushcfunction(L, function);
        std::cout << lua_gettop(L) << std::endl;
        lua_settable(L, 1);
        std::cout << lua_gettop(L) << std::endl;

        return *this;
    }

    void EndTable()
    {
        lua_setglobal(L, name);
    }
};

LuaBind LuaBeginTable(lua_State* L, const char* name)
{
    lua_newtable(L);

    //return *reinterpret_cast<LuaBind*>(L);

    LuaBind res;
    res.L = L;
    res.name = name;

    return res;
};