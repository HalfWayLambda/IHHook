/*
** $Id: lua.h,v 1.218.1.7 2012/01/13 20:36:20 roberto Exp $
** Lua - An Extensible Extension Language
** Lua.org, PUC-Rio, Brazil (http://www.lua.org)
** See Copyright Notice at the end of this file
*/
//tex: Butchered fwd decls to func pointers. Search //OFF , FUNCPTRDEF
#include "../HookMacros.h" //tex

#ifndef lua_h
#define lua_h

#include <stdarg.h>
#include <stddef.h>


#include "luaconf.h"


#define LUA_VERSION	"Lua 5.1"
#define LUA_RELEASE	"Lua 5.1.5"
#define LUA_VERSION_NUM	501
#define LUA_COPYRIGHT	"Copyright (C) 1994-2012 Lua.org, PUC-Rio"
#define LUA_AUTHORS 	"R. Ierusalimschy, L. H. de Figueiredo & W. Celes"


/* mark for precompiled code (`<esc>Lua') */
#define	LUA_SIGNATURE	"\033Lua"

/* option for multiple returns in `lua_pcall' and `lua_call' */
#define LUA_MULTRET	(-1)


/*
** pseudo-indices
*/
#define LUA_REGISTRYINDEX	(-10000)
#define LUA_ENVIRONINDEX	(-10001)
#define LUA_GLOBALSINDEX	(-10002)
#define lua_upvalueindex(i)	(LUA_GLOBALSINDEX-(i))


/* thread status; 0 is OK */
#define LUA_YIELD	1
#define LUA_ERRRUN	2
#define LUA_ERRSYNTAX	3
#define LUA_ERRMEM	4
#define LUA_ERRERR	5


typedef struct lua_State lua_State;

typedef int (*lua_CFunction) (lua_State *L);


/*
** functions that read/write blocks when loading/dumping Lua chunks
*/
typedef const char * (*lua_Reader) (lua_State *L, void *ud, size_t *sz);

typedef int (*lua_Writer) (lua_State *L, const void* p, size_t sz, void* ud);


/*
** prototype for memory-allocation functions
*/
typedef void * (*lua_Alloc) (void *ud, void *ptr, size_t osize, size_t nsize);


/*
** basic types
*/
#define LUA_TNONE		(-1)

#define LUA_TNIL		0
#define LUA_TBOOLEAN		1
#define LUA_TLIGHTUSERDATA	2
#define LUA_TNUMBER		3
#define LUA_TSTRING		4
#define LUA_TTABLE		5
#define LUA_TFUNCTION		6
#define LUA_TUSERDATA		7
#define LUA_TTHREAD		8



/* minimum Lua stack available to a C function */
#define LUA_MINSTACK	20


/*
** generic extra include file
*/
#if defined(LUA_USER_H)
#include LUA_USER_H
#endif


/* type of numbers in Lua */
typedef LUA_NUMBER lua_Number;


/* type for integer functions */
typedef LUA_INTEGER lua_Integer;



/*
** state manipulation
*/
FUNCPTRDEF(lua_State*, lua_newstate, lua_Alloc f, void *ud);
FUNCPTRDEF(void, lua_close, lua_State *L);
FUNCPTRDEF(lua_State*, lua_newthread, lua_State* L);

FUNCPTRDEF(lua_CFunction, lua_atpanic, lua_State *L, lua_CFunction panicf);

/*
** basic stack manipulation
*/
LUA_API int   (lua_gettop)(lua_State* L);//FUNCPTRDEF(int, lua_gettop, lua_State *L);
FUNCPTRDEF(void, lua_settop, lua_State *L, int index);
FUNCPTRDEF(void, lua_pushvalue, lua_State *L, int index);
FUNCPTRDEF(void, lua_remove, lua_State *L, int index);
FUNCPTRDEF(void, lua_insert, lua_State *L, int index);
FUNCPTRDEF(void, lua_replace, lua_State *L, int index);
FUNCPTRDEF(int, lua_checkstack, lua_State *L, int size);

FUNCPTRDEF(void, lua_xmove, lua_State *from, lua_State *to, int n);

//*
/** access functions (stack -> C)
/*/

FUNCPTRDEF(int, lua_isnumber, lua_State *L, int index);
FUNCPTRDEF(int, lua_isstring, lua_State *L, int index);
FUNCPTRDEF(int, lua_iscfunction, lua_State *L, int index);
LUA_API int (lua_isuserdata)(lua_State *L, int idx);//FUNCPTRDEF(int, lua_isuserdata, lua_State *L, int idx);
FUNCPTRDEF(int, lua_type, lua_State *L, int index);
FUNCPTRDEF(const char*, lua_typename, lua_State *L, int tp);

//OFF LUA_API int (lua_equal)(lua_State *L, int idx1, int idx2);
FUNCPTRDEF(int, lua_rawequal, lua_State *L, int idx1, int idx2);
FUNCPTRDEF(int, lua_lessthan, lua_State *L, int idx1, int idx2);

