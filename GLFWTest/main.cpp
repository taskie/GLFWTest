//
//  main.cpp
//  GLFWTest
//
//  Created by taskie on 2012/11/28.
//  Copyright (c) 2012年 alprosys. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>

#include <GL/glfw.h>

#include "GLFW.h"

#include "aps/font/Manager.h"
#include "aps/gl/Texture2D.h"
#include "aps/gl/ShapeContainer.h"
#include "aps/fontex/Fontex.h"
#include "aps/lua/LuaManager.h"
#include "aps/input/KeyBoardInput.h"
#include "aps/sound/Mixer.h"
#include "aps/sound/Wave.h"
#include "aps/al/Device.h"
#include "aps/input/JoystickInput.h"

#include "tolua/BindToLua.h"

#ifdef __APPLE__
#include <unistd.h>
#include <boost/algorithm/string.hpp>
#endif

class MyGLFW : public GLFW
{
	void willOpenWindow();
	void openWindow();
	void didOpenWindow();
	void initialize();
	void draw();
	void finalize();
};

void MyGLFW::willOpenWindow()
{
	/*
	 glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
	 glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 2);
	 glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	 */
	glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE, GL_TRUE);
}

void MyGLFW::openWindow()
{
	glfwOpenWindow(640, 480, 0, 0, 0, 0, 0, 0, GLFW_WINDOW);
	//	glfwOpenWindow(640, 480, 0, 0, 0, 0, 0, 0, GLFW_FULLSCREEN);
}

void MyGLFW::didOpenWindow()
{
	glfwSetWindowTitle("MYSTiG Next");
}

static std::unique_ptr<aps::lua::LuaManager> lua;
static std::unique_ptr<aps::input::KeyBoardInput> keyBoardInput;
static std::unique_ptr<aps::input::JoystickInput> joystickInput;
static std::unique_ptr<aps::al::Device> device;
static std::unique_ptr<aps::al::Context> context;
static int frame;

void GLFWCALL keyCallback(int key, int action)
{
	if (!keyBoardInput) return;
	if (action == GLFW_PRESS)
	{
		keyBoardInput->down(key);
	}
	else
	{
		keyBoardInput->up(key);
	}
}

static double oldTime = 0;

static constexpr int fps = 60;
static constexpr double spf = 1.0 / fps;
static constexpr double delta = spf / 3;

void MyGLFW::initialize()
{
	//	std::cout << glGetString(GL_VERSION) << std::endl;
	
	// blend
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glEnable(GL_ALPHA);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POINT_SMOOTH);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	
	// texture
	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_FLAT);
	glDisable(GL_CULL_FACE);
	
	// coordinate
	glViewport(0, 0, 640, 480);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glOrtho(0, 640, 480, 0, 1, -1);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	lua.reset(new aps::lua::LuaManager());
	BindToLua(lua->vm());
	
	keyBoardInput.reset(new aps::input::KeyBoardInput());
	glfwSetKeyCallback(keyCallback);
	tolua_pushusertype(lua->vm(), keyBoardInput.get(), "KeyBoardInput");
	lua_setglobal(lua->vm(), "keyBoardInput");
	
	joystickInput.reset(new aps::input::JoystickInput());
	tolua_pushusertype(lua->vm(), joystickInput.get(), "JoystickInput");
	lua_setglobal(lua->vm(), "joystickInput");
	
	device.reset(new aps::al::Device());
	context.reset(new aps::al::Context(device->context()));
	context->current();
	
	for (; ; )
	{
		if (lua->doFile("scripts/main.lua")) break;
		std::string x;
		std::cin >> x;
	}
	
	glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
	oldTime = glfwGetTime();
}

void MyGLFW::draw()
{
	keyBoardInput->update();
	
	auto reloadKey = keyBoardInput->buttonState('R');
	if (reloadKey.pressed() && reloadKey.just()) {
		for (; ; ) {
			if (lua->doFile("scripts/main.lua")) break;
			std::string x;
			std::cin >> x;
		}
	}
	
	{
		joystickInput->update();
		bool joyStickon = glfwGetJoystickParam(GLFW_JOYSTICK_1, GLFW_PRESENT);
		
		if (joyStickon)
		{
			int joyStickAxes = glfwGetJoystickParam(GLFW_JOYSTICK_1, GLFW_AXES);
			int joyStickButtons = glfwGetJoystickParam(GLFW_JOYSTICK_1, GLFW_BUTTONS);
			
			std::vector<float> positions(joyStickAxes);
			glfwGetJoystickPos(GLFW_JOYSTICK_1, &positions[0], joyStickAxes);
			for (int i = 0; i < positions.size(); i += 2) {
				joystickInput->setXY(i / 2, positions[i], positions[i + 1]);
			}
			
			std::vector<unsigned char> buttons(joyStickButtons);
			glfwGetJoystickButtons(GLFW_JOYSTICK_1, &buttons[0], joyStickButtons);
			for (int i = 0; i < buttons.size(); ++i) {
				if (buttons[i]) {
					joystickInput->down(i);
				} else {
					joystickInput->up(i);
				}
			}
		}
	}
		
	lua->callFunction("update", aps::lua::LuaTuple());
	
	glClear(GL_COLOR_BUFFER_BIT);
	lua->callFunction("draw", aps::lua::LuaTuple());
	glFlush();
	
	double nowTime = glfwGetTime();
	
	while (double diff = nowTime - oldTime < spf) {
		if (diff < delta) glfwSleep(delta);
		nowTime = glfwGetTime();
	}
	
	oldTime = glfwGetTime();
	++frame;
}

void MyGLFW::finalize()
{
	
}

int main(int argc, const char * argv[])
{
/*
#ifdef _WIN32
    std::ofstream out("cout.txt");
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!
    std::ofstream err("cerr.txt");
    std::cerr.rdbuf(err.rdbuf()); //redirect std::cout to out.txt!
#endif
*/
#ifdef __APPLE__
	std::vector<std::string> v;
	boost::split(v, argv[0], boost::is_any_of("/"));
	v.pop_back();
#ifdef NDEBUG
	chdir((boost::join(v, "/") + "/..").c_str());
#else
	chdir((boost::join(v, "/") + "/").c_str());
#endif
#endif
	
	MyGLFW glfw;
	glfw.run();
	return 0;
}
