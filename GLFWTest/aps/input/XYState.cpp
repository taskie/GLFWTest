//
//  XYState.cpp
//  GLFWTest
//
//  Created by taskie on 2012/12/22.
//  Copyright (c) 2012年 alprosys. All rights reserved.
//

#include "XYState.h"

#include <cmath>

using namespace aps::input;

XYState::XYState()
: x_(0.0), y_(0.0), abs_(0.0)
{
	
}

void XYState::setXY(double x, double y)
{
	x_ = x;
	y_ = y;
	abs_ = std::hypot(x, y);
}

double XYState::x() const { return x_; }
double XYState::y() const { return y_; }
double XYState::circledX() const { return (abs_ > 1) ? x_ / abs_ : x_; }
double XYState::circledY() const { return (abs_ > 1) ? y_ / abs_ : y_; }