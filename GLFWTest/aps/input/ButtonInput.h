//
//  ButtonInput.h
//  chiser
//
//  Copyright (c) 2012 alprosys. All rights reserved.
//

#pragma once

#include <unordered_map>

#include "ButtonState.h"

namespace aps
{
	namespace input
	{
		class ButtonInput
		{
		public:
			void up(int type);
			void down(int type);
			void update();
			ButtonState buttonState(int type) const;
			
		public:
			std::unordered_map<int, ButtonState> buttonStateMap_;
		};
	}
}