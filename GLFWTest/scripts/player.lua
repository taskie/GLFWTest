local playerShape = Rct.Sprite()
playerShape:pushChild(Rct.Regular(3, 13, "polygon", Col.black))
playerShape:pushChild(Rct.Regular(3, 13, "lineLoop", Col.black))
playerShape:pushChild(Rct.Circle(3, "polygon", Col.orange))
playerShape:pushChild(Rct.Circle(3, "lineLoop", Col.orange))

subclass ("Player", Character)
{
	shape = playerShape
}

function Player:new(x, y, rot, model, input)
	local param = { r = 3, hp = 10000000, power = 5, defence = 5, exp = 0 }
	Player.super.new(self, x, y, rot, model, param)
	self.bulletsField = model.playersBullets
	self.enemiesField = model.enemies
	
	self.v, self.vslow = 4, 2
	
	self.input = input
	
	self.weapon = {}
	self.weapon.actors = {}
	self.weapon.length = 0
	self.weapon.lengthMax = 4
	self.weapon.choice = 1
	
	self.capture = {}
	self.capture.r = 0
	self.capture.rMax = 100
	
	self.shape = Player.shape
	self.bulletShape = Player.bulletShape
end


function Player:update()
	self:recovery()
	self:move()
	self:chooseWeapon()
	self:updateCapture()
	self:fire()
	return Player.super.update(self)
end

function Player:recovery()
	if self.frame % (Mys.fps * 10) < 1 then
		self.hp = self.hp + math.ceil(self.hp / 25)
		if self.hp > self.hpmax then self.hp = self.hpmax end
	end
end

function Player:move()
	local d = {0, 0}
	
	if self.input:isPressed("LEFT") and self.x >= Mys.field.x + 10 then
		d[1] = -1
	end
	if self.input:isPressed("RIGHT") and self.x <= Mys.field.wx - 10 then
		d[1] = 1
	end
	if self.input:isPressed("UP") and self.y >= Mys.field.y + 10 then
		d[2] = -1
	end
	if self.input:isPressed("DOWN") and self.y <= Mys.field.hy - 10 then
		d[2] = 1
	end

	local dist = math.sqrt(d[1] * d[1] + d[2] * d[2])
	if dist ~= 0 then
		d[1] = d[1] / dist
		d[2] = d[2] / dist
	end
	
	local speed = not self.input:isPressed("LSHIFT") and self.v or self.vslow
	self.x = self.x + d[1] * speed
	self.y = self.y + d[2] * speed
end

function Player:chooseWeapon()
	if self.input:isJustPressed("X") then
		self.weapon.choice = self.weapon.choice % self.weapon.lengthMax + 1
	end
end

function Player:updateCapture()
	if self.input:isPressed("Z") then
		if self.capture.r < self.capture.rMax / (math.pow(self.weapon.length + 1, 1 / 3)) then
			self.capture.r = self.capture.r + (self.weapon.lengthMax - self.weapon.length + 1) / 2
		end
	else
		self.capture.r = 0
	end
	
	local nearest = self:nearestEnemy()
	if nearest and Mys.distance(self, nearest) < self.capture.r then
		local choice = self.weapon.choice
		local upgradeFlag = false
		
		nearest.bulletsBucket = self.bulletsBucket
		nearest.enemiesBucket = self.enemiesBucket
		
		for i, weapon in pairs(self.weapon.actors) do
			if weapon.name == nearest.classname then
				choice = i
				upgradeFlag = true
			end
		end
			
		self.capture.r = 0
		
		if upgradeFlag then
			self.weapon.actors[choice]:takeExp(nearest.exp)
		else
			if not self.weapon.actors[choice] then
				self.weapon.length = self.weapon.length + 1
			end
			self.weapon.actors[choice] = Weapon(nearest, self)
			local nextchoice = self.weapon.choice % self.weapon.lengthMax + 1
			if self.weapon.actors[nextchoice] == nil then
				self.weapon.choice = nextchoice
			end
		end
		nearest.isExisting = false
	end
end

function Player:fire()
	if self.input:isPressed("Z") then return end
	for i, actor in pairs(self.weapon.actors) do
		actor:update()
	end
end