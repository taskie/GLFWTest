/*
** Lua binding: aps_random_MersenneTwister
** Generated automatically by tolua++-1.0.92 on Fri Dec  7 12:05:06 2012.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_aps_random_MersenneTwister_open (lua_State* tolua_S);

#include "../aps/random/MersenneTwister.h"
using namespace aps::random;

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_MersenneTwister (lua_State* tolua_S)
{
 MersenneTwister* self = (MersenneTwister*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"MersenneTwister");
}

/* method: new of class  MersenneTwister */
#ifndef TOLUA_DISABLE_tolua_aps_random_MersenneTwister_random_MersenneTwister_new00
static int tolua_aps_random_MersenneTwister_random_MersenneTwister_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MersenneTwister",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   MersenneTwister* tolua_ret = (MersenneTwister*)  Mtolua_new((MersenneTwister)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"MersenneTwister");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  MersenneTwister */
#ifndef TOLUA_DISABLE_tolua_aps_random_MersenneTwister_random_MersenneTwister_new00_local
static int tolua_aps_random_MersenneTwister_random_MersenneTwister_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MersenneTwister",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   MersenneTwister* tolua_ret = (MersenneTwister*)  Mtolua_new((MersenneTwister)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"MersenneTwister");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  MersenneTwister */
#ifndef TOLUA_DISABLE_tolua_aps_random_MersenneTwister_random_MersenneTwister_new01
static int tolua_aps_random_MersenneTwister_random_MersenneTwister_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MersenneTwister",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  unsigned int seed = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  {
   MersenneTwister* tolua_ret = (MersenneTwister*)  Mtolua_new((MersenneTwister)(seed));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"MersenneTwister");
  }
 }
 return 1;
tolua_lerror:
 return tolua_aps_random_MersenneTwister_random_MersenneTwister_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  MersenneTwister */
#ifndef TOLUA_DISABLE_tolua_aps_random_MersenneTwister_random_MersenneTwister_new01_local
static int tolua_aps_random_MersenneTwister_random_MersenneTwister_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MersenneTwister",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  unsigned int seed = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  {
   MersenneTwister* tolua_ret = (MersenneTwister*)  Mtolua_new((MersenneTwister)(seed));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"MersenneTwister");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_aps_random_MersenneTwister_random_MersenneTwister_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: seed of class  MersenneTwister */
#ifndef TOLUA_DISABLE_tolua_aps_random_MersenneTwister_random_MersenneTwister_seed00
static int tolua_aps_random_MersenneTwister_random_MersenneTwister_seed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const MersenneTwister",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const MersenneTwister* self = (const MersenneTwister*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'seed'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->seed();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'seed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: next of class  MersenneTwister */
#ifndef TOLUA_DISABLE_tolua_aps_random_MersenneTwister_random_MersenneTwister_next00
static int tolua_aps_random_MersenneTwister_random_MersenneTwister_next00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MersenneTwister",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MersenneTwister* self = (MersenneTwister*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'next'", NULL);
#endif
  {
   double tolua_ret = (double)  self->next();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'next'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: next of class  MersenneTwister */
#ifndef TOLUA_DISABLE_tolua_aps_random_MersenneTwister_random_MersenneTwister_next01
static int tolua_aps_random_MersenneTwister_random_MersenneTwister_next01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MersenneTwister",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  MersenneTwister* self = (MersenneTwister*)  tolua_tousertype(tolua_S,1,0);
  double a = ((double)  tolua_tonumber(tolua_S,2,0));
  double b = ((double)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'next'", NULL);
#endif
  {
   double tolua_ret = (double)  self->next(a,b);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_aps_random_MersenneTwister_random_MersenneTwister_next00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: nextInt of class  MersenneTwister */
#ifndef TOLUA_DISABLE_tolua_aps_random_MersenneTwister_random_MersenneTwister_nextInt00
static int tolua_aps_random_MersenneTwister_random_MersenneTwister_nextInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MersenneTwister",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MersenneTwister* self = (MersenneTwister*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'nextInt'", NULL);
#endif
  {
   int tolua_ret = (int)  self->nextInt();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'nextInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: nextInt of class  MersenneTwister */
#ifndef TOLUA_DISABLE_tolua_aps_random_MersenneTwister_random_MersenneTwister_nextInt01
static int tolua_aps_random_MersenneTwister_random_MersenneTwister_nextInt01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MersenneTwister",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  MersenneTwister* self = (MersenneTwister*)  tolua_tousertype(tolua_S,1,0);
  double a = ((double)  tolua_tonumber(tolua_S,2,0));
  double b = ((double)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'nextInt'", NULL);
#endif
  {
   int tolua_ret = (int)  self->nextInt(a,b);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_aps_random_MersenneTwister_random_MersenneTwister_nextInt00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_aps_random_MersenneTwister_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"random",0);
  tolua_beginmodule(tolua_S,"random");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"MersenneTwister","MersenneTwister","",tolua_collect_MersenneTwister);
   #else
   tolua_cclass(tolua_S,"MersenneTwister","MersenneTwister","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"MersenneTwister");
    tolua_function(tolua_S,"new",tolua_aps_random_MersenneTwister_random_MersenneTwister_new00);
    tolua_function(tolua_S,"new_local",tolua_aps_random_MersenneTwister_random_MersenneTwister_new00_local);
    tolua_function(tolua_S,".call",tolua_aps_random_MersenneTwister_random_MersenneTwister_new00_local);
    tolua_function(tolua_S,"new",tolua_aps_random_MersenneTwister_random_MersenneTwister_new01);
    tolua_function(tolua_S,"new_local",tolua_aps_random_MersenneTwister_random_MersenneTwister_new01_local);
    tolua_function(tolua_S,".call",tolua_aps_random_MersenneTwister_random_MersenneTwister_new01_local);
    tolua_function(tolua_S,"seed",tolua_aps_random_MersenneTwister_random_MersenneTwister_seed00);
    tolua_function(tolua_S,"next",tolua_aps_random_MersenneTwister_random_MersenneTwister_next00);
    tolua_function(tolua_S,"next",tolua_aps_random_MersenneTwister_random_MersenneTwister_next01);
    tolua_function(tolua_S,"nextInt",tolua_aps_random_MersenneTwister_random_MersenneTwister_nextInt00);
    tolua_function(tolua_S,"nextInt",tolua_aps_random_MersenneTwister_random_MersenneTwister_nextInt01);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_aps_random_MersenneTwister (lua_State* tolua_S) {
 return tolua_aps_random_MersenneTwister_open(tolua_S);
};
#endif

