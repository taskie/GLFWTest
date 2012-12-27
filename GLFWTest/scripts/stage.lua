class ("Stage") { }

function Stage:new(isHell)
	self.count = 0
	self.countMax = 30
	self.stageFrameMax = Mys.fps * 10
	self.stageFrame = self.stageFrameMax - Mys.fps * 3
	
	self.enemyProbability = (isHell and 0.03) or 0.01
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
	self.enemyTable[10] = {{Enm.Quick, 1}, {Enm.Bug, 1}, {Enm.Sharp, 1}, {Enm.Fatal, 1}, {Enm.Back, 1}, {Enm.Refrect, 1}}
	
	self.enemyWeight = {}
	for stage, stageTable in ipairs(self.enemyTable) do
		self.enemyWeight[stage] = Mys.tableToWeightArray(stageTable)
	end
	self.isCleared = false
	
	self.bgms = {}
	self.bgms[1] = ""
	self.bgms[4] = ""
	self.bgms[7] = ""
	self.bgms[11] = ""
	self.bgms[14] = ""
	self.bgms[17] = ""
	
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
				enemy:takeExp(math.floor((self.count - 1) / 10) * 10000)
			end
			model.enemies:add(enemy)
		end
	end
	
	if self.stageFrame == self.stageFrameMax - 5 * Mys.fps then
		if self.bgms[self.count + 1] ~= nil then
			-- MXR:fadeOutBGM(5000)
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
	
	local bgm = self.bgms[self.stageNum]
	if bgm ~= nil then
		-- MXR:playBGM(bgm)
	end
end

function Stage:clear(model)
	-- MXR:fadeOutBGM(5000)
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

function Stage:createPlayer(model)
	return Player(Mys.field.cx, Mys.field.cy + 100, -90, model, Input())
end

