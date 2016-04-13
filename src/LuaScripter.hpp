#ifndef LuaScripter_h
#define LuaScripter_h

extern "C" {
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}

#include "component_managers/Transform2DComponentManager.hpp"

class LuaScripter {
public:
    LuaScripter(Transform2DComponentManager& transform_2D_component_manager);
    ~LuaScripter();

    static int moveThings(lua_State *L);

private:
    Transform2DComponentManager& transform_2D_component_manager;

    /* the Lua interpreter */
    lua_State* L;

};

#endif
