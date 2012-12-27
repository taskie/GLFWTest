//
//  GLFW.h
//  GLFWTest
//
//  Created by taskie on 2012/11/28.
//  Copyright (c) 2012年 alprosys. All rights reserved.
//

#ifndef __GLFWTest__GLFW__
#define __GLFWTest__GLFW__

#include <iostream>

#include <boost/noncopyable.hpp>

class GLFW : private boost::noncopyable
{
public:
	GLFW();
	virtual ~GLFW();
	void run();
	
protected:
	virtual void willOpenWindow();
	virtual void openWindow();
	virtual void didOpenWindow();
	virtual void initialize();
	virtual void draw();
	virtual void quit();
	virtual void finalize();
};

#endif /* defined(__GLFWTest__GLFW__) */
