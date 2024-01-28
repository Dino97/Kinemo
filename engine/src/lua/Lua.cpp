#include "Lua.h"

#include "utils/Log.h"

#include <lua.hpp>

struct LuaData
{
    lua_State* L;
    int kinemoTableIndex;
    int componentTableCount = 1;
};

static LuaData s_Data;

namespace Kinemo
{
    int Lua_RegisterComponentUpdate(lua_State* L)
    {
        if (lua_istable(L, -1))
        {
            // table
            lua_rawgeti(L, LUA_REGISTRYINDEX, s_Data.kinemoTableIndex);
            
            // table, kinemo table
            lua_pushstring(L, "ComponentTable");
            
            // table, component table, string
            lua_rawget(L, -2);

            // table, component table, update table
            lua_pushvalue(L, -3);

            // table, component table, update table, table
            lua_rawseti(L, -2, s_Data.componentTableCount++);
        }
        else
        {
            KM_WARNING("[Lua] value is not a table");
        }

        return 0;
    }

    static void CreateKinemoTable(lua_State* L)
    {
        lua_newtable(L);

        lua_pushstring(L, "ComponentTable");
        lua_newtable(L);

        lua_pushvalue(L, -1);
        lua_setglobal(L, "ComponentTable");

        lua_rawset(L, -3);

        s_Data.kinemoTableIndex = luaL_ref(L, LUA_REGISTRYINDEX);
    }

    void Init()
    {
        s_Data.L = luaL_newstate();
        luaL_openlibs(s_Data.L);

        CreateKinemoTable(s_Data.L);
        
        lua_register(s_Data.L, "RegisterComponentUpdate", Lua_RegisterComponentUpdate);
    }

    void RunScript(const char* path)
    {
        /*luaL_loadfile(s_Data.L, path);
        lua_pushstring(s_Data.L, path);
        lua_pushnumber(s_Data.L, 69);
        lua_pcall(s_Data.L, 2, LUA_MULTRET, 0);*/

        if (luaL_dofile(s_Data.L, path) != LUA_OK)
        {

            const char* error_msg = lua_tostring(s_Data.L, -1);
            KM_WARNING("[Lua] {0}", error_msg);
        }
    }

    void Update(float dt)
    {
        lua_State* L = s_Data.L;

        lua_rawgeti(L, LUA_REGISTRYINDEX, s_Data.kinemoTableIndex);

        // 
        lua_pushstring(L, "ComponentTable");
        lua_rawget(L, -2);

        lua_pushnil(L);
        // kinemo table, component table, nil

        while (lua_next(L, -2) != 0)
        {
            // kinemo table, component table, index, table
            lua_pushstring(L, "Update");
            lua_rawget(L, -2);
            // kinemo table, component table, index, table, Update func

            lua_pushvalue(L, -1);
            // kinemo table, component table, index, table, Update func, Update func

            lua_pushvalue(L, -3);
            // kinemo table, component table, index, table, Update func, Update func, table
            lua_pushnumber(L, dt);
            // kinemo table, component table, index, table, Update func, Update func, table, dt
            lua_call(L, 2, 0);
            // kinemo table, component table, index, table, Update func
            lua_pop(L, 2);
        }

        lua_pop(L, 2);
    }
}