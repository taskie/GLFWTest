-- GameClear

subclass ("GameClear", Actor, Scn) { }

function Scn.GameClear:new(oldScene)
	Scn.GameClear.super.new(self)
	profile.records.cleared = true
	
	self.oldScene = oldScene
	Mxr:fadeOut(oldScene.model.stage.nowPlaying, Mys.fps * 5)
	
	local textColor = {0.2, 0.2, 0.2, 1}
	self.input = Input()
	self.gameClear = Rct.Text("GAME CLEAR", "thin", 48, textColor, "c")
	self.scoreText = Rct.Text("Score : 0", "regular", 16, textColor, "c")
	self.score = 0
	
	self.nextScene = false
end

function Scn.GameClear:update()
	self.oldScene.model:update()
	self.oldScene.view:update()
	Mxr:update()
	for k, player in self.oldScene.model.players:pairs() do
		self.score = player.exp * 2
	end
	self.scoreText:renew("Score : " .. self.score)
	if self.frame > Mys.fps * 2 and self.input:isJustPressed("Z") then
		if self.oldScene.model.input.classname == "LoggingInput" then
			local replayData = {}
			replayData.date = os.date("%y/%m/%d %T")
			replayData.score = self.score
			replayData.version = Mys.version
			replayData.seed = self.oldScene.model.seed
			replayData.parameter = self.oldScene.parameter
			replayData.log = self.oldScene.model.input.log
			self.nextScene = Scn.SaveReplay(self, replayData)
		else
			self.nextScene = Scn.Title()
			Mxr.fadeOutInfo[self.oldScene.model.stage.nowPlaying] = nil
		end
	end

	return Scn.GameClear.super.update(self)
end

function Scn.GameClear:draw()
	self.oldScene:draw()
	self.gameClear:draw(Mys.screen.cx, 230)
	self.scoreText:draw(Mys.screen.cx, 270)
end