FUNCPTRDEF(double, lua_tonumber, lua_State *L, int index);
FUNCPTRDEF(lua_Integer, lua_tointeger, lua_State *L, int index);
FUNCPTRDEF(int, lua_toboolean, lua_State *L, int index);
FUNCPTRDEF(const char*, lua_tolstring, lua_State *L, int index, size_t *len);
FUNCPTRDEF(size_t, lua_objlen, lua_State *L, int idx);
FUNCPTRDEF(lua_CFunction, lua_tocfunction, lua_State *L, int idx);
FUNCPTRDEF(void*, lua_touserdata, lua_State *L, int idx);
FUNCPTRDEF(lua_State*, lua_tothread, lua_State *L, int idx);
FUNCPTRDEF(const void*, lua_topointer, lua_State *L, int idx);


/*
** push functions (C -> stack)
*/
FUNCPTRDEF(void, lua_pushnil, lua_State *L);
FUNCPTRDEF(void, lua_pushnumber, lua_State *L, double n);
FUNCPTRDEF(void, lua_pushinteger, lua_State *L, lua_Integer n);
FUNCPTRDEF(void, lua_pushlstring, lua_State *L, const char *s, size_t length);
FUNCPTRDEF(void, lua_pushstring, lua_State *L, const char *s);
FUNCPTRDEF(const char *, lua_pushvfstring, lua_State *L, const char *fmt, va_list argp);
FUNCPTRDEF(const char *, lua_pushfstring, lua_State *L, const char *fmt, ...);
FUNCPTRDEF(void, lua_pushcclosure, lua_State *L, lua_CFunction fn, int n)
FUNCPTRDEF(void, lua_pushboolean, lua_State *L, int boolean);
FUNCPTRDEF(void, lua_pushlightuserdata, lua_State *L, void *p);
FUNCPTRDEF(int, lua_pushthread, lua_State *L);

/*
** get functions (Lua -> stack)
*/
FUNCPTRDEF(void, lua_gettable, lua_State *L, int idx);
FUNCPTRDEF(void, lua_getfield, lua_State *L, int idx, const char *k);
FUNCPTRDEF(void, lua_rawget, lua_State *L, int idx);
FUNCPTRDEF(void, lua_rawgeti, lua_State *L, int idx, int n);
FUNCPTRDEF(void, lua_createtable, lua_State *L, int narray, int nrec);
FUNCPTRDEF(void *, lua_newuserdata, lua_State *L, size_t sz);
FUNCPTRDEF(int, lua_getmetatable, lua_State *L, int objindex);
FUNCPTRDEF(void, lua_getfenv, lua_State *L, int idx);


/*
** set functions (stack -> Lua)
*/
FUNCPTRDEF(void, lua_settable, lua_State *L, int idx);
FUNCPTRDEF(void, lua_setfield, lua_State *L, int idx, const char *k);
FUNCPTRDEF(void, lua_rawset, lua_State *L, int idx);
FUNCPTRDEF(void, lua_rawseti, lua_State *L, int idx, int n);
FUNCPTRDEF(int, lua_setmetatable, lua_State *L, int objindex);
FUNCPTRDEF(int, lua_setfenv, lua_State *L, int idx);


/*
** `load' and `call' functions (load and run Lua code)
*/
FUNCPTRDEF(void, lua_call, lua_State *L, int nargs, int nresults);
FUNCPTRDEF(int, lua_pcall, lua_State *L, int nargs, int nresults, int errfunc);
FUNCPTRDEF(int, lua_cpcall, lua_State *L, lua_CFunction func, void *ud);
FUNCPTRDEF(int, lua_load, lua_State *L, lua_Reader reader, void *dt, const char *chunkname);

FUNCPTRDEF(int, lua_dump, lua_State *L, lua_Writer writer, void *data);

/*
** coroutine functions
*/
LUA_API int  (lua_yield)(lua_State *L, int nresults);//FUNCPTRDEF(int, lua_yield, lua_State *L, int nresults);
FUNCPTRDEF(int, lua_resume, lua_State *L, int narg);
LUA_API int  (lua_status)(lua_State* L);//FUNCPTRDEF(int, lua_status, lua_State *L);

/*
** garbage-collection function and options
*/

#define LUA_GCSTOP		0
#define LUA_GCRESTART		1
#define LUA_GCCOLLECT		2
#define LUA_GCCOUNT		3
#define LUA_GCCOUNTB		4
#define LUA_GCSTEP		5
#define LUA_GCSETPAUSE		6
#define LUA_GCSETSTEPMUL	7

FUNCPTRDEF(int, lua_gc, lua_State *L, int what, int data);


/*
** miscellaneous functions
*/

FUNCPTRDEF(int, lua_error, lua_State *L);

FUNCPTRDEF(int, lua_next, lua_State *L, int idx);

FUNCPTRDEF(void, lua_concat, lua_State *L, int n);

//OFF LUA_API  lua_Alloc(lua_getallocf, lua_State *L, void **ud);
//FUNCPTRDEF(void, lua_setallocf, lua_State *L, lua_Alloc f, void *ud);



