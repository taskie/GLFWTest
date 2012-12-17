/*
** Lua binding: aps_fontex_Fontex
** Generated automatically by tolua++-1.0.92 on Thu Dec  6 16:46:29 2012.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_aps_fontex_Fontex_open (lua_State* tolua_S);

#include "../aps/fontex/Fontex.h"
using namespace aps::fontex;
using namespace aps::gl;
using namespace aps::font;

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_ShapeContainer (lua_State* tolua_S)
{
 ShapeContainer* self = (ShapeContainer*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Fontex (lua_State* tolua_S)
{
 Fontex* self = (Fontex*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_StringShape (lua_State* tolua_S)
{
 StringShape* self = (StringShape*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"StringShape");
 tolua_usertype(tolua_S,"ShapeContainer");
 tolua_usertype(tolua_S,"Manager");
 tolua_usertype(tolua_S,"Color");
 tolua_usertype(tolua_S,"Fontex");
}

/* method: new of class  StringShape */
#ifndef TOLUA_DISABLE_tolua_aps_fontex_Fontex_fontex_StringShape_new00
static int tolua_aps_fontex_Fontex_fontex_StringShape_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"StringShape",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ShapeContainer",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShapeContainer shape = *((ShapeContainer*)  tolua_tousertype(tolua_S,2,0));
  int size = ((int)  tolua_tonumber(tolua_S,3,0));
  int width = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   StringShape* tolua_ret = (StringShape*)  Mtolua_new((StringShape)(shape,size,width));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"StringShape");
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

/* method: new_local of class  StringShape */
#ifndef TOLUA_DISABLE_tolua_aps_fontex_Fontex_fontex_StringShape_new00_local
static int tolua_aps_fontex_Fontex_fontex_StringShape_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"StringShape",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ShapeContainer",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShapeContainer shape = *((ShapeContainer*)  tolua_tousertype(tolua_S,2,0));
  int size = ((int)  tolua_tonumber(tolua_S,3,0));
  int width = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   StringShape* tolua_ret = (StringShape*)  Mtolua_new((StringShape)(shape,size,width));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"StringShape");
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

