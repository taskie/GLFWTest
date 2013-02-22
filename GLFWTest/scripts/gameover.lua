-- GameOver

subclass ("GameOver", Actor, Scn) { }

function Scn.GameOver:new(oldScene)
	Scn.GameOver.super.new(self)
	
	self.oldScene = oldScene
	Mxr:stop(oldScene.model.stage.nowPlaying)
	Mxr.fadeOutInfo[self.oldScene.model.stage.nowPlaying] = nil
	
	Mxr:rewindAndPlay("ng")
	
	local textColor = {0.2, 0.2, 0.2, 1}
	self.input = Input()
	self.gameOver = Rct.Text("GAME OVER", "thin", 48, textColor, "c")
	self.scoreText = Rct.Text("Score : 0", "regular", 16, textColor, "c")
	self.score = 0
	
	self.nextScene = false
end

function Scn.GameOver:update()
	for k, player in self.oldScene.model.players:pairs() do
		self.score = player.exp
	end
	self.scoreText:renew("Score : " .. self.score)
	
	if self.frame > Mys.fps * 1 and self.input:isJustPressed("Z")
	   or self.frame > Mys.fps * 10
	then
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

	return Scn.GameOver.super.update(self)
end

function Scn.GameOver:draw()
	self.oldScene:draw()
	self.gameOver:draw(Mys.screen.cx, 230)
	self.scoreText:draw(Mys.screen.cx, 270)
end