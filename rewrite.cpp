#ifndef __LUA_INC_H__
#define __LUA_INC_H__

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <string>
#include <vector>

extern "C"
{
	#include "Lua/lua.h"
	#include "Lua/lauxlib.h"
	#include "Lua/lualib.h"
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <GLFW/glfw3.h>
}

using namespace std;
GLFWwindow* window;

int loadstrFunc(lua_State *L) {
    printf("Do loadstring.");
    const char* script = lua_tostring(L, -1);
    luaL_dostring(L, script);
    return 0;
}

int openWindow(lua_State *L) {
    printf("Do loadstring.");
    const char* title = lua_tostring(L, -1);
	const int resX = lua_tointeger(L, 0);
	const int resY = lua_tointeger(L, 1);
	window = glfwCreateWindow(resX, resY, title, NULL, NULL);
	
	if (!window)
	{
   		printf("Window creation failed! :(");
	} else {
		glfwMakeContextCurrent(window);
	}
    return 0;
}

int swapBuffers(lua_State *L) {
	glfwSwapBuffers(window);
	glfwTerminate();
	return 0;
}

int term(lua_State *L) {
	printf("exit");
	glfwTerminate();
	return 0;
}

int luaopen_loadstr(lua_State *L){
	lua_register(L,"loadstring",loadstrFunc);
	return 0;
}

int luaopen_openWin(lua_State *L){
	lua_register(L,"openWindow",openWindow);
	return 0;
}

int luaopen_openexit(lua_State *L){
	lua_register(L,"exit",term);
	return 0;
}

int luaopen_openbufferswap(lua_State *L){
	lua_register(L,"swapBuffers",swapBuffers);
	return 0;
}

int main(int argc, char *argv[]) {
	double time = glfwGetTime();
	glfwSwapInterval(1);
	printf("Opening LUA...");
	lua_State *L;
	L = luaL_newstate();
	printf("Opening libs...");
	luaL_openlibs(L);
	luaopen_loadstr(L);
	luaopen_openbufferswap(L); //to fix
	luaopen_openexit(L); //to fix
	luaopen_openWin(L); //to fix
	luaL_dofile(L, "customluafunc.lua");
	lua_setglobal(L, "loadstring");
	lua_setglobal(L, "openWindow");
	//TODO: Fix SwapBuffers and exit
	printf("Loading scripts...");
	std::string doItStr = std::string("print('file executed.');") + std::string("dofile('") + std::string(argv[1]) + std::string("');");
	char *doItC = new char[doItStr.length() + 1];
	strcpy(doItC, doItStr.c_str());
	luaL_dostring(L, doItC);
}

#endif // __LUA_INC_H__