/* 
** ===============================================================
** some useful macros
** ===============================================================
*/

#define lua_pop(L,n)		lua_settop(L, -(n)-1)

#define lua_newtable(L)		lua_createtable(L, 0, 0)

#define lua_register(L,n,f) (lua_pushcfunction(L, (f)), lua_setglobal(L, (n)))

#define lua_pushcfunction(L,f)	lua_pushcclosure(L, (f), 0)

#define lua_strlen(L,i)		lua_objlen(L, (i))

#define lua_isfunction(L,n)	(lua_type(L, (n)) == LUA_TFUNCTION)
#define lua_istable(L,n)	(lua_type(L, (n)) == LUA_TTABLE)
#define lua_islightuserdata(L,n)	(lua_type(L, (n)) == LUA_TLIGHTUSERDATA)
#define lua_isnil(L,n)		(lua_type(L, (n)) == LUA_TNIL)
#define lua_isboolean(L,n)	(lua_type(L, (n)) == LUA_TBOOLEAN)
#define lua_isthread(L,n)	(lua_type(L, (n)) == LUA_TTHREAD)
#define lua_isnone(L,n)		(lua_type(L, (n)) == LUA_TNONE)
#define lua_isnoneornil(L, n)	(lua_type(L, (n)) <= 0)

#define lua_pushliteral(L, s)	\
	lua_pushlstring(L, "" s, (sizeof(s)/sizeof(char))-1)

#define lua_setglobal(L,s)	lua_setfield(L, LUA_GLOBALSINDEX, (s))
#define lua_getglobal(L,s)	lua_getfield(L, LUA_GLOBALSINDEX, (s))

#define lua_tostring(L,i)	lua_tolstring(L, (i), NULL)



/*
** compatibility macros and functions
*/

#define lua_open()	luaL_newstate()

#define lua_getregistry(L)	lua_pushvalue(L, LUA_REGISTRYINDEX)

#define lua_getgccount(L)	lua_gc(L, LUA_GCCOUNT, 0)

#define lua_Chunkreader		lua_Reader
#define lua_Chunkwriter		lua_Writer


/* hack */
//FUNCPTRDEF(void, lua_setlevel, lua_State *from, lua_State *to);


/*
** {======================================================================
** Debug API
** =======================================================================
*/


/*
** Event codes
*/
#define LUA_HOOKCALL	0
#define LUA_HOOKRET	1
#define LUA_HOOKLINE	2
#define LUA_HOOKCOUNT	3
#define LUA_HOOKTAILRET 4


/*
** Event masks
*/
#define LUA_MASKCALL	(1 << LUA_HOOKCALL)
#define LUA_MASKRET	(1 << LUA_HOOKRET)
#define LUA_MASKLINE	(1 << LUA_HOOKLINE)
#define LUA_MASKCOUNT	(1 << LUA_HOOKCOUNT)

typedef struct lua_Debug lua_Debug;  /* activation record */


/* Functions to be called by the debuger in specific events */
typedef void (*lua_Hook) (lua_State *L, lua_Debug *ar);


FUNCPTRDEF(int, lua_getstack, lua_State *L, int level, lua_Debug *ar);
FUNCPTRDEF(int, lua_getinfo, lua_State *L, const char *what, lua_Debug *ar);
FUNCPTRDEF(const char *, lua_getlocal, lua_State *L, const lua_Debug *ar, int n);
FUNCPTRDEF(const char *, lua_setlocal, lua_State *L, const lua_Debug *ar, int n);

FUNCPTRDEF(const char *, lua_getupvalue, lua_State *L, int funcindex, int n);
FUNCPTRDEF(const char *, lua_setupvalue, lua_State *L, int funcindex, int n);

FUNCPTRDEF(int, lua_sethook, lua_State *L, lua_Hook func, int mask, int count);
FUNCPTRDEF(lua_Hook, lua_gethook, lua_State *L);
FUNCPTRDEF(int, lua_gethookmask, lua_State *L);
FUNCPTRDEF(int, lua_gethookcount, lua_State *L);


struct lua_Debug {
  int event;
  const char *name;	/* (n) */
  const char *namewhat;	/* (n) `global', `local', `field', `method' */
  const char *what;	/* (S) `Lua', `C', `main', `tail' */
  const char *source;	/* (S) */
  int currentline;	/* (l) */
  int nups;		/* (u) number of upvalues */
  int linedefined;	/* (S) */
  int lastlinedefined;	/* (S) */
  char short_src[LUA_IDSIZE]; /* (S) */
  /* private part */
  int i_ci;  /* active function */
};

/* }====================================================================== */


/******************************************************************************
* Copyright (C) 1994-2012 Lua.org, PUC-Rio.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining
* a copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish,
* distribute, sublicense, and/or sell copies of the Software, and to
* permit persons to whom the Software is furnished to do so, subject to
* the following conditions:
*
* The above copyright notice and this permission notice shall be
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
******************************************************************************/


#endif
