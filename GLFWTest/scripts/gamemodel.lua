class ("GameModel") { }

function GameModel:new(stage, seed)
	self.stage = stage
	if seed then
		self.random = random.MersenneTwister(seed)
	else
		self.random = random.MersenneTwister()
	end
	
	self.players = Field()
	self.enemies = Field()
	self.playersBullets = Field()
	self.enemiesBullets = Field()
		
	self.experiences = Field()
	
	self.actors = Set()
	
	self.frame = 0

	self.bulletExpMode = true
	self.enemyWithEnemyMode = true
	self.players:add(stage:createPlayer(self))
end

function GameModel:update()
	self.stage:update(self)
	
	self.players:update()
	self.enemies:update()
	self.playersBullets:update()
	self.enemiesBullets:update()
	self.experiences:update()
	self:collision()
	
	self.actors:removeIf(function (actor) return not actor:update() end)
	
	self.frame = self.frame + 1
end

-- private

function GameModel:collision()
	self:collisionWithBullet(self.players, self.enemiesBullets)
	self:collisionWithBullet(self.enemies, self.playersBullets)
	if self.enemyWithEnemyMode then
		self:collisionWithBullet(self.enemies, self.enemiesBullets)
	end
end

function GameModel:collisionWithBullet(actorField, bulletField)
	local collisionTable = actorField:collisionForField(bulletField)
	for actorId, t in pairs(collisionTable) do
		for bulletId, bullet in pairs(t.others) do
			bullet:damage(t.actor)
		end
	end
end