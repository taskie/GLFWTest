-- Game

subclass ("Game", Actor, Scn) { }

function Scn.Game:new(input, seed, parameter)
   Scn.Game.super.new(self)
   
   local stage = Stage(parameter)
   self.input = input
   self.escInput = Input()
   self.parameter = parameter
   self.model = GameModel(stage, input, seed, parameter)
   self.view = GameView(self.model, parameter)
   self.nextScene = false
   self.pause = false
end

function Scn.Game:update()
   if self.pause then
      local ret = self.pause:update()
      if self.escInput:isJustPressed("ESC") or ret == "continue" then
	 if self.model.stage.nowPlaying then Mxr:play(self.model.stage.nowPlaying) end
	 self.pause = false
      elseif ret == "title" then
	 if self.model.stage.nowPlaying then
	    Mxr:stop(self.model.stage.nowPlaying)
	    Mxr.fadeOutInfo[self.model.stage.nowPlaying] = nil
	 end
	 self.nextScene = Scn.Title()
      end
      return Scn.Game.super.update(self)
   elseif self.escInput:isJustPressed("ESC") then
      self.pause = Scn.Pause()
      if self.model.stage.nowPlaying then Mxr:pause(self.model.stage.nowPlaying) end
      return Scn.Game.super.update(self)
   end
   
   self.model:update()
   if self.model.input.classname == "ReplayInput" and self.escInput:isPressed("LSHIFT") then
      for i = 1, 5 - 1 do
	 Bck.default:update()
	 self.model:update()
	 local playerAlive = false
	 for k, player in self.model.players:pairs() do
	    playerAlive = playerAlive or player.isExisting
	 end
	 if not playerAlive then
	    break
	 end
      end
   end
   
   self.view:update()
   
   local playerAlive = false
   for k, player in self.model.players:pairs() do
      playerAlive = playerAlive or player.isExisting
   end
   if not playerAlive then
      self.nextScene = Scn.GameOver(self)
   end
   
   if self.model.isCleared then
      self.nextScene = Scn.GameClear(self)
   end
   
   return Scn.Game.super.update(self)
end

function Scn.Game:draw()
   if self.pause then
      return self.pause:draw()
   end
   
   self.view:draw()
end
