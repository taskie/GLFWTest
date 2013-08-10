//
//  XYState.h
//  GLFWTest
//
//  Created by taskie on 2012/12/22.
//  Copyright (c) 2012年 alprosys. All rights reserved.
//

#pragma once

#include "ButtonState.h"
#include <string>
#include <unordered_map>

namespace aps
{
	namespace input
	{
		class XYState
		{
		public:
			XYState();
			void setXY(double x, double y);
			void update();
			double x() const;
			double y() const;
			double circledX() const;
			double circledY() const;
			ButtonState direction(std::string key) const;
			
		private:
			double x_, y_;
			double abs_;
			std::unordered_map<std::string, ButtonState> directionMap_;
		};
	}
}
