-- Game

subclass ("Game", Actor, Scn) { }

function Scn.Game:new()
	Scn.Game.super.new(self)
	
	local stage = Stage()
	self.model = GameModel(stage)
	self.view = GameView(self.model)
	self.nextScene = false
end

function Scn.Game:update()
	self.model:update()
	self.view:update()

	return Scn.Game.super.update(self)
end

function Scn.Game:draw()
	self.view:draw()
end