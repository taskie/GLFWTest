/*
** Lua binding: aps_input_KeyBoardInput
** Generated automatically by tolua++-1.0.92 on Fri Dec  7 00:51:38 2012.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_aps_input_KeyBoardInput_open (lua_State* tolua_S);

#include "../aps/input/KeyBoardInput.h"
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
 tolua_usertype(tolua_S,"KeyBoardInput");
 tolua_usertype(tolua_S,"ButtonState");
}

/* method: buttonState of class  KeyBoardInput */
#ifndef TOLUA_DISABLE_tolua_aps_input_KeyBoardInput_input_KeyBoardInput_buttonState00
static int tolua_aps_input_KeyBoardInput_input_KeyBoardInput_buttonState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"KeyBoardInput",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  KeyBoardInput* self = (KeyBoardInput*)  tolua_tousertype(tolua_S,1,0);
  std::string key = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'buttonState'", NULL);
#endif
  {
   ButtonState tolua_ret = (ButtonState)  self->buttonState(key);
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

/* Open function */
TOLUA_API int tolua_aps_input_KeyBoardInput_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"input",0);
  tolua_beginmodule(tolua_S,"input");
   tolua_cclass(tolua_S,"KeyBoardInput","KeyBoardInput","",NULL);
   tolua_beginmodule(tolua_S,"KeyBoardInput");
    tolua_function(tolua_S,"buttonState",tolua_aps_input_KeyBoardInput_input_KeyBoardInput_buttonState00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_aps_input_KeyBoardInput (lua_State* tolua_S) {
 return tolua_aps_input_KeyBoardInput_open(tolua_S);
};
#endif

