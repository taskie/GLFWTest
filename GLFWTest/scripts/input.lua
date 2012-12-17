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

class ("Input") { }

function Input:new()
	self.keyBoard = KeyBoard()
end

function Input:isPressed(query)
	return self.keyBoard:isPressed(query)
end

function Input:isJustPressed(query)
	return self.keyBoard:isJustPressed(query)
end
