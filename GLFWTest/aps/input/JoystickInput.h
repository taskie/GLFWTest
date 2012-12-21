//
//  KeyBoardInput.h
//  chiser
//
//  Copyright (c) 2012 Alprosys. All rights reserved.
//

#pragma once

#include <string>

#include "ButtonInput.h"

namespace aps
{
	namespace input
	{
		class KeyBoardInput
		{
		public:
			void up(int key);
			void down(int key);
			void update();
			ButtonState buttonState(int key) const;
			ButtonState buttonState(std::string key) const;
			
		private:
			ButtonInput buttonInput_;
		};
	}
}
