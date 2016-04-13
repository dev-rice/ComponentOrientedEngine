#include "LuaScripter.hpp"

LuaScripter::LuaScripter(Transform2DComponentManager& transform_2D_component_manager): transform_2D_component_manager(transform_2D_component_manager) {

    /* initialize Lua */
	L = lua_open();

	/* load Lua base libraries */
	luaL_openlibs(L);

	/* register our function */
	lua_register(L, "moveThings", LuaScripter::moveThings);

	/* run the script */
	luaL_dofile(L, "move_things.lua");

}

LuaScripter::~LuaScripter() {
    /* cleanup Lua */
	lua_close(L);
}

int LuaScripter::moveThings(lua_State *L) {
    return 0;
}
