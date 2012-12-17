subclass ("GameView", Actor) { }

function GameView:new(model)
	self.model = model
	self.background = Rct.Rect(Mys.screen.w, Mys.screen.h, "polygon", {0.95, 0.95, 0.95}, 0, 0)
	self.sideBar = SideBar(model)
end

function GameView:update()
	self.sideBar:update()
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
	for id, enemy in self.model.enemies:pairs() do
		Rct.Circle(enemy.hp / enemy.hpmax * 20, "polygon", {1, 0.8, 0.1, 0.2}):draw(enemy.x, enemy.y, 0)
	end
	drawField(self.model.enemies)
	for id, enemy in self.model.enemies:pairs() do
		Rct.Text(enemy.exp, "black", 9, {0, 0, 0, 1}, "c"):draw(enemy.x, enemy.y + 3, 0)
	end
	drawField(self.model.enemiesBullets)
	drawField(self.model.experiences)
	drawField(self.model.actors)
	self.sideBar:draw()
end
