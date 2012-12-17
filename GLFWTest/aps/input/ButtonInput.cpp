//
//  ButtonInput.cpp
//  chiser
//
//  Copyright (c) 2012 alprosys. All rights reserved.
//

#include "ButtonInput.h"

using namespace aps::input;

void ButtonInput::up(int type)
{
	auto it = buttonStateMap_.find(type);
	if (it != buttonStateMap_.end())
	{
		it->second.up();
	}
	else
	{
		ButtonState bs;
		bs.up();
		buttonStateMap_[type] = bs;
	}
}

void ButtonInput::down(int type)
{
	auto it = buttonStateMap_.find(type);
	if (it != buttonStateMap_.end())
	{
		it->second.down();
	}
	else
	{
		ButtonState bs;
		bs.down();
		buttonStateMap_[type] = bs;
	}
}

void ButtonInput::update()
{
	for (auto& keyStatusPair : buttonStateMap_)
	{
		keyStatusPair.second.update();
	}
}

ButtonState ButtonInput::buttonState(int type) const
{
	auto it = buttonStateMap_.find(type);
	if (it != buttonStateMap_.end())
	{
		auto state = it->second;
		return state;
	}
	else
	{
		return ButtonState();
	}
}