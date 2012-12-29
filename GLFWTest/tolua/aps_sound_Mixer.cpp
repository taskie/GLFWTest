/*
** Lua binding: aps_sound_Mixer
** Generated automatically by tolua++-1.0.92 on Fri Dec 28 22:36:12 2012.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_aps_sound_Mixer_open (lua_State* tolua_S);

#include "../aps/sound/Mixer.h"
using namespace aps::sound;

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Mixer (lua_State* tolua_S)
{
 Mixer* self = (Mixer*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Mixer");
}

/* method: new of class  Mixer */
#ifndef TOLUA_DISABLE_tolua_aps_sound_Mixer_sound_Mixer_new00
static int tolua_aps_sound_Mixer_sound_Mixer_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mixer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Mixer* tolua_ret = (Mixer*)  Mtolua_new((Mixer)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Mixer");
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

/* method: new_local of class  Mixer */
#ifndef TOLUA_DISABLE_tolua_aps_sound_Mixer_sound_Mixer_new00_local
static int tolua_aps_sound_Mixer_sound_Mixer_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mixer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Mixer* tolua_ret = (Mixer*)  Mtolua_new((Mixer)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Mixer");
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

/* method: loadMusic of class  Mixer */
#ifndef TOLUA_DISABLE_tolua_aps_sound_Mixer_sound_Mixer_loadMusic00
static int tolua_aps_sound_Mixer_sound_Mixer_loadMusic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mixer",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mixer* self = (Mixer*)  tolua_tousertype(tolua_S,1,0);
  std::string key = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  std::string path = ((std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadMusic'", NULL);
#endif
  {
   self->loadMusic(key,path);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadMusic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadSound of class  Mixer */
#ifndef TOLUA_DISABLE_tolua_aps_sound_Mixer_sound_Mixer_loadSound00
static int tolua_aps_sound_Mixer_sound_Mixer_loadSound00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mixer",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mixer* self = (Mixer*)  tolua_tousertype(tolua_S,1,0);
  std::string key = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  std::string path = ((std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadSound'", NULL);
#endif
  {
   self->loadSound(key,path);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadSound'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: play of class  Mixer */
#ifndef TOLUA_DISABLE_tolua_aps_sound_Mixer_sound_Mixer_play00
static int tolua_aps_sound_Mixer_sound_Mixer_play00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mixer",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mixer* self = (Mixer*)  tolua_tousertype(tolua_S,1,0);
  std::string key = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'play'", NULL);
#endif
  {
   self->play(key);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'play'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pause of class  Mixer */
#ifndef TOLUA_DISABLE_tolua_aps_sound_Mixer_sound_Mixer_pause00
static int tolua_aps_sound_Mixer_sound_Mixer_pause00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mixer",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mixer* self = (Mixer*)  tolua_tousertype(tolua_S,1,0);
  std::string key = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pause'", NULL);
#endif
  {
   self->pause(key);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pause'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stop of class  Mixer */
#ifndef TOLUA_DISABLE_tolua_aps_sound_Mixer_sound_Mixer_stop00
static int tolua_aps_sound_Mixer_sound_Mixer_stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mixer",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mixer* self = (Mixer*)  tolua_tousertype(tolua_S,1,0);
  std::string key = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stop'", NULL);
#endif
  {
   self->stop(key);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rewind of class  Mixer */
#ifndef TOLUA_DISABLE_tolua_aps_sound_Mixer_sound_Mixer_rewind00
static int tolua_aps_sound_Mixer_sound_Mixer_rewind00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mixer",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mixer* self = (Mixer*)  tolua_tousertype(tolua_S,1,0);
  std::string key = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rewind'", NULL);
#endif
  {
   self->rewind(key);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rewind'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: gain of class  Mixer */
#ifndef TOLUA_DISABLE_tolua_aps_sound_Mixer_sound_Mixer_gain00
static int tolua_aps_sound_Mixer_sound_Mixer_gain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mixer",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mixer* self = (Mixer*)  tolua_tousertype(tolua_S,1,0);
  std::string key = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'gain'", NULL);
#endif
  {
   float tolua_ret = (float)  self->gain(key);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'gain'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setGain of class  Mixer */
#ifndef TOLUA_DISABLE_tolua_aps_sound_Mixer_sound_Mixer_setGain00
static int tolua_aps_sound_Mixer_sound_Mixer_setGain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mixer",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mixer* self = (Mixer*)  tolua_tousertype(tolua_S,1,0);
  std::string key = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  float gain = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setGain'", NULL);
#endif
  {
   self->setGain(key,gain);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setGain'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: update of class  Mixer */
#ifndef TOLUA_DISABLE_tolua_aps_sound_Mixer_sound_Mixer_update00
static int tolua_aps_sound_Mixer_sound_Mixer_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mixer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mixer* self = (Mixer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_aps_sound_Mixer_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"sound",0);
  tolua_beginmodule(tolua_S,"sound");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Mixer","Mixer","",tolua_collect_Mixer);
   #else
   tolua_cclass(tolua_S,"Mixer","Mixer","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Mixer");
    tolua_function(tolua_S,"new",tolua_aps_sound_Mixer_sound_Mixer_new00);
    tolua_function(tolua_S,"new_local",tolua_aps_sound_Mixer_sound_Mixer_new00_local);
    tolua_function(tolua_S,".call",tolua_aps_sound_Mixer_sound_Mixer_new00_local);
    tolua_function(tolua_S,"loadMusic",tolua_aps_sound_Mixer_sound_Mixer_loadMusic00);
    tolua_function(tolua_S,"loadSound",tolua_aps_sound_Mixer_sound_Mixer_loadSound00);
    tolua_function(tolua_S,"play",tolua_aps_sound_Mixer_sound_Mixer_play00);
    tolua_function(tolua_S,"pause",tolua_aps_sound_Mixer_sound_Mixer_pause00);
    tolua_function(tolua_S,"stop",tolua_aps_sound_Mixer_sound_Mixer_stop00);
    tolua_function(tolua_S,"rewind",tolua_aps_sound_Mixer_sound_Mixer_rewind00);
    tolua_function(tolua_S,"gain",tolua_aps_sound_Mixer_sound_Mixer_gain00);
    tolua_function(tolua_S,"setGain",tolua_aps_sound_Mixer_sound_Mixer_setGain00);
    tolua_function(tolua_S,"update",tolua_aps_sound_Mixer_sound_Mixer_update00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_aps_sound_Mixer (lua_State* tolua_S) {
 return tolua_aps_sound_Mixer_open(tolua_S);
};
#endif

