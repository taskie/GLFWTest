//
//  ButtonState.h
//  chiser
//
//  Copyright (c) 2012 Alprosys. All rights reserved.
//

#pragma once

namespace aps
{
	namespace input
	{
		class ButtonState
		{
		public:
			ButtonState();
			void up();
			void down();
			void update();
			bool pressed() const;
			bool just() const;
			int holdingTime() const;
			
		private:
			int state_;
		};
	}
}
