#pragma once

#include "EntityManager.h"

#include <lua.hpp>
#include <iostream>



int Lua_EntityManager_CreateEntity(lua_State* L);
int Lua_EntityManager_DestroyEntity(lua_State* L);

void RegisterEntityManager(lua_State* L, EntityManager* em)
{
    lua_newtable(L);

    lua_pushstring(L, "handle");
    lua_pushlightuserdata(L, em);
    lua_settable(L, -3);

    // Register CreateEntity method
    lua_pushstring(L, "CreateEntity");
    lua_pushcfunction(L, Lua_EntityManager_CreateEntity);
    lua_settable(L, -3);
    
    // Register DestroyEntity method
    lua_pushstring(L, "DestroyEntity");
    lua_pushcfunction(L, Lua_EntityManager_DestroyEntity);
    lua_settable(L, -3);

    lua_setglobal(L, "EntityManager");            
}

int Lua_EntityManager_CreateEntity(lua_State* L)
{
    lua_pushstring(L, "handle");
    lua_gettable(L, -2);
    EntityManager* em = static_cast<EntityManager*>(lua_touserdata(L, -1));

    lua_pushnumber(L, em->CreateEntity());

    return 1;
}

int Lua_EntityManager_DestroyEntity(lua_State* L)
{
    if (lua_gettop(L) < 2)
    {
        lua_pushstring(L, "[EntityManager:DestroyEntity] too few arguments in a function call");
        lua_error(L);
    }

    lua_pushstring(L, "handle");
    lua_gettable(L, -3);
    EntityManager* em = static_cast<EntityManager*>(lua_touserdata(L, -1));
    lua_pop(L, 1);

    Entity entity = lua_tonumber(L, -1);
    em->DestroyEntity(entity);

    return 0;
}