/* method: get of class  StringShape */
#ifndef TOLUA_DISABLE_tolua_aps_fontex_Fontex_fontex_StringShape_get00
static int tolua_aps_fontex_Fontex_fontex_StringShape_get00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"StringShape",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  StringShape* self = (StringShape*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get'", NULL);
#endif
  {
   ShapeContainer tolua_ret = (ShapeContainer)  self->get();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((ShapeContainer)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"ShapeContainer");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(ShapeContainer));
     tolua_pushusertype(tolua_S,tolua_obj,"ShapeContainer");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: size of class  StringShape */
#ifndef TOLUA_DISABLE_tolua_aps_fontex_Fontex_fontex_StringShape_size00
static int tolua_aps_fontex_Fontex_fontex_StringShape_size00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"StringShape",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  StringShape* self = (StringShape*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'size'", NULL);
#endif
  {
   int tolua_ret = (int)  self->size();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'size'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: width of class  StringShape */
#ifndef TOLUA_DISABLE_tolua_aps_fontex_Fontex_fontex_StringShape_width00
static int tolua_aps_fontex_Fontex_fontex_StringShape_width00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"StringShape",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  StringShape* self = (StringShape*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'width'", NULL);
#endif
  {
   int tolua_ret = (int)  self->width();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'width'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Fontex */
#ifndef TOLUA_DISABLE_tolua_aps_fontex_Fontex_fontex_Fontex_new00
static int tolua_aps_fontex_Fontex_fontex_Fontex_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Fontex",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Manager",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Manager fontManager = *((Manager*)  tolua_tousertype(tolua_S,2,0));
  {
   Fontex* tolua_ret = (Fontex*)  Mtolua_new((Fontex)(fontManager));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Fontex");
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

/* method: new_local of class  Fontex */
#ifndef TOLUA_DISABLE_tolua_aps_fontex_Fontex_fontex_Fontex_new00_local
static int tolua_aps_fontex_Fontex_fontex_Fontex_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Fontex",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Manager",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Manager fontManager = *((Manager*)  tolua_tousertype(tolua_S,2,0));
  {
   Fontex* tolua_ret = (Fontex*)  Mtolua_new((Fontex)(fontManager));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Fontex");
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

/* method: utf8StringShape of class  Fontex */
#ifndef TOLUA_DISABLE_tolua_aps_fontex_Fontex_fontex_Fontex_utf8StringShape00
static int tolua_aps_fontex_Fontex_fontex_Fontex_utf8StringShape00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Fontex",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Fontex* self = (Fontex*)  tolua_tousertype(tolua_S,1,0);
  std::string text = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  std::string fontName = ((std::string)  tolua_tocppstring(tolua_S,3,0));
  int size = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'utf8StringShape'", NULL);
#endif
  {
   StringShape tolua_ret = (StringShape)  self->utf8StringShape(text,fontName,size);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((StringShape)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"StringShape");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(StringShape));
     tolua_pushusertype(tolua_S,tolua_obj,"StringShape");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'utf8StringShape'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: utf8StringShape of class  Fontex */
#ifndef TOLUA_DISABLE_tolua_aps_fontex_Fontex_fontex_Fontex_utf8StringShape01
static int tolua_aps_fontex_Fontex_fontex_Fontex_utf8StringShape01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Fontex",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Fontex* self = (Fontex*)  tolua_tousertype(tolua_S,1,0);
  std::string text = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  std::string fontName = ((std::string)  tolua_tocppstring(tolua_S,3,0));
  int size = ((int)  tolua_tonumber(tolua_S,4,0));
  Color color = *((Color*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'utf8StringShape'", NULL);
#endif
  {
   StringShape tolua_ret = (StringShape)  self->utf8StringShape(text,fontName,size,color);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((StringShape)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"StringShape");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(StringShape));
     tolua_pushusertype(tolua_S,tolua_obj,"StringShape");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_aps_fontex_Fontex_fontex_Fontex_utf8StringShape00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_aps_fontex_Fontex_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"fontex",0);
  tolua_beginmodule(tolua_S,"fontex");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"StringShape","StringShape","",tolua_collect_StringShape);
   #else
   tolua_cclass(tolua_S,"StringShape","StringShape","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"StringShape");
    tolua_function(tolua_S,"new",tolua_aps_fontex_Fontex_fontex_StringShape_new00);
    tolua_function(tolua_S,"new_local",tolua_aps_fontex_Fontex_fontex_StringShape_new00_local);
    tolua_function(tolua_S,".call",tolua_aps_fontex_Fontex_fontex_StringShape_new00_local);
    tolua_function(tolua_S,"get",tolua_aps_fontex_Fontex_fontex_StringShape_get00);
    tolua_function(tolua_S,"size",tolua_aps_fontex_Fontex_fontex_StringShape_size00);
    tolua_function(tolua_S,"width",tolua_aps_fontex_Fontex_fontex_StringShape_width00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Fontex","Fontex","",tolua_collect_Fontex);
   #else
   tolua_cclass(tolua_S,"Fontex","Fontex","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Fontex");
    tolua_function(tolua_S,"new",tolua_aps_fontex_Fontex_fontex_Fontex_new00);
    tolua_function(tolua_S,"new_local",tolua_aps_fontex_Fontex_fontex_Fontex_new00_local);
    tolua_function(tolua_S,".call",tolua_aps_fontex_Fontex_fontex_Fontex_new00_local);
    tolua_function(tolua_S,"utf8StringShape",tolua_aps_fontex_Fontex_fontex_Fontex_utf8StringShape00);
    tolua_function(tolua_S,"utf8StringShape",tolua_aps_fontex_Fontex_fontex_Fontex_utf8StringShape01);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_aps_fontex_Fontex (lua_State* tolua_S) {
 return tolua_aps_fontex_Fontex_open(tolua_S);
};
#endif

