class ("Stage") { }

function Stage:new(parameter)
   self.count = 0
   self.countMax = parameter.stages or 10
   self.stageFrameMax = Mys.fps * 60
   self.stageFrame = self.stageFrameMax - Mys.fps * 3
   
   self.enemyProbability = parameter.enemyProbability or 0.01
   self.enemyTable = {}
   self.enemyTable[1] = {{Enm.Zaco, 2}, {Enm.Winder, 2}, {Enm.Sniper, 1}, {Enm.Quick, 1}}
   self.enemyTable[2] = {{Enm.Zaco, 1}, {Enm.Winder, 1}, {Enm.Sniper, 2}, {Enm.Quick, 2}, {Enm.Scatter, 1}}
   self.enemyTable[3] = {{Enm.Winder, 2}, {Enm.Sniper, 1}, {Enm.Block, 2}, {Enm.Quick, 1}, {Enm.Scatter, 2}}
   self.enemyTable[4] = {{Enm.Spiral, 2}, {Enm.Block, 2}, {Enm.Scatter, 2}, {Enm.Breakaway, 1}}
   self.enemyTable[5] = {{Enm.Bee, 2}, {Enm.Spiral, 2}, {Enm.Block, 2}, {Enm.Base, 1}, {Enm.Breakaway, 1}}
   self.enemyTable[6] = {{Enm.Bee, 2}, {Enm.Base, 2}, {Enm.Bug, 3}, {Enm.Conveyor, 1}, {Enm.Breakaway, 1}}
   self.enemyTable[7] = {{Enm.Sharp, 2}, {Enm.Bug, 2}, {Enm.Conveyor, 2}, {Enm.Sniper, 1}, {Enm.Block, 1}}
   self.enemyTable[8] = {{Enm.Back, 1}, {Enm.Sharp, 2}, {Enm.Fatal, 2}, {Enm.Block, 1}, {Enm.Curtain, 1}}
   self.enemyTable[9] = {{Enm.Back, 1}, {Enm.Radio, 2}, {Enm.Fatal, 2}, {Enm.Bug, 1}, {Enm.Curtain, 1}}
   self.enemyTable[10] = {{Enm.Back, 1}, {Enm.Sharp, 2}, {Enm.Radio, 2}, {Enm.Fatal, 2}, {Enm.Bug, 1}, {Enm.Block, 1}, {Enm.Reflect, 1}, {Enm.Splash, 1}}
   self.enemyTable[11] = {{Enm.Zaco, 2}, {Enm.Winder, 2}, {Enm.Sniper, 1}, {Enm.Quick, 1}, {Enm.Conveyor, 2}, {Enm.Block, 2}, {Enm.Splash, 1}}
   self.enemyTable[12] = {{Enm.Base, 2}, {Enm.Back, 1}, {Enm.Bee, 1}, {Enm.Curtain, 1}, {Enm.Breakaway, 1}, {Enm.Radio, 1}}
   self.enemyTable[13] = {{Enm.Spiral, 2}, {Enm.Splash, 2}, {Enm.Sharp, 2}, {Enm.Curtain, 2}, {Enm.Scatter, 2}}
   self.enemyTable[14] = {{Enm.Back, 3}, {Enm.Zaco, 2}, {Enm.Conveyor, 2}, {Enm.Spiral, 1}}
   self.enemyTable[15] = {{Enm.Bee, 3}, {Enm.Curtain, 1}, {Enm.Base, 1}, {Enm.Breakaway, 1}}
   self.enemyTable[16] = {{Enm.Conveyor, 3}, {Enm.Back, 1}, {Enm.Block, 1}, {Enm.Bug, 1}, {Enm.Base, 1}, {Enm.Scatter, 1}}
   self.enemyTable[17] = {{Enm.Sharp, 2}, {Enm.Sniper, 2}, {Enm.Block, 2}, {Enm.Quick, 2}, {Enm.Winder, 1}}
   self.enemyTable[18] = {{Enm.Curtain, 2}, {Enm.Bee, 2}, {Enm.Winder, 2}, {Enm.Back, 1}, {Enm.Fatal, 2}, {Enm.Bug, 2}}
   self.enemyTable[19] = {{Enm.Zaco, 2}, {Enm.Winder, 2}, {Enm.Sniper, 2}, {Enm.Quick, 2}, {Enm.Scatter, 2}, {Enm.Block, 2},
			  {Enm.Spiral, 2}, {Enm.Bee, 2}, {Enm.Breakaway, 1}}
   self.enemyTable[20] = {{Enm.Bug, 2}, {Enm.Base, 2}, {Enm.Sharp, 2}, {Enm.Fatal, 2}, {Enm.Back, 2},
			  {Enm.Reflect, 1}, {Enm.Radio, 1}, {Enm.Conveyor, 1}, {Enm.Splash, 1}, {Enm.Curtain, 1}}

   self.enemyWeight = {}
   for stage, stageTable in ipairs(self.enemyTable) do
      self.enemyWeight[stage] = Mys.tableToWeightArray(stageTable)
   end
   self.isCleared = false
   
   self.bgms = {}
   self.bgms[1] = "febricula"
   self.bgms[4] = "cascade"
   self.bgms[7] = "stig"
   self.bgms[11] = "conduit"
   self.bgms[14] = "retrofire"
   self.bgms[17] = "influx"
   self.bgmCycle = 20
   self.nowPlaying = false
   
   self.frame = 0
