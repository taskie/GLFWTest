subclass("Player", Character) {}

function Player:new()
	Character.new(self, Mys.field.cx, 400, -math.pi_half, 5, 10, 3, 3, 0)
	self.v, self.vslow = 4, 2
	self.shape = Rct.Sprite()
	self.shape:pushChild(Rct.Regular(3, 13, "polygon", Col.blue))
	self.shape:pushChild(Rct.Regular(3, 13, "lineLoop", Col.white))
	self.shape:pushChild(Rct.Circle(3, "polygon", Col.white))
	self.shape:pushChild(Rct.Circle(3, "lineLoop", Col.white))
	self.bulletShape = Rct.Regular(3, 6, "polygon", {1, 1, 1, 0.3})
	self.bucket = false
	self.captureR = 0
	self.captureRMax = 100
	self.lastShot = 20
	self.shotInterval = 10
	self.nearestEnemy = {}
	self.weapons = {}
	self.weaponsChoice = 1
	self.weaponsChoiceMax = 4
end

function Player:update()
	local d = {0, 0}

	if self.bucket == false then
		self.bucket = Game.playerBulletsBucket
	end

	if self.frame % (Mys.fps * 10) < 1 then
		self.hp = self.hp + 1
		if self.hp > self.hpmax then self.hp = self.hpmax end
	end

	if input:isPressed("LEFT") and self.x >= Mys.field.x + 10 then
		d[1] = -1
	end
	if input:isPressed("RIGHT") and self.x <= Mys.field.wx - 10 then
		d[1] = 1
	end
	if input:isPressed("UP") and self.y >= Mys.field.y + 10 then
		d[2] = -1
	end
	if input:isPressed("DOWN") and self.y <= Mys.field.hy - 10 then
		d[2] = 1
	end

	local dist = math.sqrt(d[1] * d[1] + d[2] * d[2])
	if dist ~= 0 then
		d[1] = d[1] / dist
		d[2] = d[2] / dist
	end

	local speed = self.v
	if input:isPressed("LSHIFT") then
		speed = self.vslow
	end

	self.x = self.x + d[1] * speed
	self.y = self.y + d[2] * speed


	self.nearestEnemy = {}
	for key, enemy in pairs(Game.enemies) do
		local dist = Mys.distance(self, enemy)
		if self.nearestEnemy[1] == nil or dist < self.nearestEnemy[1] then
			self.nearestEnemy[1] = dist
			self.nearestEnemy[2] = enemy
			self.nearestEnemy[3] = key
		end
	end

	self.lastShot = self.lastShot + 1
	if not input:isPressed("Z") then
		if self.lastShot > self.shotInterval and not Game.isHell then
			self:shoot(self.x, self.y, 9, self.rot, 3)
			-- MXR:playSound("playershoot", self.x / Mys.screen.wx)
			self.lastShot = 0
		end

		for i, weapon in pairs(self.weapons) do
			weapon:attack()
		end
	end

	if input:isPressed(SDLK_z) then
		local weaponsLength = 0
		
		for i = 1, self.weaponsChoiceMax do
			if self.weapons[i] ~= nil then
				weaponsLength = weaponsLength + 1
			end
		end
		
		if self.captureR < self.captureRMax / (math.pow(weaponsLength + 1, 1 / 3)) then
			self.captureR = self.captureR + (self.weaponsChoiceMax - weaponsLength + 1) / 2
		end

		Game.drawables[Mys.nextId(Game.drawables)]
		= Drawable(Rct.Circle(self.captureR, nil, {1,1,1,0.2}), self.x, self.y, self.rot, 1)

		if self.nearestEnemy[1] ~= nil and self.nearestEnemy[1] < self.captureR then
			Game.enemies[self.nearestEnemy[3]] = nil
			local enemy = self.nearestEnemy[2]
			
			local choice = self.weaponsChoice
			local upgradeFlag = false
			
			for i, weapon in pairs(self.weapons) do
				if weapon.name == enemy.name then
					choice = i
					upgradeFlag = true
				end
			end
			
			self.captureR = 0
			-- MXR:playSound("ok")
			
			if upgradeFlag then
				self.weapons[choice]:takeExp(enemy.exp)
			else
				self.weapons[choice] = Weapon(enemy)
				local nextchoice = self.weaponsChoice % self.weaponsChoiceMax + 1
				if self.weapons[nextchoice] == nil then
					self.weaponsChoice = nextchoice
				end
			end
		end
	else
		self.captureR = 0
	end

	if input:isJustPressed("X") then
		local choiceMax = self.weaponsChoiceMax
		if choiceMax ~= 0 then
			-- MXR:playSound("weaponchoice")
			self.weaponsChoice = self.weaponsChoice % choiceMax + 1
		end
	end

	if input:isJustPressed("C") then
		if self.weapons[self.weaponsChoice] ~= nil then
			local weapon = self.weapons[self.weaponsChoice]

			if not weapon.bomb then
				if weapon.level >= 5 then
					for k, bullet in pairs(Game.enemyBulletsBucket.bullets) do
						bullet.v = 3 * bullet.v
						bullet.rot = Mys.angle(self, bullet)
					end
				end

				weapon.bomb = true
				weapon.bombFrameMax = weapon.level * Mys.fps
				weapon.bombFrame = weapon.bombFrameMax
			end
		end
	end

	for k, weapon in pairs(self.weapons) do
		if weapon.bomb then
			weapon:attack()
			weapon:attack()
			weapon:attack()

			weapon.bombFrame = weapon.bombFrame - 1
			if weapon.bombFrame == 0 then
				self.weapons[k] = nil
			end
		end
	end

	self.bucket = self.bucket or Game.playerBulletsBucket

	if input:isJustPressed("ESC") then
		self:damaged(self.hp)
	end

	self.frame = self.frame + 1

	return true
end

function Player:levelUp()
	local up = false
	while self.exp >= math.pow(self.level + 1, 3) do
		self.level = self.level + 1
		self.hpmax = self.hpmax + 2
		self.hp = self.hp + 2
		self.power = self.power + 1
		self.defence = self.defence + 1
		up = true
	end
	if up then
		-- MXR:playSound("levelup")
		Game.drawables.levelup = FadeOut(Rct.Text("LEVEL UP", "m+r9", Col.yellow, "ct"), self.x, self.y + 30, 0, Mys.fps)
	end
	return up
end

function Player:draw()
	self.shape:draw(self.x, self.y, self.rot)
end
