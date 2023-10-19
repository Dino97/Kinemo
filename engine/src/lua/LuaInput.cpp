#include "LuaInput.h"

#include "Lua.h"
#include "app/Input.h"

using namespace Kinemo;

namespace Lua
{
    LUA_FUNC(GetKey)
    {
        int keycode = lua_tonumber(L, -1);
        bool ret = Input::GetKey(keycode);
        lua_pushboolean(L, ret);

        return 1;
    }

    LUA_FUNC(GetMouseButtonDown)
    {
        int button = lua_tonumber(L, -1);
        bool ret = Input::GetMouseButtonDown(button);
        lua_pushboolean(L, ret);

        return 1;
    }

    LUA_FUNC(GetMousePosition)
    {
        float x = Input::GetMouseX();
        float y = Input::GetMouseY();
        lua_pushnumber(L, x);
        lua_pushnumber(L, y);

        return 2;
    }

    void LuaInput::Register(lua_State* L)
    {
        lua_newtable(L);

        lua_pushstring(L, "GetKey");
        lua_pushcfunction(L, GetKey);
        lua_rawset(L, -3);

        lua_pushstring(L, "GetMouseButtonDown");
        lua_pushcfunction(L, GetMouseButtonDown);
        lua_rawset(L, -3);

        lua_pushstring(L, "GetMousePosition");
        lua_pushcfunction(L, GetMousePosition);
        lua_rawset(L, -3);

        lua_setglobal(L, "Input");
    }
}
