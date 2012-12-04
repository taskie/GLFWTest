//
//  main.cpp
//  GLFWTest
//
//  Created by taskie on 2012/11/28.
//  Copyright (c) 2012年 alprosys. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

#include <GL/glfw.h>

#include "GLFW.h"

#include "aps/font/Manager.h"
#include "aps/gl/Texture2D.h"
#include "aps/gl/ShapeContainer.h"
#include "aps/fontex/Fontex.h"
#include "aps/lua/Manager.h"

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
}

void MyGLFW::openWindow()
{
	glfwOpenWindow(640, 480, 0, 0, 0, 0, 0, 0, GLFW_WINDOW);
}

void MyGLFW::didOpenWindow()
{
	glfwSetWindowTitle("GLFW + FreeType");
}

static aps::lua::Manager lua;
static aps::gl::ShapeContainer shape;
static aps::font::Manager fontManager;

void MyGLFW::initialize()
{
	std::cout << glGetString(GL_VERSION) << std::endl;
	
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
	
	fontManager = aps::font::Manager();
	// fontManager.loadFont("HiraMinPW3", "/Library/Fonts/Zapfino.ttf", 0);
	fontManager.loadFont("M+ 2p thin", "/System/Library/Fonts/AquaKana.ttc", 0);
	
	aps::fontex::Fontex fontex(fontManager);
	
	std::array<double, 4> color = {1, 1, 1, 1};
	auto stringShape = fontex.utf8StringShape("アクアかな", "M+ 2p thin", 64, color);
	shape = stringShape.get();
	shape.setPosition(0, 100);
	
	glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
}

void MyGLFW::draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	shape.draw();
	
	glFlush();
}

void MyGLFW::finalize()
{
	
}

int main(int argc, const char * argv[])
{
	MyGLFW glfw;
	glfw.run();
	return 0;
}
