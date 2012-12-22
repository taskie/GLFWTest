class ("KeyBoard") {
	device = keyBoardInput
}

function KeyBoard:new()
end

function KeyBoard:isPressed(query)
	return self.device:buttonState(query):pressed()
end

function KeyBoard:isJustPressed(query)
	local state = self.device:buttonState(query)
	return state:pressed() and state:just()
end

class ("Joystick") {
	device = joystickInput,
	buttonMap = dofile("scripts/joystickmapping.lua")
}

function Joystick:new()
end

function Joystick:isPressed(query)
	local key = Joystick.buttonMap[query]
	if not key then return false end
	return self.device:buttonState(key):pressed()
end

function Joystick:isJustPressed(query)
	local key = Joystick.buttonMap[query]
	if not key then return false end
	local state = self.device:buttonState(key)
	return state:pressed() and state:just()
end

class ("Input") { }

function Input:new()
	self.keyBoard = KeyBoard()
	self.joystick = Joystick()
end

function Input:isPressed(query)
	return self.keyBoard:isPressed(query) or self.joystick:isPressed(query)
end

function Input:isJustPressed(query)
	return self.keyBoard:isJustPressed(query) or self.joystick:isJustPressed(query)
end
