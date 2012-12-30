class ("Stage") { }

function Stage:new(parameter)
	self.count = 0
	self.countMax = parameter.stages or 10
	self.stageFrameMax = Mys.fps * 60
	self.stageFrame = self.stageFrameMax - Mys.fps * 3
	
	self.enemyProbability = parameter.enemyProbability or 0.01
	self.enemyTable = {}
	self.enemyTable[1] = {{Enm.Zaco, 1}, {Enm.Winder, 1}, {Enm.Sniper, 1}}
	self.enemyTable[2] = {{Enm.Zaco, 1}, {Enm.Winder, 1}, {Enm.Sniper, 1}, {Enm.Scatter, 1}}
	self.enemyTable[3] = {{Enm.Winder, 1}, {Enm.Sniper, 1}, {Enm.Scatter, 1}, {Enm.Spiral, 1}}
	self.enemyTable[4] = {{Enm.Sniper, 1}, {Enm.Scatter, 1}, {Enm.Spiral, 1}, {Enm.Bee, 1}, {Enm.Base, 1}}
	self.enemyTable[5] = {{Enm.Scatter, 1}, {Enm.Spiral, 1}, {Enm.Bee, 1}, {Enm.Base, 1}, {Enm.Block, 1}}
	self.enemyTable[6] = {{Enm.Spiral, 1}, {Enm.Bee, 1}, {Enm.Base, 1}, {Enm.Block, 1}, {Enm.Quick, 1}}
	self.enemyTable[7] = {{Enm.Bee, 1}, {Enm.Base, 1}, {Enm.Block, 1}, {Enm.Quick, 1}, {Enm.Bug, 1}}
	self.enemyTable[8] = {{Enm.Base, 1}, {Enm.Block, 1}, {Enm.Quick, 1}, {Enm.Bug, 1}, {Enm.Sharp, 1}, {Enm.Fatal, 1}}
	self.enemyTable[9] = {{Enm.Block, 1}, {Enm.Quick, 1}, {Enm.Bug, 1}, {Enm.Sharp, 1}, {Enm.Fatal, 1}, {Enm.Back, 1}}
	self.enemyTable[10] = {{Enm.Quick, 1}, {Enm.Bug, 1}, {Enm.Sharp, 1}, {Enm.Fatal, 1}, {Enm.Back, 1}, {Enm.Reflect, 1}}
	
	self.enemyWeight = {}
	for stage, stageTable in ipairs(self.enemyTable) do
		self.enemyWeight[stage] = Mys.tableToWeightArray(stageTable)
	end
	self.isCleared = false
	
	self.bgms = {}
	self.bgms[1] = "conduit"
	self.bgms[4] = "retrofire"
	self.bgms[7] = "influx"
	self.bgms[11] = "febricula_inf"
	self.bgms[14] = "cascade_inf"
	self.bgms[17] = "stig_inf"
	self.bgmCycle = 20
	self.nowPlaying = false
	
	self.frame = 0
end

function Stage:update(model)
	if self.isCleared then return end
	
	if self.count > 0 then
		local noEnemy = model.enemies:isEmpty()
		if model.random:next() < self.enemyProbability or noEnemy then
			local tableNum = (self.count - 1) % 10 + 1
			local en = Mys.choiceWithWeight(self.enemyWeight[tableNum], model.random)
			local enemy = self.enemyTable[tableNum][en][1](model)
			if self.count > 10 then
				enemy:takeExp(math.floor((self.count - 1) / 10) * 8192)
			end
			model.enemies:add(enemy)
		end
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

	-- Main.scene = GameClear(Main.scene)
end
