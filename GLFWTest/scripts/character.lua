subclass ("Character", Actor) { }

function Character:new(x, y, rot, model, param)
	Character.super.new(self, x, y, rot)
	self.model = model
	
	self.r = param.r
	self.hp = param.hp
	self.power = param.power
	self.defence = param.defence
	self.exp = param.exp
	
	self.hpmax = self.hp
	self.level = 1
	self.levelMax = 50
	self:levelUp()
	
	self.bullets = Set()
	self.killer = false
end

function Character:update()
	self.bullets:removeIf(function (bullet) return not bullet.isExisting end)
	return Character.super.update(self)
end

function Character:takeExp(exp)
	self.exp = self.exp + exp
	return self:levelUp()
end

function Character:calcRequiredExp(level)
	return math.pow(self.level + 1, 3)
end

function Character:levelUp()
	local up = false
	if self.level >= self.levelMax then return up end
	while self.exp >= self:calcRequiredExp() do
		self.level = self.level + 1
		self.power = math.ceil(self.power * Mys.levelUpRatio)
		self.defence = math.ceil(self.defence * Mys.levelUpRatio)
		local oldhpmax = self.hpmax
		self.hpmax = math.ceil(self.hpmax * Mys.levelUpRatio)
		self.hp = self.hp + self.hpmax - oldhpmax
		up = true
	end
	return up
end

function Character:death()
	self.isExisting = false
	self.update = function () return false end
	if self.killer then
		self.model.experiences:add(Exp.Path(self.killer, self))
		if self.model.bulletExpMode then
			for id, bullet in self.bullets:pairs() do
				bullet.isExisting = false
				self.model.experiences:add(Exp.Bullet(self.killer, bullet, self.expBulletShape))
			end
		end
	end
end

function Character:shoot(x, y, rot, speed, r, rate)
	assert(self.bulletsField)
	rate = rate or 1
	local bullet = Bullet(self, x, y, rot, speed, r, self.power * rate, self.bulletShape)
	self.bulletsField:add(bullet)
	self.bullets:push(bullet)
end

function Character:calcDamageByBullet(bullet)
	return math.ceil(bullet.power ^ 0.5 * (0.99 ^ self.defence))
end

function Character:damagedByBullet(bullet)
	self.killer = bullet.shooter
	local damage = self:calcDamageByBullet(bullet)
	self:damaged(damage)
	self.model.actors:push(Damage(damage, self.x, self.y, bullet.rot, bullet.v))
	if self.isExisting then
		self.killer = false
	end
end

function Character:damaged(damage)
	self.hp = math.floor(self.hp - damage)
	if self.hp < 0 then self.hp = 0 end
	if self.hp == 0 and self.isExisting then
		self.hp = 0
		self:death()
	end
end

function Character:nearestEnemy()
	if not self.enemiesField then return nil end
	local distanceMin = math.huge
	local enemyMin = false
	for id, enemy in self.enemiesField:pairs() do
		local distance = Mys.distance(self, enemy)
		if distance < distanceMin then
			distanceMin = distance
			enemyMin = enemy
		end
	end
	return enemyMin
end