local playerShape = Rct.Sprite()
playerShape:pushChild(Rct.Regular(3, 13, "polygon", Col.black))
playerShape:pushChild(Rct.Regular(3, 13, "lineLoop", Col.black))
playerShape:pushChild(Rct.Circle(3, "polygon", Col.orange))
playerShape:pushChild(Rct.Circle(3, "lineLoop", Col.orange))

local particles = {}
local particlesColor = {0, 0, 0, 0.4}
particles[1] = Rct.Path({{13, 0}, {-6.5, 11.25}}, "lines", particlesColor, 0, 0)
particles[2] = Rct.Path({{-6.5, 11.25}, {-6.5, -11.25}}, "lines", particlesColor, 0, 0)
particles[3] = Rct.Path({{-6.5, -11.25}, {13, 0}}, "lines", particlesColor, 0, 0)

subclass ("Player", Character)
{
	shape = playerShape,
	particles = particles
}

function Player:new(x, y, rot, model, input)
	local param = { r = 3, hp = 1000, power = 5, defence = 5, exp = 1 }
	Player.super.new(self, x, y, rot, model, param)
	self.bulletsField = model.playersBullets
	self.enemiesField = model.enemies
	
	self.v = 0
	self.vfast, self.vslow = 4, 2
	
	self.input = input
	
	self.weapon = {}
	self.weapon.actors = {}
	self.weapon.length = 0
	self.weapon.lengthMax = 3
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
	
	local speed = not self.input:isPressed("LSHIFT") and self.vfast or self.vslow
	self.x = self.x + d[1] * speed
	self.y = self.y + d[2] * speed
end

function Player:chooseWeapon()
	if self.input:isJustPressed("X") then
		Mxr:rewindAndPlay("weaponchoice")
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
		Mxr:rewindAndPlay("ok")
	
		if upgradeFlag then
			self.weapon.actors[choice].exp = self.weapon.actors[choice].exp + nearest.exp
			self.weapon.actors[choice]:levelUp()
		else
			profile.records.captured[nearest.classname] = true
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
	local fireFlag = not self.input:isPressed("Z")
	for i, actor in pairs(self.weapon.actors) do
		actor:update()
		if fireFlag then
			actor:fire()
		end
	end
end

function Player:shoot(...)
	return Player.super.shoot(self, ...)
end

function Player:levelUp(...)
	local ret = Player.super.levelUp(self, ...)
	if ret then
		Mxr:rewindAndPlay("levelup")
	end
	return ret
end

function Player:damaged(...)
	Mxr:rewindAndPlay("playerdamaged")
	self.model.actors:push(DamageScreen())
	Player.super.damaged(self, ...)
end