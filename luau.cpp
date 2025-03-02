// luau.cpp : Defines the entry point for the application.
//
#include "luau.h"
#include "lualib.h"
#include <luacode.h>
#include <iostream> 
#include <conio.h> 

lua_State* Luau_newstate() { return luaL_newstate(); }
lua_State* Luau_newthread(lua_State* L) { return lua_newthread(L); }

char* Luau_compile(const char* source, size_t* size) { return luau_compile(source, strlen(source), nullptr, size); }

void Luau_sandboxthread(lua_State* L) { luaL_sandboxthread(L); }
void Luau_close(lua_State* L) { lua_close(L); }
void Luau_sandbox(lua_State* L) { luaL_sandbox(L); }
void Luau_pushvalue(lua_State* L, int idx) { lua_pushvalue(L, idx); }
int Luau_type(lua_State* L, int idx) { return lua_type(L, idx); }
void Luau_openlibs(lua_State* L) { luaL_openlibs(L); }

double Luau_tonumber(lua_State* L, int idx) { return lua_tonumberx(L, idx, NULL); }
lua_CFunction Luau_tocfunction(lua_State* L, int idx) { return lua_tocfunction(L, idx); }
int Luau_tointeger(lua_State* L, int idx) { return lua_tointegerx(L, idx, NULL); }
int Luau_toboolean(lua_State* L, int idx) { return lua_toboolean(L, idx); }
void* Luau_touserdata(lua_State* L, int idx) { return lua_touserdata(L, idx); }
int Luau_ref(lua_State* L, int idx) { return lua_ref(L, idx); }
int Luau_getref(lua_State* L, int idx) { return lua_getref(L, idx); }
void Luau_unref(lua_State* L, int ref) { lua_unref(L, ref); }
unsigned Luau_tounsigned(lua_State* L, int i) { return lua_tounsignedx(L, i, NULL); }
const char* Luau_tostring(lua_State* L, int i) { return lua_tolstring(L, (i), NULL); }

void Luau_error(lua_State* L) { lua_error(L); }

void Luau_pop(lua_State* L, int n) { lua_settop(L, -(n)-1); }

void Luau_newtable(lua_State* L) { lua_createtable(L, 0, 0); }

void Luau_setmetatable(lua_State* L, int objIndex) { lua_setmetatable(L, objIndex); }

int Luau_strlen(lua_State* L, int i) { return lua_objlen(L, (i)); }

int Luau_isfunction(lua_State* L, int n) { return lua_type(L, (n)) == LUA_TFUNCTION; }
int Luau_istable(lua_State* L, int n) { return lua_type(L, (n)) == LUA_TTABLE; }
int Luau_islightuserdata(lua_State* L, int n) { return lua_type(L, (n)) == LUA_TLIGHTUSERDATA; }
int Luau_isuserdata(lua_State* L, int n) { return lua_isuserdata(L, n); }
int Luau_isnil(lua_State* L, int n) { return lua_type(L, (n)) == LUA_TNIL; }
int Luau_isboolean(lua_State* L, int n) { return lua_type(L, (n)) == LUA_TBOOLEAN; }
int Luau_isstring(lua_State* L, int n) { return lua_isstring(L, n); }
int Luau_isnumber(lua_State* L, int n) { return lua_isnumber(L, n); }
int Luau_isvector(lua_State* L, int n) { return lua_type(L, (n)) == LUA_TVECTOR; }
int Luau_isthread(lua_State* L, int n) { return lua_type(L, (n)) == LUA_TTHREAD; }
int Luau_isnone(lua_State* L, int n) { return lua_type(L, (n)) == LUA_TNONE; }
int Luau_isnoneornil(lua_State* L, int n) { return lua_type(L, (n)) <= LUA_TNIL; }
int Luau_pcall(lua_State* L, int nargs, int nresults, int errfunc) { return lua_pcall(L, nargs, nresults, errfunc); }

int Luau_load(lua_State* L, const char* chunkname, const char* data, size_t size, int env) { return luau_load(L, chunkname, data, size, env); }
int Luau_gettop(lua_State* L) { return lua_gettop(L); }
// void Luau_pushliterals(lua_State* L, const char* s) {lua_pushlstring(L, "" s, (sizeof(s) / sizeof(char)) - 1);}

void Luau_pushcfunction(lua_State* L, lua_CFunction fn, const char* debugname) { lua_pushcclosurek(L, fn, debugname, 0, NULL); }
void Luau_pushcclosure(lua_State* L, lua_CFunction fn, const char* debugname, int nup) { lua_pushcclosurek(L, fn, debugname, nup, NULL); }
void Luau_pushnumber(lua_State* L, double n) { lua_pushnumber(L, n); }
void Luau_pushnil(lua_State* L) { lua_pushnil(L); }
void Luau_pushinteger(lua_State* L, int n) { lua_pushinteger(L, n); }
void Luau_pushstring(lua_State* L, const char* s) { lua_pushstring(L, s); }
void Luau_pushboolean(lua_State* L, int b) { lua_pushboolean(L, b); }

void Luau_pushlightuserdata(lua_State* L, void* p) { lua_pushlightuserdata(L, p); }

void Luau_setglobal(lua_State* L, const char* s) { lua_setfield(L, LUA_GLOBALSINDEX, (s)); }
int Luau_getglobal(lua_State* L, const char* s) { return lua_getfield(L, LUA_GLOBALSINDEX, (s)); }

void Luau_setfield(lua_State* L, int idx, const char* s) { lua_setfield(L, idx, s); }
int Luau_getfield(lua_State* L, int idx, const char* s) { return lua_getfield(L, idx, s); }

void Luau_settable(lua_State* L, int idx) { lua_settable(L, idx); }
int Luau_gettable(lua_State* L, int idx) { return lua_gettable(L, idx); }

void* Luau_newuserdatadtor(lua_State* L, size_t sz, void(*dtor)(void*)) { return lua_newuserdatadtor(L, sz, dtor); }
void* Luau_newuserdata(lua_State* L, size_t s) { return lua_newuserdatatagged(L, s, 0); }

int Luau_resume(lua_State* L, lua_State* from, int nargs) { return lua_resume(L, from, nargs); }

void Luau_setsafeenv(lua_State* L, int objindex, int enabled) { lua_setsafeenv(L, objindex, enabled); }