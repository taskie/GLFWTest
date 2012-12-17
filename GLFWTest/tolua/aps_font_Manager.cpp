/*
** Lua binding: aps_font_Manager
** Generated automatically by tolua++-1.0.92 on Thu Dec  6 17:44:07 2012.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_aps_font_Manager_open (lua_State* tolua_S);

#include "../aps/font/Manager.h"
using namespace aps::font;

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Manager (lua_State* tolua_S)
{
 Manager* self = (Manager*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_GlyphBitmap (lua_State* tolua_S)
{
 GlyphBitmap* self = (GlyphBitmap*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"GlyphBitmap");
 tolua_usertype(tolua_S,"Manager");
}

/* method: new of class  Manager */
#ifndef TOLUA_DISABLE_tolua_aps_font_Manager_font_Manager_new00
static int tolua_aps_font_Manager_font_Manager_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Manager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Manager* tolua_ret = (Manager*)  Mtolua_new((Manager)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Manager");
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

/* method: new_local of class  Manager */
#ifndef TOLUA_DISABLE_tolua_aps_font_Manager_font_Manager_new00_local
static int tolua_aps_font_Manager_font_Manager_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Manager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Manager* tolua_ret = (Manager*)  Mtolua_new((Manager)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Manager");
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

/* method: loadFont of class  Manager */
#ifndef TOLUA_DISABLE_tolua_aps_font_Manager_font_Manager_loadFont00
static int tolua_aps_font_Manager_font_Manager_loadFont00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Manager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Manager* self = (Manager*)  tolua_tousertype(tolua_S,1,0);
  std::string name = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  std::string filePath = ((std::string)  tolua_tocppstring(tolua_S,3,0));
  long faceIndex = ((long)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadFont'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->loadFont(name,filePath,faceIndex);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadFont'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getGlyphBitmap of class  Manager */
#ifndef TOLUA_DISABLE_tolua_aps_font_Manager_font_Manager_getGlyphBitmap00
static int tolua_aps_font_Manager_font_Manager_getGlyphBitmap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Manager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Manager* self = (Manager*)  tolua_tousertype(tolua_S,1,0);
  std::string name = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  unsigned long charCode = ((unsigned long)  tolua_tonumber(tolua_S,3,0));
  int size = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getGlyphBitmap'", NULL);
#endif
  {
   GlyphBitmap tolua_ret = (GlyphBitmap)  self->getGlyphBitmap(name,charCode,size);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((GlyphBitmap)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"GlyphBitmap");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(GlyphBitmap));
     tolua_pushusertype(tolua_S,tolua_obj,"GlyphBitmap");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getGlyphBitmap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: kerning of class  Manager */
#ifndef TOLUA_DISABLE_tolua_aps_font_Manager_font_Manager_kerning00
static int tolua_aps_font_Manager_font_Manager_kerning00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Manager",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Manager* self = (Manager*)  tolua_tousertype(tolua_S,1,0);
  std::string name = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  unsigned int left = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  unsigned int right = ((unsigned int)  tolua_tonumber(tolua_S,4,0));
  int size = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'kerning'", NULL);
#endif
  {
   double tolua_ret = (double)  self->kerning(name,left,right,size);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'kerning'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: errorMessage of class  Manager */
#ifndef TOLUA_DISABLE_tolua_aps_font_Manager_font_Manager_errorMessage00
static int tolua_aps_font_Manager_font_Manager_errorMessage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Manager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Manager* self = (const Manager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'errorMessage'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->errorMessage();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'errorMessage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: errorClear of class  Manager */
#ifndef TOLUA_DISABLE_tolua_aps_font_Manager_font_Manager_errorClear00
static int tolua_aps_font_Manager_font_Manager_errorClear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Manager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Manager* self = (Manager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'errorClear'", NULL);
#endif
  {
   self->errorClear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'errorClear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_aps_font_Manager_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"font",0);
  tolua_beginmodule(tolua_S,"font");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Manager","Manager","",tolua_collect_Manager);
   #else
   tolua_cclass(tolua_S,"Manager","Manager","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Manager");
    tolua_function(tolua_S,"new",tolua_aps_font_Manager_font_Manager_new00);
    tolua_function(tolua_S,"new_local",tolua_aps_font_Manager_font_Manager_new00_local);
    tolua_function(tolua_S,".call",tolua_aps_font_Manager_font_Manager_new00_local);
    tolua_function(tolua_S,"loadFont",tolua_aps_font_Manager_font_Manager_loadFont00);
    tolua_function(tolua_S,"getGlyphBitmap",tolua_aps_font_Manager_font_Manager_getGlyphBitmap00);
    tolua_function(tolua_S,"kerning",tolua_aps_font_Manager_font_Manager_kerning00);
    tolua_function(tolua_S,"errorMessage",tolua_aps_font_Manager_font_Manager_errorMessage00);
    tolua_function(tolua_S,"errorClear",tolua_aps_font_Manager_font_Manager_errorClear00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_aps_font_Manager (lua_State* tolua_S) {
 return tolua_aps_font_Manager_open(tolua_S);
};
#endif

