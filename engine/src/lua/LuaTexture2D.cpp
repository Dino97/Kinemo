#include "LuaTexture2D.h"

#include "Lua.h"
#include "graphics/Texture2D.h"

using namespace Kinemo;

#include <iostream>

namespace Lua
{
    LUA_FUNC(Load)
    {
        const char* path = lua_tostring(L, -1);

        //lua_pushlightuserdata(L, texture);

        void* newTexture = lua_newuserdata(L, sizeof(Texture2D*));
        new (newTexture) Texture2D(path);

        return 1;
    }

    void LuaTexture2D::Register(lua_State* L)
    {
        lua_newtable(L);

        lua_pushstring(L, "load");
        lua_pushcfunction(L, Load);
        lua_rawset(L, -3);

        lua_setglobal(L, "Texture2D");
    }
}
