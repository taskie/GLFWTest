//
//  main.cpp
//  GLFWTest
//
//  Created by taskie on 2012/11/28.
//  Copyright (c) 2012年 alprosys. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <boost/format.hpp>

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

static std::vector<char> loadProfileData()
{
	std::ifstream ifs("profile.dat", std::ios::binary);
	if (!ifs.good()) return std::vector<char>();
	
	std::size_t begPos = ifs.tellg();
	ifs.seekg(0, std::ios::end);
	std::size_t endPos = ifs.tellg();
	ifs.seekg(0, std::ios::beg);
	
	std::ptrdiff_t size = endPos - begPos;
	
	std::vector<char> vec(size);
	ifs.read(vec.data(), size);
	
	return vec;
}

static void saveProfileData(std::vector<char> vec)
{
	std::ofstream ofs("profile.dat", std::ios::binary);
	
	ofs.write(vec.data(), vec.size());
}

static std::vector<char> loadReplayData(int n)
{
	std::string path = (boost::format("replays/replay%d.dat") % n).str();
	std::ifstream ifs(path, std::ios::binary);
	if (!ifs.good()) return std::vector<char>();
	
	std::size_t begPos = ifs.tellg();
	ifs.seekg(0, std::ios::end);
	std::size_t endPos = ifs.tellg();
	ifs.seekg(0, std::ios::beg);
	
	std::ptrdiff_t size = endPos - begPos;
	
	std::vector<char> vec(size);
	ifs.read(vec.data(), size);
	
	return vec;
}

static int loadReplayDataLuaCF(lua_State *L)
{
	int n = static_cast<int>(lua_tointeger(L, -1));
	auto data = loadReplayData(n);
	if (data.empty())
	{
		lua_pushboolean(L, false);
	} else {
		lua_pushlstring(L, data.data(), data.size());
	}
	return 1;
}

static void saveReplayData(int n, std::vector<char> vec)
{
	std::string path = (boost::format("replays/replay%d.dat") % n).str();
	std::ofstream ofs(path, std::ios::binary);
	
	ofs.write(vec.data(), vec.size());
}

static int saveReplayDataLuaCF(lua_State *L)
{
	int n = static_cast<int>(lua_tointeger(L, 1));
	std::size_t size;
	const char* c = lua_tolstring(L, 2, &size);
	std::vector<char> data(c, c + size);
	saveReplayData(n, data);
	return 0;
}

class MyGLFW : public GLFW
{
	virtual void willOpenWindow();
	virtual void openWindow();
	virtual void didOpenWindow();
	virtual void initialize();
	virtual void draw();
	virtual void finalize();
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
#if 0
//#if 1
//#if defined(NDEBUG)
	glfwOpenWindow(640, 480, 0, 0, 0, 0, 0, 0, GLFW_FULLSCREEN);
#else
	glfwOpenWindow(640, 480, 0, 0, 0, 0, 0, 0, GLFW_WINDOW);
#endif
}

void MyGLFW::didOpenWindow()
{
#if defined(NDEBUG)
	glfwSetWindowTitle("MYSTiG hyper inflation");
#else
	glfwSetWindowTitle("MYSTiG hyper inflation - Debug");
#endif
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
	glOrtho(0, 640, 480, 0, 100, -100);
	glFrustum(-2, 2, -2, 2, -100, 100);
	
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
	
	lua_register(lua->vm(), "loadReplayData", loadReplayDataLuaCF);
	lua_register(lua->vm(), "saveReplayData", saveReplayDataLuaCF);
	
	device.reset(new aps::al::Device());
	context.reset(new aps::al::Context(device->context()));
	context->current();
	
	std::vector<char> profile = loadProfileData();
	if (!profile.empty()) {
		lua_pushlstring(lua->vm(), profile.data(), profile.size());
		lua_setglobal(lua->vm(), "profileBinary");
	}
	
#ifdef NDEBUG
	lua->doFile("scripts/main.lua");
#else
	for (; ; )
	{
		if (lua->doFile("scripts/main.lua")) break;
		std::string x;
		std::cin >> x;
	}
#endif
	
	glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
	oldTime = glfwGetTime();
}

void MyGLFW::draw()
{
	keyBoardInput->update();

#ifndef NDEBUG
	auto reloadKey = keyBoardInput->buttonState('R');
	if (reloadKey.pressed() && reloadKey.just()) {
		for (; ; ) {
			if (lua->doFile("scripts/main.lua")) break;
			std::string x;
			std::cin >> x;
		}
	}
#endif
	
	auto smoothKey = keyBoardInput->buttonState('L');
	static bool smoothFlag = true;
	if (smoothKey.pressed() && smoothKey.just()) {
		if (smoothFlag) {
			glDisable(GL_LINE_SMOOTH);
		} else {
			glEnable(GL_LINE_SMOOTH);
		}
		smoothFlag = !smoothFlag;
	}
		
	{
		joystickInput->update();
		
		int joystickNo;
		for (joystickNo = GLFW_JOYSTICK_1; joystickNo < GLFW_JOYSTICK_LAST; ++joystickNo)
		{
			bool joyStickOn = glfwGetJoystickParam(GLFW_JOYSTICK_1, GLFW_PRESENT);
			if (joyStickOn) break;
		}
		
		if (joystickNo != GLFW_JOYSTICK_LAST)
		{
			int joyStickAxes = glfwGetJoystickParam(joystickNo, GLFW_AXES);
			int joyStickButtons = glfwGetJoystickParam(joystickNo, GLFW_BUTTONS);
			
			std::vector<float> positions(joyStickAxes);
			glfwGetJoystickPos(joystickNo, &positions[0], joyStickAxes);
			for (std::size_t i = 0; i < positions.size(); i += 2) {
				joystickInput->setXY(static_cast<int>(i / 2), positions[i], positions[i + 1]);
			}
			
			std::vector<unsigned char> buttons(joyStickButtons);
			glfwGetJoystickButtons(joystickNo, &buttons[0], joyStickButtons);
			for (std::size_t i = 0; i < buttons.size(); ++i) {
				if (buttons[i]) {
					joystickInput->down(static_cast<int>(i));
				} else {
					joystickInput->up(static_cast<int>(i));
				}
			}
		}
	}
		
	auto ret = lua->callFunction("update", aps::lua::LuaTuple());
	if (!ret.empty())
	{
		if (ret[0].which() == 2)
		{
			bool flag = boost::get<bool>(ret[0]);
			if (!flag) quit();
		}
	}
	
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
	lua->callFunction("serializeProfile", aps::lua::LuaTuple());
	
	lua_getglobal(lua->vm(), "profileBinary");
	std::size_t size;
	const char* data = lua_tolstring(lua->vm(), -1, &size);
	
	std::vector<char> profile(size);
	std::copy_n(data, size, profile.begin());
	saveProfileData(profile);
}

int main(int argc, const char * argv[])
{
#if !defined(NDEBUG)
#ifdef _WIN32
	std::ofstream out("cout.txt");
	auto oldcoutbuf = std::cout.rdbuf(out.rdbuf());
	std::ofstream err("cerr.txt");
	auto oldcerrbuf = std::cerr.rdbuf(err.rdbuf());
#endif
#endif
	
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
	
#if !defined(NDEBUG)
#ifdef _WIN32
	std::cout.rdbuf(oldcoutbuf);
	std::cerr.rdbuf(oldcerrbuf);
#endif
#endif
	
	return 0;
}
