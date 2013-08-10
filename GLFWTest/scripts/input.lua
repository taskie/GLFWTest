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
	if Joystick.buttonMap.stick then
		local pressed = self.device:xyState(Joystick.buttonMap.stick):direction(query):pressed()
		if pressed then
			return true
		end
	end
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

subclass ("LoggingInput", Input) { }

function LoggingInput:new(...)
	self.log = {}
	self.super.new(self, ...)
end

local observedKeys = {"Z", "X", "C", "LEFT", "RIGHT", "UP", "DOWN", "LSHIFT"}

function LoggingInput:update()
	local keys = 0
	for i, key in ipairs(observedKeys) do
		keys = keys + (self:isPressed(key) and 1 or 0) * (2 ^ (i - 1))
	end
	local old = self.log[#self.log]
	if old and old[1] == keys then
		old[2] = old[2] + 1
	else
		table.insert(self.log, {keys, 1})
	end
end

subclass ("ReplayInput", Input) { }

function ReplayInput:new(log, ...)
	self.log = log
	self.oldKeys = 0
	self.nowKeys = 0
	self.pressedKeyTable = {}
	self.justPressedKeyTable = {}
end

function ReplayInput:update()
	self.pressedKeyTable = {}
	self.justPressedKeyTable = {}
	
	self.oldKeys = self.nowKeys
	self.nowKeys = 0
	
	if not self.log[1] then return end
	self.nowKeys = self.log[1][1]
	self.log[1][2] = self.log[1][2] - 1
	if self.log[1][2] == 0 then table.remove(self.log, 1) end
	
	local keys = self.nowKeys
	local oldkeys = self.oldKeys
	for i, key in ipairs(observedKeys) do
		if keys % 2 == 1 then
			self.pressedKeyTable[key] = true
			if oldkeys % 2 == 0 then
				self.justPressedKeyTable[key] = true
			end
		end
		
		keys = math.floor(keys / 2)
		oldkeys = math.floor(oldkeys / 2)
	end
end

function ReplayInput:isPressed(query)
	return self.pressedKeyTable[query]
end

function ReplayInput:isJustPressed(query)
	return self.justPressedKeyTable[query]
end