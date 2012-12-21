//
//  KeyBoardInput.cpp
//  chiser
//
//  Copyright (c) 2012 Alprosys. All rights reserved.
//

#include "KeyBoardInput.h"

#include <GL/glfw.h>

#include <unordered_map>
#include <boost/algorithm/string.hpp>

using namespace aps::input;

void KeyBoardInput::up(int key)
{
	buttonInput_.up(key);
}

void KeyBoardInput::down(int key)
{
	buttonInput_.down(key);
}

void KeyBoardInput::update()
{
	buttonInput_.update();
}

ButtonState KeyBoardInput::buttonState(int key) const
{
	return buttonInput_.buttonState(key);
}

ButtonState KeyBoardInput::buttonState(std::string key) const
{
	static std::unordered_map<std::string, int> charCodeDictionary =
	{
		{"ESCAPE", GLFW_KEY_ESC}, {"ESC", GLFW_KEY_ESC},
		{"LSHIFT", GLFW_KEY_LSHIFT}, {"RSHIFT", GLFW_KEY_RSHIFT},
		{"UP", GLFW_KEY_UP}, {"DOWN", GLFW_KEY_DOWN}, {"LEFT", GLFW_KEY_LEFT}, {"RIGHT", GLFW_KEY_RIGHT},
		{"SPACE", GLFW_KEY_SPACE}, {"ENTER", GLFW_KEY_ENTER}, {"RETURN", GLFW_KEY_ENTER}
	};

	boost::algorithm::to_upper(key);
	if (key.size() == 1)
	{
		int code = key[0];
		return buttonState(code);
	}
	
	auto it = charCodeDictionary.find(key);
	if (it != charCodeDictionary.end()) return buttonState(it->second);
	
	return ButtonState();
}