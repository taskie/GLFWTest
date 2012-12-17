/*
** Lua binding: aps_gl_ShapeElement
** Generated automatically by tolua++-1.0.92 on Fri Dec  7 01:23:09 2012.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_aps_gl_ShapeElement_open (lua_State* tolua_S);

#include "../aps/gl/ShapeElement.h"
using namespace aps::gl;

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_ShapeElement (lua_State* tolua_S)
{
 ShapeElement* self = (ShapeElement*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"ShapeElement");
 tolua_usertype(tolua_S,"Color");
}

/* method: new of class  ShapeElement */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeElement_gl_ShapeElement_new00
static int tolua_aps_gl_ShapeElement_gl_ShapeElement_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ShapeElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ShapeElement* tolua_ret = (ShapeElement*)  Mtolua_new((ShapeElement)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ShapeElement");
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

/* method: new_local of class  ShapeElement */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeElement_gl_ShapeElement_new00_local
static int tolua_aps_gl_ShapeElement_gl_ShapeElement_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ShapeElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ShapeElement* tolua_ret = (ShapeElement*)  Mtolua_new((ShapeElement)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ShapeElement");
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

/* method: vertex of class  ShapeElement */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeElement_gl_ShapeElement_vertex00
static int tolua_aps_gl_ShapeElement_gl_ShapeElement_vertex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShapeElement",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShapeElement* self = (ShapeElement*)  tolua_tousertype(tolua_S,1,0);
  double x = ((double)  tolua_tonumber(tolua_S,2,0));
  double y = ((double)  tolua_tonumber(tolua_S,3,0));
  double z = ((double)  tolua_tonumber(tolua_S,4,0.0));
  double w = ((double)  tolua_tonumber(tolua_S,5,1.0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'vertex'", NULL);
#endif
  {
   ShapeElement& tolua_ret = (ShapeElement&)  self->vertex(x,y,z,w);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"ShapeElement");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'vertex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: color of class  ShapeElement */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeElement_gl_ShapeElement_color00
static int tolua_aps_gl_ShapeElement_gl_ShapeElement_color00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShapeElement",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShapeElement* self = (ShapeElement*)  tolua_tousertype(tolua_S,1,0);
  double r = ((double)  tolua_tonumber(tolua_S,2,0));
  double g = ((double)  tolua_tonumber(tolua_S,3,0));
  double b = ((double)  tolua_tonumber(tolua_S,4,0));
  double a = ((double)  tolua_tonumber(tolua_S,5,1.0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'color'", NULL);
#endif
  {
   ShapeElement& tolua_ret = (ShapeElement&)  self->color(r,g,b,a);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"ShapeElement");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'color'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: color of class  ShapeElement */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeElement_gl_ShapeElement_color01
static int tolua_aps_gl_ShapeElement_gl_ShapeElement_color01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShapeElement",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  ShapeElement* self = (ShapeElement*)  tolua_tousertype(tolua_S,1,0);
  Color color = *((Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'color'", NULL);
#endif
  {
   ShapeElement& tolua_ret = (ShapeElement&)  self->color(color);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"ShapeElement");
  }
 }
 return 1;
tolua_lerror:
 return tolua_aps_gl_ShapeElement_gl_ShapeElement_color00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: texCoord of class  ShapeElement */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeElement_gl_ShapeElement_texCoord00
static int tolua_aps_gl_ShapeElement_gl_ShapeElement_texCoord00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShapeElement",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShapeElement* self = (ShapeElement*)  tolua_tousertype(tolua_S,1,0);
  double s = ((double)  tolua_tonumber(tolua_S,2,0));
  double t = ((double)  tolua_tonumber(tolua_S,3,0.0));
  double r = ((double)  tolua_tonumber(tolua_S,4,0.0));
  double q = ((double)  tolua_tonumber(tolua_S,5,1.0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'texCoord'", NULL);
#endif
  {
   ShapeElement& tolua_ret = (ShapeElement&)  self->texCoord(s,t,r,q);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"ShapeElement");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'texCoord'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw of class  ShapeElement */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeElement_gl_ShapeElement_draw00
static int tolua_aps_gl_ShapeElement_gl_ShapeElement_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShapeElement",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShapeElement* self = (ShapeElement*)  tolua_tousertype(tolua_S,1,0);
  ShapeElement::DrawMode mode = ((ShapeElement::DrawMode) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw'", NULL);
#endif
  {
   ShapeElement& tolua_ret = (ShapeElement&)  self->draw(mode);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"ShapeElement");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rectangle of class  ShapeElement */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeElement_gl_ShapeElement_rectangle00
static int tolua_aps_gl_ShapeElement_gl_ShapeElement_rectangle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShapeElement",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShapeElement* self = (ShapeElement*)  tolua_tousertype(tolua_S,1,0);
  double x = ((double)  tolua_tonumber(tolua_S,2,0));
  double y = ((double)  tolua_tonumber(tolua_S,3,0));
  double w = ((double)  tolua_tonumber(tolua_S,4,0));
  double h = ((double)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rectangle'", NULL);
#endif
  {
   ShapeElement& tolua_ret = (ShapeElement&)  self->rectangle(x,y,w,h);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"ShapeElement");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rectangle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: regularPolygon of class  ShapeElement */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeElement_gl_ShapeElement_regularPolygon00
static int tolua_aps_gl_ShapeElement_gl_ShapeElement_regularPolygon00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShapeElement",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShapeElement* self = (ShapeElement*)  tolua_tousertype(tolua_S,1,0);
  int n = ((int)  tolua_tonumber(tolua_S,2,0));
  double r = ((double)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'regularPolygon'", NULL);
#endif
  {
   ShapeElement& tolua_ret = (ShapeElement&)  self->regularPolygon(n,r);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"ShapeElement");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'regularPolygon'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: circle of class  ShapeElement */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeElement_gl_ShapeElement_circle00
static int tolua_aps_gl_ShapeElement_gl_ShapeElement_circle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShapeElement",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShapeElement* self = (ShapeElement*)  tolua_tousertype(tolua_S,1,0);
  double r = ((double)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'circle'", NULL);
#endif
  {
   ShapeElement& tolua_ret = (ShapeElement&)  self->circle(r);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"ShapeElement");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'circle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_aps_gl_ShapeElement_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"gl",0);
  tolua_beginmodule(tolua_S,"gl");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"ShapeElement","ShapeElement","",tolua_collect_ShapeElement);
   #else
   tolua_cclass(tolua_S,"ShapeElement","ShapeElement","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"ShapeElement");
    tolua_function(tolua_S,"new",tolua_aps_gl_ShapeElement_gl_ShapeElement_new00);
    tolua_function(tolua_S,"new_local",tolua_aps_gl_ShapeElement_gl_ShapeElement_new00_local);
    tolua_function(tolua_S,".call",tolua_aps_gl_ShapeElement_gl_ShapeElement_new00_local);
    tolua_function(tolua_S,"vertex",tolua_aps_gl_ShapeElement_gl_ShapeElement_vertex00);
    tolua_function(tolua_S,"color",tolua_aps_gl_ShapeElement_gl_ShapeElement_color00);
    tolua_function(tolua_S,"color",tolua_aps_gl_ShapeElement_gl_ShapeElement_color01);
    tolua_function(tolua_S,"texCoord",tolua_aps_gl_ShapeElement_gl_ShapeElement_texCoord00);
    tolua_constant(tolua_S,"Point",ShapeElement::Point);
    tolua_constant(tolua_S,"Lines",ShapeElement::Lines);
    tolua_constant(tolua_S,"LineLoop",ShapeElement::LineLoop);
    tolua_constant(tolua_S,"LineStrip",ShapeElement::LineStrip);
    tolua_constant(tolua_S,"Triangles",ShapeElement::Triangles);
    tolua_constant(tolua_S,"TriangleStrip",ShapeElement::TriangleStrip);
    tolua_constant(tolua_S,"PolyGon",ShapeElement::PolyGon);
    tolua_function(tolua_S,"draw",tolua_aps_gl_ShapeElement_gl_ShapeElement_draw00);
    tolua_function(tolua_S,"rectangle",tolua_aps_gl_ShapeElement_gl_ShapeElement_rectangle00);
    tolua_function(tolua_S,"regularPolygon",tolua_aps_gl_ShapeElement_gl_ShapeElement_regularPolygon00);
    tolua_function(tolua_S,"circle",tolua_aps_gl_ShapeElement_gl_ShapeElement_circle00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_aps_gl_ShapeElement (lua_State* tolua_S) {
 return tolua_aps_gl_ShapeElement_open(tolua_S);
};
#endif

