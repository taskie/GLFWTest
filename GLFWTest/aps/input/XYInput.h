//
//  XYInput.h
//  GLFWTest
//
//  Created by taskie on 2012/12/22.
//  Copyright (c) 2012年 alprosys. All rights reserved.
//

#pragma once

#include <unordered_map>
#include <complex>

#include "XYState.h"

namespace aps
{
	namespace input
	{
		class XYInput
		{
		public:
			void setXY(int type, double x, double y);
			XYState xyState(int type) const;
			
		public:
			std::unordered_map<int, XYState> xyStateMap_;
		};
	}
}
