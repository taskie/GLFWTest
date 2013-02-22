-- Records

subclass ("Records", Actor, Scn) { }

local function getReplayHeader(n)
	local binary = loadReplayData(n)
	if not binary then return n .. ". ", " " end
	local rep = MP.unpack(binary)
	local str = n .. ".  " .. (rep.date or "") .. "  " .. (rep.score or "")	
	local detailstr = ""
	if rep.parameter.stages ~= 10 then detailstr = detailstr .. "[" .. rep.parameter.stages .. " Stages] " end
	if rep.parameter.enemyProbability ~= 0.01 then detailstr = detailstr .. "[ER Lv. " .. (rep.parameter.enemyProbability * 100) .. "] " end
	if rep.parameter.enemyWithEnemyMode then detailstr = detailstr .. "[IS] " end
	if rep.parameter.bulletExpMode then detailstr = detailstr .. "[BE] " end
	detailstr = detailstr .. " "
	return str, detailstr
end

function Scn.Records:new()
	Scn.Records.super.new(self)
	
	self.background = Background()
	self.barRect = Rct.Rect(Mys.field.x, Mys.screen.h, "polygon", {0.8, 0.8, 0.8, 0.5}, 0, 0)

	local textColor = {0.2, 0.2, 0.2, 1}
	self.input = Input()
	self.loadReplay = Rct.Text("RECORDS", "thin", 48, textColor, "c")
	
	self.items = {}
	self.items.texts = {}
	self.items.textShapes = {}
	self.items.detailTextShapes = {}
	for i = 1, 9 do
		self.items.texts[i] = i
	end
	self.items.texts[10] = "Exit"
	self.items.choice = 10
	self.items.choiceMax = #self.items.texts
	self.items.choiceTriangle = Rct.Regular(3, 5, "lineLoop", textColor)
	
	for i = 1, 9 do
		local str, detailstr = getReplayHeader(i)
		self.items.textShapes[i] = Rct.Text(str, "regular", 16, textColor, "l")
		self.items.detailTextShapes[i] = Rct.Text(detailstr, "regular", 12, textColor, "l")
	end
	self.items.textShapes[10] = Rct.Text("Exit", "regular", 16, textColor, "l")
	
	self.nextScene = false
end

function Scn.Records:update()
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
	
	if self.input:isJustPressed("Z") then
		if self.items.choice == 10 then
			Mxr:rewindAndPlay("ok")
			self.nextScene = Scn.Title()
		else
			local binary = loadReplayData(self.items.choice)
			if binary then
				local rep = MP.unpack(binary)
				Mxr:rewindAndPlay("ok")
				self.nextScene = Scn.Game(ReplayInput(rep.log), rep.seed, rep.parameter)
			else
				Mxr:rewindAndPlay("ng")
			end
		end
	end

	return Scn.Records.super.update(self)
end

function Scn.Records:draw()
	self.background:draw()
	self.barRect:draw()
	self.barRect:draw(Mys.field.wx)
	
	self.loadReplay:draw(Mys.field.cx, 60)
	for i, shape in ipairs(self.items.textShapes) do
		shape:draw(Mys.field.x + 40, 60 + i * 40)
	end
	for i, shape in ipairs(self.items.detailTextShapes) do
		shape:draw(Mys.field.x + 67, 60 + 15 + i * 40)
	end
	self.items.choiceTriangle:draw(Mys.field.x + 20, 54 + self.items.choice * 40)
end