end

function Stage:update(model)
   if self.isCleared then return end
   
   if self.count > 0 then
      local noEnemy = model.enemies:isEmpty()
      if model.random:next() < self.enemyProbability or noEnemy then
	 local tableNum = self.count
	 local en = Mys.choiceWithWeight(self.enemyWeight[tableNum], model.random)
	 local enemy = self.enemyTable[tableNum][en][1](model)
	 enemy:takeExp(math.ceil(self.count ^ 3) - 1)
	 model.enemies:add(enemy)
      end
   end

   if self.count == 10 and self.stageFrame == 30 * Mys.fps then
      model.enemies:add(Enm.Ring(model))
   end
   if self.count == 20 and self.stageFrame == 30 * Mys.fps then
      model.enemies:add(Enm.BlackRing(model))
      model.enemies:add(Enm.BlackSide(model, Mys.field.cx - 100))
      model.enemies:add(Enm.BlackSide(model, Mys.field.cx + 100))
   end
   
   if self.stageFrame == 57 * Mys.fps then
      Bck.default:accel(Mys.fps * 5)
   end
   
   if self.stageFrame == self.stageFrameMax - 5 * Mys.fps then
      if self.count ~= self.countMax then
	 local bgm = self.bgms[(self.count + 1) % self.bgmCycle]
	 if bgm ~= nil then
	    Mxr:fadeOut(self.nowPlaying, math.floor(Mys.fps * 4.75))
	 end
      end
   end
   
   self.stageFrame = self.stageFrame + 1
   
   if self.stageFrame >= self.stageFrameMax then
      self:next(model)
   end
   
   self.frame = self.frame + 1
end

function Stage:next(model)
   local player = false
   for k, player_ in model.players:pairs() do
      player = player_
   end
   
   for id, bullet in model.enemiesBullets:pairs() do
      bullet.isExisting = false
      model.experiences:add(Exp.Bullet(player, bullet, bullet.shooter.expBulletShape))
   end

   for k, enemy in model.enemies:pairs() do
      enemy.killer = player
      enemy:death()
   end
   
   if self.count == self.countMax then
      self:clear(model)
      return
   end
   
   self.stageFrame = 0
   self.count = self.count + 1
   
   local bgm = self.bgms[self.count % self.bgmCycle]
   if bgm ~= nil then
      if self.nowPlaying then
	 Mxr:stop(self.nowPlaying)
      end
      Mxr:rewindAndPlay(bgm)
      self.nowPlaying = bgm
   end
end

function Stage:clear(model)
   self.isCleared = true
   -- Main.scene = GameClear(Main.scene)
end
