/*
** Lua binding: aps_input_ButtonState
** Generated automatically by tolua++-1.0.92 on Fri Dec  7 00:52:03 2012.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_aps_input_ButtonState_open (lua_State* tolua_S);

#include "../aps/input/ButtonState.h"
using namespace aps::input;

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_ButtonState (lua_State* tolua_S)
{
 ButtonState* self = (ButtonState*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"ButtonState");
}

/* method: new of class  ButtonState */
#ifndef TOLUA_DISABLE_tolua_aps_input_ButtonState_input_ButtonState_new00
static int tolua_aps_input_ButtonState_input_ButtonState_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ButtonState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ButtonState* tolua_ret = (ButtonState*)  Mtolua_new((ButtonState)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ButtonState");
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

/* method: new_local of class  ButtonState */
#ifndef TOLUA_DISABLE_tolua_aps_input_ButtonState_input_ButtonState_new00_local
static int tolua_aps_input_ButtonState_input_ButtonState_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ButtonState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ButtonState* tolua_ret = (ButtonState*)  Mtolua_new((ButtonState)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ButtonState");
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

/* method: pressed of class  ButtonState */
#ifndef TOLUA_DISABLE_tolua_aps_input_ButtonState_input_ButtonState_pressed00
static int tolua_aps_input_ButtonState_input_ButtonState_pressed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ButtonState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ButtonState* self = (ButtonState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pressed'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->pressed();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pressed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: just of class  ButtonState */
#ifndef TOLUA_DISABLE_tolua_aps_input_ButtonState_input_ButtonState_just00
static int tolua_aps_input_ButtonState_input_ButtonState_just00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ButtonState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ButtonState* self = (ButtonState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'just'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->just();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'just'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: holdingTime of class  ButtonState */
#ifndef TOLUA_DISABLE_tolua_aps_input_ButtonState_input_ButtonState_holdingTime00
static int tolua_aps_input_ButtonState_input_ButtonState_holdingTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ButtonState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ButtonState* self = (ButtonState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'holdingTime'", NULL);
#endif
  {
   int tolua_ret = (int)  self->holdingTime();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'holdingTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_aps_input_ButtonState_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"input",0);
  tolua_beginmodule(tolua_S,"input");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"ButtonState","ButtonState","",tolua_collect_ButtonState);
   #else
   tolua_cclass(tolua_S,"ButtonState","ButtonState","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"ButtonState");
    tolua_function(tolua_S,"new",tolua_aps_input_ButtonState_input_ButtonState_new00);
    tolua_function(tolua_S,"new_local",tolua_aps_input_ButtonState_input_ButtonState_new00_local);
    tolua_function(tolua_S,".call",tolua_aps_input_ButtonState_input_ButtonState_new00_local);
    tolua_function(tolua_S,"pressed",tolua_aps_input_ButtonState_input_ButtonState_pressed00);
    tolua_function(tolua_S,"just",tolua_aps_input_ButtonState_input_ButtonState_just00);
    tolua_function(tolua_S,"holdingTime",tolua_aps_input_ButtonState_input_ButtonState_holdingTime00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_aps_input_ButtonState (lua_State* tolua_S) {
 return tolua_aps_input_ButtonState_open(tolua_S);
};
#endif

