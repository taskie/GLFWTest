//
//  KeyBoardInput.h
//  chiser
//
//  Copyright (c) 2012 Alprosys. All rights reserved.
//

#pragma once

#include <string>

#include "ButtonInput.h"
#include "XYInput.h"

namespace aps
{
	namespace input
	{
		class JoystickInput
		{
		public:
			void up(int num);
			void down(int num);
			void setXY(int num, double x, double y);
			void update();
			ButtonState buttonState(int num) const;
			XYState xyState(int num) const;
			
		private:
			ButtonInput buttonInput_;
			XYInput xyInput_;
		};
	}
}
