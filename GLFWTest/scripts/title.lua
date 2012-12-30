-- Title

subclass ("Title", Actor, Scn) { }

function Scn.Title:new()
	Scn.Title.super.new(self)
	
	local textColor = {0.2, 0.2, 0.2, 1}
	self.input = Input()
	self.background = Background()
	self.barRect = Rct.Rect(Mys.field.x, Mys.screen.h, "polygon", {0.8, 0.8, 0.8, 0.5}, 0, 0)
	self.mystig = Rct.Text("MYSTiG", "thin", 96, textColor, "r")
	self.infration = Rct.Text("inflation", "thin", 64, textColor, "r")
	self.version = Rct.Text("Ver. " .. Mys.version, "regular", 16, textColor, "r")
	
	self.items = {}
	self.items.texts = {"Start", "Customize", "Records", "Settings", "Quit"}
	if not profile.records.cleared then self.items.texts[2] = " " end
	self.items.choice = 1
	self.items.choiceMax = #self.items.texts
	self.items.choiceTriangle = Rct.Regular(3, 5, "lineLoop", textColor)
	self.items.xShifts = {}
	self.items.xShiftMax = 15
	self.items.textShapes = {}
	for i, text in ipairs(self.items.texts) do
		self.items.xShifts[i] = 0
		self.items.textShapes[i] = Rct.Text(text, "thin", 32, textColor, "l")
	end
	self.items.xShifts[1] = self.items.xShiftMax
	self.nextScene = false
end

function Scn.Title:update()
	if self.input:isJustPressed("DOWN") then
		Mxr:play("weaponchoice")
		self.items.choice = self.items.choice + 1
		while self.items.texts[self.items.choice] == " " do
			self.items.choice = self.items.choice + 1
		end
		if self.items.choice > self.items.choiceMax then
			self.items.choice = 1
		end
	end
	
	if self.input:isJustPressed("UP") then
		Mxr:play("weaponchoice")
		self.items.choice = self.items.choice - 1
		while self.items.texts[self.items.choice] == " " do
			self.items.choice = self.items.choice - 1
		end
		if self.items.choice < 1 then
			self.items.choice = self.items.choiceMax
		end
	end
	
	if self.input:isJustPressed("Z") then
		self.nextScene = false
		if self.items.texts[self.items.choice] == "Start" then
			Mxr:play("ok")
			self.nextScene = Scn.Game(LoggingInput(), nil, profile.game)
		elseif self.items.texts[self.items.choice] == "Customize" then
			Mxr:play("ok")
			self.nextScene = Scn.Customize()
		elseif self.items.texts[self.items.choice] == "Settings" then
			Mxr:play("ok")
			self.nextScene = Scn.Settings()
		elseif self.items.texts[self.items.choice] == "Records" then
			Mxr:play("ok")
			self.nextScene = Scn.Records()
		elseif self.items.texts[self.items.choice] == "Quit" then
			return false
		end
	end
	
	for i, text in ipairs(self.items.texts) do
		if self.items.choice == i then
			self.items.xShifts[i] = self.items.xShifts[i] + 1
			if self.items.xShifts[i] > self.items.xShiftMax then
				self.items.xShifts[i] = self.items.xShiftMax
			end
		else
			self.items.xShifts[i] = self.items.xShifts[i] - 1
			if self.items.xShifts[i] < 0 then
				self.items.xShifts[i] = 0
			end
		end
	end
	
	return Scn.Title.super.update(self)
end

function Scn.Title:draw()
	self.background:draw()
	self.barRect:draw()
	self.barRect:draw(Mys.field.wx)
	self.mystig:draw(Mys.screen.wx - 40, 120)
	self.infration:draw(Mys.screen.wx - 45, 200)
	self.version:draw(Mys.screen.wx - 50, 240)
	self.items.choiceTriangle:draw(Mys.field.x + 20, 280 - 12 + (self.items.choice - 1) * 40)
	for i, shape in ipairs(self.items.textShapes) do
		shape:draw(Mys.field.x + 30 + self.items.xShifts[i], 280 + (i - 1) * 40)
	end
end