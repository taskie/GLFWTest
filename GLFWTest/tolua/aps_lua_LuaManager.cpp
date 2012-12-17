/*
** Lua binding: aps_lua_LuaManager
** Generated automatically by tolua++-1.0.92 on Thu Dec  6 17:44:07 2012.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_aps_lua_LuaManager_open (lua_State* tolua_S);

#include "../aps/lua/LuaManager.h"
using namespace aps::lua;

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"LuaManager");
}

/* method: doFile of class  LuaManager */
#ifndef TOLUA_DISABLE_tolua_aps_lua_LuaManager_lua_LuaManager_doFile00
static int tolua_aps_lua_LuaManager_lua_LuaManager_doFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaManager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaManager* self = (LuaManager*)  tolua_tousertype(tolua_S,1,0);
  std::string path = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doFile'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->doFile(path);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_aps_lua_LuaManager_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"lua",0);
  tolua_beginmodule(tolua_S,"lua");
   tolua_cclass(tolua_S,"LuaManager","LuaManager","",NULL);
   tolua_beginmodule(tolua_S,"LuaManager");
    tolua_function(tolua_S,"doFile",tolua_aps_lua_LuaManager_lua_LuaManager_doFile00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_aps_lua_LuaManager (lua_State* tolua_S) {
 return tolua_aps_lua_LuaManager_open(tolua_S);
};
#endif

