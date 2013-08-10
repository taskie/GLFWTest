//
//  XYState.cpp
//  GLFWTest
//
//  Created by taskie on 2012/12/22.
//  Copyright (c) 2012年 alprosys. All rights reserved.
//

#include "XYState.h"

#include <cmath>
#include <boost/algorithm/string.hpp>

using namespace aps::input;

XYState::XYState()
: x_(0.0), y_(0.0), abs_(0.0)
{
	for (auto key : {"LEFT", "RIGHT", "UP", "DOWN"}) {
		directionMap_[key] = ButtonState();
	}
}

void XYState::setXY(double x, double y)
{
	x_ = x;
	y_ = y;
	abs_ = std::hypot(x, y);
	if (x_ < -0.5) { directionMap_["LEFT"].down();  } else { directionMap_["LEFT"].up();  }
	if (x_ >  0.5) { directionMap_["RIGHT"].down(); } else { directionMap_["RIGHT"].up(); }
	if (y_ < -0.5) { directionMap_["DOWN"].down();  } else { directionMap_["DOWN"].up();  }
	if (y_ >  0.5) { directionMap_["UP"].down();    } else { directionMap_["UP"].up();    }
	for (auto pair : directionMap_) pair.second.update();
}

double XYState::x() const { return x_; }
double XYState::y() const { return y_; }
double XYState::circledX() const { return (abs_ > 1) ? x_ / abs_ : x_; }
double XYState::circledY() const { return (abs_ > 1) ? y_ / abs_ : y_; }

ButtonState XYState::direction(std::string key) const
{
	boost::algorithm::to_upper(key);
	auto it = directionMap_.find(key);
	if (it != directionMap_.end()) return it->second;
	return ButtonState();
}