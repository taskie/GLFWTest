/*
** Lua binding: aps_gl_ShapeContainer
** Generated automatically by tolua++-1.0.92 on Tue Dec 11 04:54:44 2012.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_aps_gl_ShapeContainer_open (lua_State* tolua_S);

#include "../aps/gl/ShapeContainer.h"
using namespace aps::gl;

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_ShapeContainer (lua_State* tolua_S)
{
 ShapeContainer* self = (ShapeContainer*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_std__array_double_3_ (lua_State* tolua_S)
{
 std::array<double,3>* self = (std::array<double,3>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_std__array_double_4_ (lua_State* tolua_S)
{
 std::array<double,4>* self = (std::array<double,4>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"std::array<double,3>");
 tolua_usertype(tolua_S,"Texture2D");
 tolua_usertype(tolua_S,"ShapeContainer");
 tolua_usertype(tolua_S,"ShapeElement");
 tolua_usertype(tolua_S,"std::array<double,4>");
 tolua_usertype(tolua_S,"Color");
}

/* method: new of class  ShapeContainer */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeContainer_gl_ShapeContainer_new00
static int tolua_aps_gl_ShapeContainer_gl_ShapeContainer_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ShapeContainer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ShapeContainer* tolua_ret = (ShapeContainer*)  Mtolua_new((ShapeContainer)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ShapeContainer");
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

/* method: new_local of class  ShapeContainer */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeContainer_gl_ShapeContainer_new00_local
static int tolua_aps_gl_ShapeContainer_gl_ShapeContainer_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ShapeContainer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ShapeContainer* tolua_ret = (ShapeContainer*)  Mtolua_new((ShapeContainer)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ShapeContainer");
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

/* method: new of class  ShapeContainer */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeContainer_gl_ShapeContainer_new01
static int tolua_aps_gl_ShapeContainer_gl_ShapeContainer_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ShapeContainer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ShapeElement",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  ShapeElement shapeElement = *((ShapeElement*)  tolua_tousertype(tolua_S,2,0));
  {
   ShapeContainer* tolua_ret = (ShapeContainer*)  Mtolua_new((ShapeContainer)(shapeElement));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ShapeContainer");
  }
 }
 return 1;
tolua_lerror:
 return tolua_aps_gl_ShapeContainer_gl_ShapeContainer_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  ShapeContainer */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeContainer_gl_ShapeContainer_new01_local
static int tolua_aps_gl_ShapeContainer_gl_ShapeContainer_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ShapeContainer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ShapeElement",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  ShapeElement shapeElement = *((ShapeElement*)  tolua_tousertype(tolua_S,2,0));
  {
   ShapeContainer* tolua_ret = (ShapeContainer*)  Mtolua_new((ShapeContainer)(shapeElement));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ShapeContainer");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_aps_gl_ShapeContainer_gl_ShapeContainer_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  ShapeContainer */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeContainer_gl_ShapeContainer_delete00
static int tolua_aps_gl_ShapeContainer_gl_ShapeContainer_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShapeContainer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShapeContainer* self = (ShapeContainer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: point of class  ShapeContainer */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeContainer_gl_ShapeContainer_point00
static int tolua_aps_gl_ShapeContainer_gl_ShapeContainer_point00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShapeContainer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShapeContainer* self = (ShapeContainer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'point'", NULL);
#endif
  {
   ShapeContainer& tolua_ret = (ShapeContainer&)  self->point();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"ShapeContainer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'point'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: lines of class  ShapeContainer */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeContainer_gl_ShapeContainer_lines00
static int tolua_aps_gl_ShapeContainer_gl_ShapeContainer_lines00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShapeContainer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShapeContainer* self = (ShapeContainer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'lines'", NULL);
#endif
  {
   ShapeContainer& tolua_ret = (ShapeContainer&)  self->lines();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"ShapeContainer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'lines'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: lineLoop of class  ShapeContainer */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeContainer_gl_ShapeContainer_lineLoop00
static int tolua_aps_gl_ShapeContainer_gl_ShapeContainer_lineLoop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShapeContainer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShapeContainer* self = (ShapeContainer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'lineLoop'", NULL);
#endif
  {
   ShapeContainer& tolua_ret = (ShapeContainer&)  self->lineLoop();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"ShapeContainer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'lineLoop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: lineStrip of class  ShapeContainer */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeContainer_gl_ShapeContainer_lineStrip00
static int tolua_aps_gl_ShapeContainer_gl_ShapeContainer_lineStrip00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShapeContainer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShapeContainer* self = (ShapeContainer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'lineStrip'", NULL);
#endif
  {
   ShapeContainer& tolua_ret = (ShapeContainer&)  self->lineStrip();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"ShapeContainer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'lineStrip'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: triangles of class  ShapeContainer */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeContainer_gl_ShapeContainer_triangles00
static int tolua_aps_gl_ShapeContainer_gl_ShapeContainer_triangles00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShapeContainer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShapeContainer* self = (ShapeContainer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'triangles'", NULL);
#endif
  {
   ShapeContainer& tolua_ret = (ShapeContainer&)  self->triangles();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"ShapeContainer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'triangles'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: triangleStrip of class  ShapeContainer */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeContainer_gl_ShapeContainer_triangleStrip00
static int tolua_aps_gl_ShapeContainer_gl_ShapeContainer_triangleStrip00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShapeContainer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShapeContainer* self = (ShapeContainer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'triangleStrip'", NULL);
#endif
  {
   ShapeContainer& tolua_ret = (ShapeContainer&)  self->triangleStrip();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"ShapeContainer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'triangleStrip'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: polygon of class  ShapeContainer */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeContainer_gl_ShapeContainer_polygon00
static int tolua_aps_gl_ShapeContainer_gl_ShapeContainer_polygon00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShapeContainer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShapeContainer* self = (ShapeContainer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'polygon'", NULL);
#endif
  {
   ShapeContainer& tolua_ret = (ShapeContainer&)  self->polygon();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"ShapeContainer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'polygon'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAnchor of class  ShapeContainer */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeContainer_gl_ShapeContainer_setAnchor00
static int tolua_aps_gl_ShapeContainer_gl_ShapeContainer_setAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShapeContainer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShapeContainer* self = (ShapeContainer*)  tolua_tousertype(tolua_S,1,0);
  double x = ((double)  tolua_tonumber(tolua_S,2,0));
  double y = ((double)  tolua_tonumber(tolua_S,3,0));
  double z = ((double)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAnchor'", NULL);
#endif
  {
   ShapeContainer& tolua_ret = (ShapeContainer&)  self->setAnchor(x,y,z);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"ShapeContainer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPosition of class  ShapeContainer */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeContainer_gl_ShapeContainer_setPosition00
static int tolua_aps_gl_ShapeContainer_gl_ShapeContainer_setPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShapeContainer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShapeContainer* self = (ShapeContainer*)  tolua_tousertype(tolua_S,1,0);
  double x = ((double)  tolua_tonumber(tolua_S,2,0));
  double y = ((double)  tolua_tonumber(tolua_S,3,0));
  double z = ((double)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPosition'", NULL);
#endif
  {
   ShapeContainer& tolua_ret = (ShapeContainer&)  self->setPosition(x,y,z);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"ShapeContainer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScale of class  ShapeContainer */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeContainer_gl_ShapeContainer_setScale00
static int tolua_aps_gl_ShapeContainer_gl_ShapeContainer_setScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShapeContainer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShapeContainer* self = (ShapeContainer*)  tolua_tousertype(tolua_S,1,0);
  double scale = ((double)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScale'", NULL);
#endif
  {
   ShapeContainer& tolua_ret = (ShapeContainer&)  self->setScale(scale);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"ShapeContainer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScale of class  ShapeContainer */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeContainer_gl_ShapeContainer_setScale01
static int tolua_aps_gl_ShapeContainer_gl_ShapeContainer_setScale01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShapeContainer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  ShapeContainer* self = (ShapeContainer*)  tolua_tousertype(tolua_S,1,0);
  double x = ((double)  tolua_tonumber(tolua_S,2,0));
  double y = ((double)  tolua_tonumber(tolua_S,3,0));
  double z = ((double)  tolua_tonumber(tolua_S,4,1));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScale'", NULL);
#endif
  {
   ShapeContainer& tolua_ret = (ShapeContainer&)  self->setScale(x,y,z);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"ShapeContainer");
  }
 }
 return 1;
tolua_lerror:
 return tolua_aps_gl_ShapeContainer_gl_ShapeContainer_setScale00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRotate of class  ShapeContainer */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeContainer_gl_ShapeContainer_setRotate00
static int tolua_aps_gl_ShapeContainer_gl_ShapeContainer_setRotate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShapeContainer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShapeContainer* self = (ShapeContainer*)  tolua_tousertype(tolua_S,1,0);
  double angle = ((double)  tolua_tonumber(tolua_S,2,0));
  double x = ((double)  tolua_tonumber(tolua_S,3,0));
  double y = ((double)  tolua_tonumber(tolua_S,4,0));
  double z = ((double)  tolua_tonumber(tolua_S,5,1));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRotate'", NULL);
#endif
  {
   ShapeContainer& tolua_ret = (ShapeContainer&)  self->setRotate(angle,x,y,z);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"ShapeContainer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRotate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setColorForce of class  ShapeContainer */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeContainer_gl_ShapeContainer_setColorForce00
static int tolua_aps_gl_ShapeContainer_gl_ShapeContainer_setColorForce00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShapeContainer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShapeContainer* self = (ShapeContainer*)  tolua_tousertype(tolua_S,1,0);
  Color color = *((Color*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setColorForce'", NULL);
#endif
  {
   ShapeContainer& tolua_ret = (ShapeContainer&)  self->setColorForce(color);
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"ShapeContainer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setColorForce'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: anchor of class  ShapeContainer */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeContainer_gl_ShapeContainer_anchor00
static int tolua_aps_gl_ShapeContainer_gl_ShapeContainer_anchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShapeContainer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShapeContainer* self = (ShapeContainer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'anchor'", NULL);
#endif
  {
   std::array<double,3> tolua_ret = (std::array<double,3>)  self->anchor();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((std::array<double,3>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"std::array<double,3>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(std::array<double,3>));
     tolua_pushusertype(tolua_S,tolua_obj,"std::array<double,3>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'anchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: position of class  ShapeContainer */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeContainer_gl_ShapeContainer_position00
static int tolua_aps_gl_ShapeContainer_gl_ShapeContainer_position00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShapeContainer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShapeContainer* self = (ShapeContainer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'position'", NULL);
#endif
  {
   std::array<double,3> tolua_ret = (std::array<double,3>)  self->position();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((std::array<double,3>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"std::array<double,3>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(std::array<double,3>));
     tolua_pushusertype(tolua_S,tolua_obj,"std::array<double,3>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'position'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scale of class  ShapeContainer */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeContainer_gl_ShapeContainer_scale00
static int tolua_aps_gl_ShapeContainer_gl_ShapeContainer_scale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShapeContainer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShapeContainer* self = (ShapeContainer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scale'", NULL);
#endif
  {
   std::array<double,3> tolua_ret = (std::array<double,3>)  self->scale();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((std::array<double,3>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"std::array<double,3>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(std::array<double,3>));
     tolua_pushusertype(tolua_S,tolua_obj,"std::array<double,3>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotate of class  ShapeContainer */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeContainer_gl_ShapeContainer_rotate00
static int tolua_aps_gl_ShapeContainer_gl_ShapeContainer_rotate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShapeContainer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShapeContainer* self = (ShapeContainer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotate'", NULL);
#endif
  {
   std::array<double,4> tolua_ret = (std::array<double,4>)  self->rotate();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((std::array<double,4>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"std::array<double,4>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(std::array<double,4>));
     tolua_pushusertype(tolua_S,tolua_obj,"std::array<double,4>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pushChild of class  ShapeContainer */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeContainer_gl_ShapeContainer_pushChild00
static int tolua_aps_gl_ShapeContainer_gl_ShapeContainer_pushChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShapeContainer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ShapeContainer",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShapeContainer* self = (ShapeContainer*)  tolua_tousertype(tolua_S,1,0);
  ShapeContainer child = *((ShapeContainer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pushChild'", NULL);
#endif
  {
   self->pushChild(child);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pushChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTexture of class  ShapeContainer */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeContainer_gl_ShapeContainer_setTexture00
static int tolua_aps_gl_ShapeContainer_gl_ShapeContainer_setTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ShapeContainer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Texture2D",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ShapeContainer* self = (ShapeContainer*)  tolua_tousertype(tolua_S,1,0);
  Texture2D texture = *((Texture2D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTexture'", NULL);
#endif
  {
   self->setTexture(texture);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rectWithTexture of class  ShapeContainer */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeContainer_gl_ShapeContainer_rectWithTexture00
static int tolua_aps_gl_ShapeContainer_gl_ShapeContainer_rectWithTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ShapeContainer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Texture2D",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Texture2D texture = *((Texture2D*)  tolua_tousertype(tolua_S,2,0));
  {
   ShapeContainer tolua_ret = (ShapeContainer)  ShapeContainer::rectWithTexture(texture);
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
 tolua_error(tolua_S,"#ferror in function 'rectWithTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rectWithTexture of class  ShapeContainer */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeContainer_gl_ShapeContainer_rectWithTexture01
static int tolua_aps_gl_ShapeContainer_gl_ShapeContainer_rectWithTexture01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ShapeContainer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Texture2D",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Texture2D texture = *((Texture2D*)  tolua_tousertype(tolua_S,2,0));
  Color color = *((Color*)  tolua_tousertype(tolua_S,3,0));
  {
   ShapeContainer tolua_ret = (ShapeContainer)  ShapeContainer::rectWithTexture(texture,color);
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
tolua_lerror:
 return tolua_aps_gl_ShapeContainer_gl_ShapeContainer_rectWithTexture00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw of class  ShapeContainer */
#ifndef TOLUA_DISABLE_tolua_aps_gl_ShapeContainer_gl_ShapeContainer_draw00
static int tolua_aps_gl_ShapeContainer_gl_ShapeContainer_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const ShapeContainer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const ShapeContainer* self = (const ShapeContainer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw'", NULL);
#endif
  {
   self->draw();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_aps_gl_ShapeContainer_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"gl",0);
  tolua_beginmodule(tolua_S,"gl");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"ShapeContainer","ShapeContainer","",tolua_collect_ShapeContainer);
   #else
   tolua_cclass(tolua_S,"ShapeContainer","ShapeContainer","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"ShapeContainer");
    tolua_function(tolua_S,"new",tolua_aps_gl_ShapeContainer_gl_ShapeContainer_new00);
    tolua_function(tolua_S,"new_local",tolua_aps_gl_ShapeContainer_gl_ShapeContainer_new00_local);
    tolua_function(tolua_S,".call",tolua_aps_gl_ShapeContainer_gl_ShapeContainer_new00_local);
    tolua_function(tolua_S,"new",tolua_aps_gl_ShapeContainer_gl_ShapeContainer_new01);
    tolua_function(tolua_S,"new_local",tolua_aps_gl_ShapeContainer_gl_ShapeContainer_new01_local);
    tolua_function(tolua_S,".call",tolua_aps_gl_ShapeContainer_gl_ShapeContainer_new01_local);
    tolua_function(tolua_S,"delete",tolua_aps_gl_ShapeContainer_gl_ShapeContainer_delete00);
    tolua_function(tolua_S,"point",tolua_aps_gl_ShapeContainer_gl_ShapeContainer_point00);
    tolua_function(tolua_S,"lines",tolua_aps_gl_ShapeContainer_gl_ShapeContainer_lines00);
    tolua_function(tolua_S,"lineLoop",tolua_aps_gl_ShapeContainer_gl_ShapeContainer_lineLoop00);
    tolua_function(tolua_S,"lineStrip",tolua_aps_gl_ShapeContainer_gl_ShapeContainer_lineStrip00);
    tolua_function(tolua_S,"triangles",tolua_aps_gl_ShapeContainer_gl_ShapeContainer_triangles00);
    tolua_function(tolua_S,"triangleStrip",tolua_aps_gl_ShapeContainer_gl_ShapeContainer_triangleStrip00);
    tolua_function(tolua_S,"polygon",tolua_aps_gl_ShapeContainer_gl_ShapeContainer_polygon00);
    tolua_function(tolua_S,"setAnchor",tolua_aps_gl_ShapeContainer_gl_ShapeContainer_setAnchor00);
    tolua_function(tolua_S,"setPosition",tolua_aps_gl_ShapeContainer_gl_ShapeContainer_setPosition00);
    tolua_function(tolua_S,"setScale",tolua_aps_gl_ShapeContainer_gl_ShapeContainer_setScale00);
    tolua_function(tolua_S,"setScale",tolua_aps_gl_ShapeContainer_gl_ShapeContainer_setScale01);
    tolua_function(tolua_S,"setRotate",tolua_aps_gl_ShapeContainer_gl_ShapeContainer_setRotate00);
    tolua_function(tolua_S,"setColorForce",tolua_aps_gl_ShapeContainer_gl_ShapeContainer_setColorForce00);
    tolua_function(tolua_S,"anchor",tolua_aps_gl_ShapeContainer_gl_ShapeContainer_anchor00);
    tolua_function(tolua_S,"position",tolua_aps_gl_ShapeContainer_gl_ShapeContainer_position00);
    tolua_function(tolua_S,"scale",tolua_aps_gl_ShapeContainer_gl_ShapeContainer_scale00);
    tolua_function(tolua_S,"rotate",tolua_aps_gl_ShapeContainer_gl_ShapeContainer_rotate00);
    tolua_function(tolua_S,"pushChild",tolua_aps_gl_ShapeContainer_gl_ShapeContainer_pushChild00);
    tolua_function(tolua_S,"setTexture",tolua_aps_gl_ShapeContainer_gl_ShapeContainer_setTexture00);
    tolua_function(tolua_S,"rectWithTexture",tolua_aps_gl_ShapeContainer_gl_ShapeContainer_rectWithTexture00);
    tolua_function(tolua_S,"rectWithTexture",tolua_aps_gl_ShapeContainer_gl_ShapeContainer_rectWithTexture01);
    tolua_function(tolua_S,"draw",tolua_aps_gl_ShapeContainer_gl_ShapeContainer_draw00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_aps_gl_ShapeContainer (lua_State* tolua_S) {
 return tolua_aps_gl_ShapeContainer_open(tolua_S);
};
#endif

