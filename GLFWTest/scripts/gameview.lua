subclass ("GameView", Actor) { }

function GameView:new(model)
	self.model = model
	self.background = Background()
	self.sideBar = SideBar(model)
	local textColor = {0.2, 0.2, 0.2, 1}
	self.stageBegining = Rct.Text("STAGE X", "thin", 32, textColor, "c")
	self.verboseMode = false
end

function GameView:update()
	Mxr:update()
	self.sideBar:update()
	if self.model.stage.stageFrame < Mys.fps * 2 then
		self.stageBegining:renew("STAGE " .. self.model.stage.count)
	else
		self.stageBegining:renew(" ")
	end
	return true
end

local function drawField(field)
	for id, actor in field:pairs() do
		actor:draw()
	end
end

function GameView:draw()
	self.background:draw()
	drawField(self.model.playersBullets)
	drawField(self.model.players)
	for id, player in self.model.players:pairs() do
		Rct.Circle(player.capture.r, "polygon", {0, 0, 0, 0.1}):draw(player.x, player.y, 0)
	end
	if self.verboseMode then
		for id, enemy in self.model.enemies:pairs() do
			Rct.Circle(enemy.hp / enemy.hpmax * 20, "polygon", {1, 0.8, 0.1, 0.2}):draw(enemy.x, enemy.y, 0)
		end
	end
	drawField(self.model.enemies)
	if self.verboseMode then
		for id, enemy in self.model.enemies:pairs() do
			Rct.Text(enemy.exp, "black", 9, {0, 0, 0, 1}, "c"):draw(enemy.x, enemy.y + 3, 0)
		end
	end
	drawField(self.model.enemiesBullets)
	drawField(self.model.experiences)
	drawField(self.model.actors)
	self.stageBegining:draw(Mys.screen.cx, 100)
	self.sideBar:draw()
end
