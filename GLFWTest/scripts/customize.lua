-- Customize

subclass ("Customize", Actor, Scn) { }

local function atIndex(t, value)
	for i, v in ipairs(t) do
		if v == value then return i end
	end
	return nil
end

function Scn.Customize:new(old)
	Scn.Customize.super.new(self)
	
	local textColor = {0.2, 0.2, 0.2, 1}
	self.oldScene = old
	self.input = Input()
	self.background = Background()
	
	self.barRect = Rct.Rect(Mys.field.x, Mys.screen.h, "polygon", {0.8, 0.8, 0.8, 0.5}, 0, 0)
	
	self.items = {}
	self.items.texts = {"Stages", "Encounter Rate", "Internecine Strife", "Exp. in Bullets", "Show Details", "Exit"}
	self.items.parameterNames = {"stages", "enemyProbability", "bulletExpMode", "enemyWithEnemyMode", "verboseMode"}
	self.items.values = {{10, 20}, {0.01, 0.02, 0.03}, {false, true}, {false, true}, {false, true}}
	self.items.valueTexts = {{"10", "20"}, {"Lv. 1", "Lv. 2", "Lv. 3"}, {"Off", "On"}, {"Off", "On"}, {"Off", "On"}}
	self.items.valueTextShapes = {}
	self.items.valueChoices = {}
	
	do
		local param = profile.game
		local values = self.items.values
		for i, name in ipairs(self.items.parameterNames) do
			self.items.valueChoices[i] = atIndex(values[i], param[name]) or 1
		end
	end
	
	for i, choice in ipairs(self.items.valueChoices) do
		self.items.valueTextShapes[i] = Rct.Text(self.items.valueTexts[i][choice], "thin", 64, {0.2, 0.2, 0.2, 0.3}, "r")
	end
	
	self.items.choice = 1
	self.items.choiceMax = #self.items.texts
	self.items.choiceTriangle = Rct.Regular(3, 5, "lineLoop", textColor)
	self.items.textShapes = {}
	for i, text in ipairs(self.items.texts) do
		self.items.textShapes[i] = Rct.Text(text, "thin", 32, textColor, "l")
	end
	self.nextScene = false
end


function Scn.Customize:update()
	if self.input:isJustPressed("DOWN") then
		Mxr:play("weaponchoice")
		self.items.choice = self.items.choice + 1
		if self.items.choice > self.items.choiceMax then
			self.items.choice = 1
		end
	end
	
	if self.input:isJustPressed("UP") then
		Mxr:play("weaponchoice")
		self.items.choice = self.items.choice - 1
		if self.items.choice < 1 then
			self.items.choice = self.items.choiceMax
		end
	end
	
	if self.input:isJustPressed("LEFT") then
		local choice = self.items.choice
		if self.items.valueChoices[choice]
		   and self.items.valueChoices[choice] - 1 >= 1
		then
			Mxr:play("ok")
			self.items.valueChoices[choice] = self.items.valueChoices[choice] - 1
			self.items.valueTextShapes[choice]:renew(self.items.valueTexts[choice][self.items.valueChoices[choice]])
		end
	end
	
	if self.input:isJustPressed("RIGHT") then
		local choice = self.items.choice
		if self.items.valueChoices[choice]
		   and self.items.valueChoices[choice] + 1 <= #self.items.values[choice]
		then
			Mxr:play("ok")
			self.items.valueChoices[choice] = self.items.valueChoices[choice] + 1
			self.items.valueTextShapes[choice]:renew(self.items.valueTexts[choice][self.items.valueChoices[choice]])
		end
	end
	
	if self.input:isJustPressed("Z") then
		if self.items.texts[self.items.choice] == "Exit" then
			Mxr:play("ok")
			do
				local param = profile.game
				local values = self.items.values
				for i, name in ipairs(self.items.parameterNames) do
					param[name] = values[i][self.items.valueChoices[i]]
				end
			end
			self.nextScene = Scn.Title()
		end
	end
	
	return Scn.Customize.super.update(self)
end

function Scn.Customize:draw()
	self.background:draw()
	self.barRect:draw()
	self.barRect:draw(Mys.field.wx)
	self.items.choiceTriangle:draw(Mys.field.x + 15, 50 - 12 + (self.items.choice - 1) * 80)
	for i, shape in ipairs(self.items.valueTextShapes) do
		shape:draw(Mys.field.wx - 30, 90 + (i - 1) * 80)
	end
	for i, shape in ipairs(self.items.textShapes) do
		shape:draw(Mys.field.x + 30, 50 + (i - 1) * 80)
	end
end