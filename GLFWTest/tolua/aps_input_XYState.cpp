/*
** Lua binding: aps_input_XYState
** Generated automatically by tolua++-1.0.92 on 08/11/13 02:56:58.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_aps_input_XYState_open (lua_State* tolua_S);

#include "../aps/input/XYState.h"
using namespace aps::input;

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_XYState (lua_State* tolua_S)
{
 XYState* self = (XYState*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

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
 tolua_usertype(tolua_S,"XYState");
}

/* method: new of class  XYState */
#ifndef TOLUA_DISABLE_tolua_aps_input_XYState_input_XYState_new00
static int tolua_aps_input_XYState_input_XYState_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"XYState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   XYState* tolua_ret = (XYState*)  Mtolua_new((XYState)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"XYState");
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

/* method: new_local of class  XYState */
#ifndef TOLUA_DISABLE_tolua_aps_input_XYState_input_XYState_new00_local
static int tolua_aps_input_XYState_input_XYState_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"XYState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   XYState* tolua_ret = (XYState*)  Mtolua_new((XYState)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"XYState");
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

/* method: setXY of class  XYState */
#ifndef TOLUA_DISABLE_tolua_aps_input_XYState_input_XYState_setXY00
static int tolua_aps_input_XYState_input_XYState_setXY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"XYState",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  XYState* self = (XYState*)  tolua_tousertype(tolua_S,1,0);
  double x = ((double)  tolua_tonumber(tolua_S,2,0));
  double y = ((double)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setXY'", NULL);
#endif
  {
   self->setXY(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setXY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: x of class  XYState */
#ifndef TOLUA_DISABLE_tolua_aps_input_XYState_input_XYState_x00
static int tolua_aps_input_XYState_input_XYState_x00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const XYState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const XYState* self = (const XYState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'x'", NULL);
#endif
  {
   double tolua_ret = (double)  self->x();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'x'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: y of class  XYState */
#ifndef TOLUA_DISABLE_tolua_aps_input_XYState_input_XYState_y00
static int tolua_aps_input_XYState_input_XYState_y00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const XYState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const XYState* self = (const XYState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'y'", NULL);
#endif
  {
   double tolua_ret = (double)  self->y();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'y'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: circledX of class  XYState */
#ifndef TOLUA_DISABLE_tolua_aps_input_XYState_input_XYState_circledX00
static int tolua_aps_input_XYState_input_XYState_circledX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const XYState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const XYState* self = (const XYState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'circledX'", NULL);
#endif
  {
   double tolua_ret = (double)  self->circledX();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'circledX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: circledY of class  XYState */
#ifndef TOLUA_DISABLE_tolua_aps_input_XYState_input_XYState_circledY00
static int tolua_aps_input_XYState_input_XYState_circledY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const XYState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const XYState* self = (const XYState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'circledY'", NULL);
#endif
  {
   double tolua_ret = (double)  self->circledY();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'circledY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: direction of class  XYState */
#ifndef TOLUA_DISABLE_tolua_aps_input_XYState_input_XYState_direction00
static int tolua_aps_input_XYState_input_XYState_direction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const XYState",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const XYState* self = (const XYState*)  tolua_tousertype(tolua_S,1,0);
  std::string key = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'direction'", NULL);
#endif
  {
   ButtonState tolua_ret = (ButtonState)  self->direction(key);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((ButtonState)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"ButtonState");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(ButtonState));
     tolua_pushusertype(tolua_S,tolua_obj,"ButtonState");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'direction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_aps_input_XYState_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"input",0);
  tolua_beginmodule(tolua_S,"input");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"XYState","XYState","",tolua_collect_XYState);
   #else
   tolua_cclass(tolua_S,"XYState","XYState","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"XYState");
    tolua_function(tolua_S,"new",tolua_aps_input_XYState_input_XYState_new00);
    tolua_function(tolua_S,"new_local",tolua_aps_input_XYState_input_XYState_new00_local);
    tolua_function(tolua_S,".call",tolua_aps_input_XYState_input_XYState_new00_local);
    tolua_function(tolua_S,"setXY",tolua_aps_input_XYState_input_XYState_setXY00);
    tolua_function(tolua_S,"x",tolua_aps_input_XYState_input_XYState_x00);
    tolua_function(tolua_S,"y",tolua_aps_input_XYState_input_XYState_y00);
    tolua_function(tolua_S,"circledX",tolua_aps_input_XYState_input_XYState_circledX00);
    tolua_function(tolua_S,"circledY",tolua_aps_input_XYState_input_XYState_circledY00);
    tolua_function(tolua_S,"direction",tolua_aps_input_XYState_input_XYState_direction00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_aps_input_XYState (lua_State* tolua_S) {
 return tolua_aps_input_XYState_open(tolua_S);
};
#endif

