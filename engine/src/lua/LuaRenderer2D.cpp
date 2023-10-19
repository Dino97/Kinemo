#include "LuaRenderer2D.h"

#include "graphics/Renderer2D.h"
#include "Kinemo.h"

using namespace Kinemo;

namespace Lua
{
    LUA_FUNC(DrawQuad)
    {
        float x = static_cast<float>(lua_tonumber(L, -5));
        float y = static_cast<float>(lua_tonumber(L, -4));
        float width = static_cast<float>(lua_tonumber(L, -3));
        float height = static_cast<float>(lua_tonumber(L, -2));
        auto sprite = static_cast<Texture2D*>(lua_touserdata(L, -1));

        lua_pop(L, 5);

        Renderer2D::DrawQuad({x, y, 0.1f}, {width, height}, *sprite);

        return 0;
    }

    LUA_FUNC(DrawRect)
    {
        float x      = static_cast<float>(lua_tonumber(L, -4));
        float y      = static_cast<float>(lua_tonumber(L, -3));
        float width  = static_cast<float>(lua_tonumber(L, -2));
        float height = static_cast<float>(lua_tonumber(L, -1));

        lua_pop(L, 4);

        Renderer2D::DrawQuad({x, y, 0.1f}, {width, height}, {1, 1, 1, 1});

        return 0;
    }

    void LuaRenderer2D::Register(lua_State* L)
    {
        lua_newtable(L);

        lua_pushstring(L, "draw_quad");
        lua_pushcfunction(L, DrawQuad);
        lua_rawset(L, -3);

        lua_pushstring(L, "draw_rect");
        lua_pushcfunction(L, DrawRect);
        lua_rawset(L, -3);

        lua_setglobal(L, "Renderer2D");
    }
}
