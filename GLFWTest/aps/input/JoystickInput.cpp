//
//  JoystickInput.cpp
//  chiser
//
//  Copyright (c) 2012 Alprosys. All rights reserved.
//

#include "JoystickInput.h"

using namespace aps::input;

void JoystickInput::up(int num)
{
	buttonInput_.up(num);
}

void JoystickInput::down(int num)
{
	buttonInput_.down(num);
}

void JoystickInput::setXY(int num, double x, double y)
{
	xyInput_.setXY(num, x, y);
}

void JoystickInput::update()
{
	buttonInput_.update();
}

ButtonState JoystickInput::buttonState(int key) const
{
	return buttonInput_.buttonState(key);
}

XYState JoystickInput::xyState(int key) const
{
	return xyInput_.xyState(key);
}

