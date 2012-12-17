/*
** Lua binding: aps_gl_Texture2D
** Generated automatically by tolua++-1.0.92 on Thu Dec  6 16:46:29 2012.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_aps_gl_Texture2D_open (lua_State* tolua_S);

#include "../aps/gl/Texture2D.h"
using namespace aps::gl;

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Texture2D (lua_State* tolua_S)
{
 Texture2D* self = (Texture2D*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"std::unordered_map<GLenum,GLenum>");
 tolua_usertype(tolua_S,"Texture2D");
}

/* method: new of class  Texture2D */
#ifndef TOLUA_DISABLE_tolua_aps_gl_Texture2D_gl_Texture2D_new00
static int tolua_aps_gl_Texture2D_gl_Texture2D_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Texture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  unsigned int textureId = (( unsigned int)  tolua_tonumber(tolua_S,2,0));
  unsigned int rawWidth = (( unsigned int)  tolua_tonumber(tolua_S,3,0));
  unsigned int rawHeight = (( unsigned int)  tolua_tonumber(tolua_S,4,0));
  unsigned int width = (( unsigned int)  tolua_tonumber(tolua_S,5,0));
  unsigned int height = (( unsigned int)  tolua_tonumber(tolua_S,6,0));
  {
   Texture2D* tolua_ret = (Texture2D*)  Mtolua_new((Texture2D)(textureId,rawWidth,rawHeight,width,height));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Texture2D");
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

/* method: new_local of class  Texture2D */
#ifndef TOLUA_DISABLE_tolua_aps_gl_Texture2D_gl_Texture2D_new00_local
static int tolua_aps_gl_Texture2D_gl_Texture2D_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Texture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  unsigned int textureId = (( unsigned int)  tolua_tonumber(tolua_S,2,0));
  unsigned int rawWidth = (( unsigned int)  tolua_tonumber(tolua_S,3,0));
  unsigned int rawHeight = (( unsigned int)  tolua_tonumber(tolua_S,4,0));
  unsigned int width = (( unsigned int)  tolua_tonumber(tolua_S,5,0));
  unsigned int height = (( unsigned int)  tolua_tonumber(tolua_S,6,0));
  {
   Texture2D* tolua_ret = (Texture2D*)  Mtolua_new((Texture2D)(textureId,rawWidth,rawHeight,width,height));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Texture2D");
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

/* method: new of class  Texture2D */
#ifndef TOLUA_DISABLE_tolua_aps_gl_Texture2D_gl_Texture2D_new01
static int tolua_aps_gl_Texture2D_gl_Texture2D_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Texture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  unsigned int rawWidth = (( unsigned int)  tolua_tonumber(tolua_S,2,0));
  unsigned int rawHeight = (( unsigned int)  tolua_tonumber(tolua_S,3,0));
  unsigned int width = (( unsigned int)  tolua_tonumber(tolua_S,4,0));
  unsigned int height = (( unsigned int)  tolua_tonumber(tolua_S,5,0));
  {
   Texture2D* tolua_ret = (Texture2D*)  Mtolua_new((Texture2D)(rawWidth,rawHeight,width,height));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Texture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_aps_gl_Texture2D_gl_Texture2D_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Texture2D */
#ifndef TOLUA_DISABLE_tolua_aps_gl_Texture2D_gl_Texture2D_new01_local
static int tolua_aps_gl_Texture2D_gl_Texture2D_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Texture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  unsigned int rawWidth = (( unsigned int)  tolua_tonumber(tolua_S,2,0));
  unsigned int rawHeight = (( unsigned int)  tolua_tonumber(tolua_S,3,0));
  unsigned int width = (( unsigned int)  tolua_tonumber(tolua_S,4,0));
  unsigned int height = (( unsigned int)  tolua_tonumber(tolua_S,5,0));
  {
   Texture2D* tolua_ret = (Texture2D*)  Mtolua_new((Texture2D)(rawWidth,rawHeight,width,height));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Texture2D");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_aps_gl_Texture2D_gl_Texture2D_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Texture2D */
#ifndef TOLUA_DISABLE_tolua_aps_gl_Texture2D_gl_Texture2D_delete00
static int tolua_aps_gl_Texture2D_gl_Texture2D_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Texture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Texture2D* self = (Texture2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rawWidth of class  Texture2D */
#ifndef TOLUA_DISABLE_tolua_aps_gl_Texture2D_gl_Texture2D_rawWidth00
static int tolua_aps_gl_Texture2D_gl_Texture2D_rawWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Texture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Texture2D* self = (Texture2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rawWidth'", NULL);
#endif
  {
   unsigned int tolua_ret = ( unsigned int)  self->rawWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rawWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rawHeight of class  Texture2D */
#ifndef TOLUA_DISABLE_tolua_aps_gl_Texture2D_gl_Texture2D_rawHeight00
static int tolua_aps_gl_Texture2D_gl_Texture2D_rawHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Texture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Texture2D* self = (Texture2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rawHeight'", NULL);
#endif
  {
   unsigned int tolua_ret = ( unsigned int)  self->rawHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rawHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: width of class  Texture2D */
#ifndef TOLUA_DISABLE_tolua_aps_gl_Texture2D_gl_Texture2D_width00
static int tolua_aps_gl_Texture2D_gl_Texture2D_width00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Texture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Texture2D* self = (Texture2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'width'", NULL);
#endif
  {
   unsigned int tolua_ret = ( unsigned int)  self->width();
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

/* method: height of class  Texture2D */
#ifndef TOLUA_DISABLE_tolua_aps_gl_Texture2D_gl_Texture2D_height00
static int tolua_aps_gl_Texture2D_gl_Texture2D_height00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Texture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Texture2D* self = (Texture2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'height'", NULL);
#endif
  {
   unsigned int tolua_ret = ( unsigned int)  self->height();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'height'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: bind of class  Texture2D */
#ifndef TOLUA_DISABLE_tolua_aps_gl_Texture2D_gl_Texture2D_bind00
static int tolua_aps_gl_Texture2D_gl_Texture2D_bind00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Texture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Texture2D* self = (Texture2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'bind'", NULL);
#endif
  {
   Texture2D& tolua_ret = (Texture2D&)  self->bind();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Texture2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'bind'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unbind of class  Texture2D */
#ifndef TOLUA_DISABLE_tolua_aps_gl_Texture2D_gl_Texture2D_unbind00
static int tolua_aps_gl_Texture2D_gl_Texture2D_unbind00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Texture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Texture2D* self = (Texture2D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unbind'", NULL);
#endif
  {
   Texture2D& tolua_ret = (Texture2D&)  self->unbind();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Texture2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unbind'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: image2D of class  Texture2D */
#ifndef TOLUA_DISABLE_tolua_aps_gl_Texture2D_gl_Texture2D_image2D00
static int tolua_aps_gl_Texture2D_gl_Texture2D_image2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Texture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Texture2D* self = (Texture2D*)  tolua_tousertype(tolua_S,1,0);
  unsigned int target = (( unsigned int)  tolua_tonumber(tolua_S,2,0));
   int level = ((  int)  tolua_tonumber(tolua_S,3,0));
   int internalFormat = ((  int)  tolua_tonumber(tolua_S,4,0));
  unsigned int format = (( unsigned int)  tolua_tonumber(tolua_S,5,0));
  unsigned int type = (( unsigned int)  tolua_tonumber(tolua_S,6,0));
  const void* data = ((const void*)  tolua_touserdata(tolua_S,7,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'image2D'", NULL);
#endif
  {
   Texture2D& tolua_ret = (Texture2D&)  self->image2D(target,level,internalFormat,format,type,data);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Texture2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'image2D'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: parameter of class  Texture2D */
#ifndef TOLUA_DISABLE_tolua_aps_gl_Texture2D_gl_Texture2D_parameter00
static int tolua_aps_gl_Texture2D_gl_Texture2D_parameter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Texture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Texture2D* self = (Texture2D*)  tolua_tousertype(tolua_S,1,0);
  unsigned int key = (( unsigned int)  tolua_tonumber(tolua_S,2,0));
  unsigned int value = (( unsigned int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'parameter'", NULL);
#endif
  {
   Texture2D& tolua_ret = (Texture2D&)  self->parameter(key,value);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Texture2D");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'parameter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: parameter of class  Texture2D */
#ifndef TOLUA_DISABLE_tolua_aps_gl_Texture2D_gl_Texture2D_parameter01
static int tolua_aps_gl_Texture2D_gl_Texture2D_parameter01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Texture2D",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::unordered_map<GLenum,GLenum>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Texture2D* self = (Texture2D*)  tolua_tousertype(tolua_S,1,0);
  std::unordered_map<GLenum,GLenum> parameter = *((std::unordered_map<GLenum,GLenum>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'parameter'", NULL);
#endif
  {
   Texture2D& tolua_ret = (Texture2D&)  self->parameter(parameter);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Texture2D");
  }
 }
 return 1;
tolua_lerror:
 return tolua_aps_gl_Texture2D_gl_Texture2D_parameter00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: fromData of class  Texture2D */
#ifndef TOLUA_DISABLE_tolua_aps_gl_Texture2D_gl_Texture2D_fromData00
static int tolua_aps_gl_Texture2D_gl_Texture2D_fromData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Texture2D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  unsigned const char data = ((unsigned const char)  tolua_tonumber(tolua_S,2,0));
  int width = ((int)  tolua_tonumber(tolua_S,3,0));
  int height = ((int)  tolua_tonumber(tolua_S,4,0));
  {
   Texture2D tolua_ret = (Texture2D)  Texture2D::fromData(&data,width,height);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Texture2D)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Texture2D");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Texture2D));
     tolua_pushusertype(tolua_S,tolua_obj,"Texture2D");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
   tolua_pushnumber(tolua_S,(lua_Number)data);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fromData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_aps_gl_Texture2D_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"gl",0);
  tolua_beginmodule(tolua_S,"gl");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Texture2D","Texture2D","",tolua_collect_Texture2D);
   #else
   tolua_cclass(tolua_S,"Texture2D","Texture2D","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Texture2D");
    tolua_function(tolua_S,"new",tolua_aps_gl_Texture2D_gl_Texture2D_new00);
    tolua_function(tolua_S,"new_local",tolua_aps_gl_Texture2D_gl_Texture2D_new00_local);
    tolua_function(tolua_S,".call",tolua_aps_gl_Texture2D_gl_Texture2D_new00_local);
    tolua_function(tolua_S,"new",tolua_aps_gl_Texture2D_gl_Texture2D_new01);
    tolua_function(tolua_S,"new_local",tolua_aps_gl_Texture2D_gl_Texture2D_new01_local);
    tolua_function(tolua_S,".call",tolua_aps_gl_Texture2D_gl_Texture2D_new01_local);
    tolua_function(tolua_S,"delete",tolua_aps_gl_Texture2D_gl_Texture2D_delete00);
    tolua_function(tolua_S,"rawWidth",tolua_aps_gl_Texture2D_gl_Texture2D_rawWidth00);
    tolua_function(tolua_S,"rawHeight",tolua_aps_gl_Texture2D_gl_Texture2D_rawHeight00);
    tolua_function(tolua_S,"width",tolua_aps_gl_Texture2D_gl_Texture2D_width00);
    tolua_function(tolua_S,"height",tolua_aps_gl_Texture2D_gl_Texture2D_height00);
    tolua_function(tolua_S,"bind",tolua_aps_gl_Texture2D_gl_Texture2D_bind00);
    tolua_function(tolua_S,"unbind",tolua_aps_gl_Texture2D_gl_Texture2D_unbind00);
    tolua_function(tolua_S,"image2D",tolua_aps_gl_Texture2D_gl_Texture2D_image2D00);
    tolua_function(tolua_S,"parameter",tolua_aps_gl_Texture2D_gl_Texture2D_parameter00);
    tolua_function(tolua_S,"parameter",tolua_aps_gl_Texture2D_gl_Texture2D_parameter01);
    tolua_function(tolua_S,"fromData",tolua_aps_gl_Texture2D_gl_Texture2D_fromData00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_aps_gl_Texture2D (lua_State* tolua_S) {
 return tolua_aps_gl_Texture2D_open(tolua_S);
};
#endif

