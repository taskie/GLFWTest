//
//  BindToLua.h
//  GLFWTest
//
//  Created by taskie on 2012/12/05.
//  Copyright (c) 2012年 alprosys. All rights reserved.
//

#ifndef GLFWTest_BindToLua_h
#define GLFWTest_BindToLua_h

#include <tolua++.h>
#include "aps_font_Manager.h"
#include "aps_fontex_Fontex.h"
#include "aps_gl_Color.h"
#include "aps_gl_ShapeContainer.h"
#include "aps_gl_ShapeElement.h"
#include "aps_gl_Texture2D.h"
#include "aps_input_ButtonState.h"
#include "aps_input_KeyBoardInput.h"
#include "aps_random_MersenneTwister.h"

void BindToLua(lua_State* L)
{
	tolua_aps_font_Manager_open(L);
	tolua_aps_fontex_Fontex_open(L);
	tolua_aps_gl_Color_open(L);
	tolua_aps_gl_ShapeContainer_open(L);
	tolua_aps_gl_ShapeElement_open(L);
	tolua_aps_gl_Texture2D_open(L);
	tolua_aps_input_ButtonState_open(L);
	tolua_aps_input_KeyBoardInput_open(L);
	tolua_aps_random_MersenneTwister_open(L);
}

#endif
