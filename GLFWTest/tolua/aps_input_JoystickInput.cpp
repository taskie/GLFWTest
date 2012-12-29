/*
** Lua binding: aps_input_JoystickInput
** Generated automatically by tolua++-1.0.92 on Fri Dec 28 00:14:46 2012.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_aps_input_JoystickInput_open (lua_State* tolua_S);

#include "../aps/input/JoystickInput.h"
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
 tolua_usertype(tolua_S,"JoystickInput");
 tolua_usertype(tolua_S,"XYState");
 tolua_usertype(tolua_S,"ButtonState");
}

/* method: buttonState of class  JoystickInput */
#ifndef TOLUA_DISABLE_tolua_aps_input_JoystickInput_input_JoystickInput_buttonState00
static int tolua_aps_input_JoystickInput_input_JoystickInput_buttonState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const JoystickInput",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const JoystickInput* self = (const JoystickInput*)  tolua_tousertype(tolua_S,1,0);
  int num = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'buttonState'", NULL);
#endif
  {
   ButtonState tolua_ret = (ButtonState)  self->buttonState(num);
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
 tolua_error(tolua_S,"#ferror in function 'buttonState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: xyState of class  JoystickInput */
#ifndef TOLUA_DISABLE_tolua_aps_input_JoystickInput_input_JoystickInput_xyState00
static int tolua_aps_input_JoystickInput_input_JoystickInput_xyState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const JoystickInput",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const JoystickInput* self = (const JoystickInput*)  tolua_tousertype(tolua_S,1,0);
  int num = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'xyState'", NULL);
#endif
  {
   XYState tolua_ret = (XYState)  self->xyState(num);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((XYState)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"XYState");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(XYState));
     tolua_pushusertype(tolua_S,tolua_obj,"XYState");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'xyState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_aps_input_JoystickInput_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"input",0);
  tolua_beginmodule(tolua_S,"input");
   tolua_cclass(tolua_S,"JoystickInput","JoystickInput","",NULL);
   tolua_beginmodule(tolua_S,"JoystickInput");
    tolua_function(tolua_S,"buttonState",tolua_aps_input_JoystickInput_input_JoystickInput_buttonState00);
    tolua_function(tolua_S,"xyState",tolua_aps_input_JoystickInput_input_JoystickInput_xyState00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_aps_input_JoystickInput (lua_State* tolua_S) {
 return tolua_aps_input_JoystickInput_open(tolua_S);
};
#endif

