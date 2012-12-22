//
//  XYInput.cpp
//  GLFWTest
//
//  Created by taskie on 2012/12/22.
//  Copyright (c) 2012年 alprosys. All rights reserved.
//

#include "XYInput.h"

using namespace aps::input;

void XYInput::setXY(int type, double x, double y)
{
	auto it = xyStateMap_.find(type);
	if (it != xyStateMap_.end())
	{
		it->second.setXY(x, y);
	}
	else
	{
		XYState xy;
		xy.setXY(x, y);
		xyStateMap_[type] = xy;
	}
}

XYState XYInput::xyState(int type) const
{
	auto it = xyStateMap_.find(type);
	if (it != xyStateMap_.end())
	{
		auto state = it->second;
		return state;
	}
	else
	{
		return XYState();
	}
}