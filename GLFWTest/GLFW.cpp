//
//  GLFW.cpp
//  GLFWTest
//
//  Created by taskie on 2012/11/28.
//  Copyright (c) 2012年 alprosys. All rights reserved.
//

#include "GLFW.h"

#include <GL/glfw.h>

GLFW::GLFW()
{
	glfwInit();
}

GLFW::~GLFW()
{
	glfwTerminate();
}

void GLFW::run()
{
	willOpenWindow();
	openWindow();
	didOpenWindow();
	initialize();
	
	while (glfwGetWindowParam(GLFW_OPENED))
	{
		draw();
		glfwSwapBuffers();
	}
	
	finalize();
}

void GLFW::willOpenWindow()
{
	
}

void GLFW::openWindow()
{
	glfwOpenWindow(0, 0, 0, 0, 0, 0, 0, 0, GLFW_WINDOW);
}

void GLFW::didOpenWindow()
{
	glfwSetWindowTitle("GLFW");
}

void GLFW::initialize()
{
	glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
}

void GLFW::draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void GLFW::finalize()
{
	
}