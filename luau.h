// luau.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include "lua.h"
#include <luacodegen.h>
#include "luau/Compiler/src/Builtins.h"

#define LUAU_API extern "C" __declspec(dllexport)
typedef struct lua_CompileOptions lua_CompileOptions;

LUAU_API lua_State* Luau_newstate(); //implemented C#
LUAU_API lua_State* Luau_newthread(lua_State* L);
LUAU_API char* Luau_compile(const char* source, lua_CompileOptions* options, size_t* size);
LUAU_API void Luau_close(lua_State* L); //implemented C#
LUAU_API void Luau_openlibs(lua_State* L); //implemented C#
LUAU_API void Luau_sandboxthread(lua_State* L);
LUAU_API void Luau_sandbox(lua_State* L); //implemented C#
LUAU_API void Luau_pushvalue(lua_State* L, int idx); //implemented C#
LUAU_API int Luau_type(lua_State* L, int idx); //implemented C#
LUAU_API double Luau_tonumber(lua_State* L, int idx); //implemented C#
LUAU_API lua_CFunction Luau_tocfunction(lua_State* L, int idx); //implemented C#
LUAU_API int Luau_tointeger(lua_State* L, int idx); //implemented C#
LUAU_API int Luau_toboolean(lua_State*, int idx); //implemented C#
LUAU_API void* Luau_touserdata(lua_State* L, int idx);
LUAU_API int Luau_ref(lua_State* L, int idx); //implemented C#
LUAU_API int Luau_getref(lua_State* L, int idx); //implemented C#
LUAU_API void Luau_unref(lua_State* L, int ref); //implemented C#
LUAU_API unsigned Luau_tounsigned(lua_State* L, int idx); //implemented C#
LUAU_API const char* Luau_tostring(lua_State* L, int i); //implemented C#
LUAU_API void Luau_error(lua_State* L); //implemented C#
LUAU_API void Luau_pop(lua_State* L, int n); //implemented C#
LUAU_API void Luau_newtable(lua_State* L); //implemented C#
LUAU_API void Luau_setmetatable(lua_State* L, int objIndex);
LUAU_API int Luau_strlen(lua_State* L, int i);
LUAU_API int Luau_isfunction(lua_State* L, int n);
LUAU_API int Luau_istable(lua_State* L, int n); //implemented C#
LUAU_API int Luau_islightuserdata(lua_State* L, int n);
LUAU_API int Luau_isuserdata(lua_State* L, int n);
LUAU_API int Luau_isnil(lua_State* L, int n); //implemented C#
LUAU_API int Luau_isboolean(lua_State* L, int n);
LUAU_API int Luau_isstring(lua_State* L, int n); //implemented C#
LUAU_API int Luau_isnumber(lua_State* L, int n); //implemented C#
LUAU_API int Luau_isvector(lua_State* L, int n);
LUAU_API int Luau_isthread(lua_State* L, int n);
LUAU_API int Luau_isnone(lua_State* L, int n);
LUAU_API int Luau_isnoneornil(lua_State* L, int n);
LUAU_API int Luau_pcall(lua_State* L, int nargs, int nresults, int errfunc); //implemented C#
LUAU_API int Luau_load(lua_State* L, const char* chunkname, const char* data, size_t size, int env); //implemented C#
LUAU_API int Luau_gettop(lua_State* L); //implemented C#
LUAU_API void Luau_pushcfunction(lua_State* L, lua_CFunction fn); //implemented C#
LUAU_API void Luau_pushcclosure(lua_State* L, lua_CFunction fn, const char* debugname, int nup);
LUAU_API void Luau_pushnumber(lua_State* L, double n);  //implemented C#
LUAU_API void Luau_pushnil(lua_State* L); //implemented C#
LUAU_API void Luau_pushinteger(lua_State* L, int n); //implemented C#
LUAU_API void Luau_pushstring(lua_State* L, const char* s); //implemented C#
LUAU_API void Luau_pushboolean(lua_State* L, int b); //implemented C#
LUAU_API void Luau_pushlightuserdata(lua_State* L, void* p);  //implemented C#
LUAU_API void Luau_setglobal(lua_State* L, const char* s); //implemented C#
LUAU_API int Luau_getglobal(lua_State* L, const char* s); //implemented C#
LUAU_API void Luau_setfield(lua_State* L, int idx, const char* s); //implemented C#
LUAU_API int Luau_getfield(lua_State* L, int idx, const char* s); //implemented C#
LUAU_API void Luau_settable(lua_State* L, int idx); //implemented C#
LUAU_API int Luau_gettable(lua_State* L, int idx); //implemented C#
LUAU_API void* Luau_newuserdatadtor(lua_State* L, size_t sz, void (*dtor)(void*)); //implemented C#
LUAU_API void* Luau_newuserdata(lua_State* L, size_t s); //implemented C#
LUAU_API int Luau_resume(lua_State* L, lua_State* from, int nargs);
LUAU_API void Luau_setsafeenv(lua_State* L, int objindex, int enabled); //implemented C#
LUAU_API int Luau_codegen_supported(); //implemented C#
LUAU_API void Luau_codegen_create(lua_State* L); //implemented C#
LUAU_API void Luau_codegen_compile(lua_State* L, int idx); //implemented C#
LUAU_API void Luau_free(void* ptr); //implemented C#