//
//  ButtonState.cpp
//  chiser
//
//  Copyright (c) 2012 Alprosys. All rights reserved.
//

#include "ButtonState.h"

using namespace	aps::input;

ButtonState::ButtonState()
: state_(-1)
{
	
}

void ButtonState::up()
{
	if (state_ >= 0) state_ = -1;
}

void ButtonState::down()
{
	if (state_ < 0) state_ = 0;
}

void ButtonState::update()
{
	if (state_ >= 0) {
		++state_;
	} else {
		--state_;
	}
}

bool ButtonState::pressed() const
{
	return state_ >= 0;
}

bool ButtonState::just() const
{
	return holdingTime() == 1;
}

int ButtonState::holdingTime() const
{
	return (state_ >= 0) ? state_ : ~state_;
}

#ifdef UNITTEST

#include <cassert>

int main()
{
	ButtonState b;
	
	assert(!b.pressed());
	b.down();
	assert(b.pressed() && b.just());
	b.update();
	assert(b.holdingTime() == 1);
	b.up();
	assert(b.just());
	b.update();
	b.update();
	assert(b.holdingTime() == 2);
	
	return 0;
}

#endif
