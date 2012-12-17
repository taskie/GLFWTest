Enm = {}

-- Zaco

subclass ("Zaco", Enemy, Enm)
{
	vertices = {{0, 0}, {0, 20}, {13.3, 0}, {20, 10}, {13.3, 20}},
	cx = 10, cy = 10,
	color = {0.3, 0.4, 0.9, 1.0},
	param = {r = 3, hp = 1, power = 1, defence = 1, exp = 1}
}
Enemy.setEnemy(Enm.Zaco)
Enm.Zaco.move = Motion.uniform

function Enm.Zaco:new(model, x, y, rot)
	x = x or model.random:next(Mys.field.x, Mys.field.wx)
	y = y or -10
	rot = rot or 90
	Enemy.new(self, x, y, rot, model, self.param)
	self.v = 0.5
end

function Enm.Zaco:fire()
	if self.frame % 30 == 0 then
		local nearest = self:nearestEnemy()
		local angle = self.rot
		local way = self.level
		if way > 100 then way = 100 end
		for i = 0, way - 1 do
			if self.level >= 30 then self:shoot(self.x, self.y, angle + 360 * i / way, 3, 3, 1) end
			self:shoot(self.x, self.y, angle + 360 * i / way, 4, 3, 1)
		end
	end
end

-- Winder

subclass ("Winder", Enemy, Enm)
{
	vertices = {{0, 0}, {20, 0}, {10, 10}, {20, 20}, {0, 20}},
	cx = 10, cy = 10,
	color = {1, 0, 0.3, 1.0},
	param = {r = 3, hp = 3, power = 1, defence = 2, exp = 2}
}
Enemy.setEnemy(Enm.Winder)
Enm.Winder.move = Motion.uniform

function Enm.Winder:new(model, x, y, rot)
	local default = not x
	x = x or model.random:next(Mys.field.x, Mys.field.wx)
	y = y or -10
	rot = rot or 90
	Enemy.new(self, x, y, rot, model, self.param)
	if default then
		local nearest = self:nearestEnemy()
		if nearest then
			self.rot = Mys.angle(self, nearest)
		end
	end
	self.v = 1
end

function Enm.Winder:fire()
	local interval = 20 - self.level
	if interval < 5 then interval = 5 end
	local angle = 45 - 2 * self.level
	if angle < 5 then angle = 5 end
	
	if self.frame % interval == 0 then
		self:shoot(self.x, self.y, self.rot + angle, 4, 3, 1)
		self:shoot(self.x, self.y, self.rot - angle, 4, 3, 1)
		if self.level >= 30 then
			self:shoot(self.x, self.y, self.rot + angle * 2, 4, 3, 1)
			self:shoot(self.x, self.y, self.rot - angle * 2, 4, 3, 1)
		end
	end
end

-- Sniper

subclass ("Sniper", Enemy, Enm)
{
	vertices = {{0, 10}, {10, 0}, {10, 5}, {20, 10}, {10, 15}, {10, 20}},
	cx = 10, cy = 10,
	color = {0.5, 0.3, 0.3, 1.0},
	param = {r = 3, hp = 5, power = 2, defence = 2, exp = 4}
}
Enemy.setEnemy(Enm.Sniper)

function Enm.Sniper:new(model, x, y, rot)
	x = x or model.random:next(Mys.field.x, Mys.field.wx)
	y = y or -10
	rot = rot or 90 + model.random:next(-5, 5)
	Enemy.new(self, x, y, rot, model, self.param)
	self.v = 1
end

function Enm.Sniper:move()
	local nearest = self:nearestEnemy()
	if nearest then
		local angle = Mys.angle(self, nearest)
		local dx = math.cos(math.rad(angle)) * 0.01 + math.cos(math.rad(self.rot))
		local dy = math.sin(math.rad(angle)) * 0.01 + math.sin(math.rad(self.rot))
		self.rot = math.deg(math.atan2(dy, dx))
	end
	
	Motion.uniform(self)
end

function Enm.Sniper:fire()
 	local interval = 60 + math.floor(30 / self.level)
 	if self.level >= 30 then interval = 30 end
	if self.frame % interval == 0 then
		local num = 2 + self.level
		if num > 10 then num = 10 end
		for i = 0, num - 1 do
			self:shoot(self.x, self.y, self.rot, 1.5 + 0.5 * i, 3, 1)
		end
	end
end

-- Scatter

subclass ("Scatter", Enemy, Enm)
{
	vertices = {{0,0},{5,0},{10,10},{15,0},{20,0},{20,5},{10,10},{20,15},{20,20},{15,20},{10,10},{5,20},{0,20},{0,15},{10,10},{0,5}},
	cx = 10, cy = 10,
	color = {0.4, 0.4, 0.7, 1.0},
	param = {r = 3, hp = 7, power = 3, defence = 4, exp = 8}
}
Enemy.setEnemy(Enm.Scatter)
Enm.Scatter.move = Motion.uniform

function Enm.Scatter:new(model, x, y, rot)
	if not x then
		y = model.random:next(100, 240)
		if model.random:next() < 0.5 then
			x = -10
			rot = 0
		else
			x = Mys.screen.wx + 10
			rot = 180
		end
	end
	Enemy.new(self, x, y, rot, model, self.param)
	self.v = 0.5
end

function Enm.Scatter:fire()
	local interval = self.level >= 30 and 30 or 60
	if self.frame % interval < 1 then
		local way = 7 + self.level * 2
		if way > 100 then way = 100 end
		for i = 1, way do
			self:shoot(self.x, self.y, self.model.random:next(0, 360), self.model.random:next(1.5, 4), 3, 1)
		end
	end
end

-- Spiral

subclass ("Spiral", Enemy, Enm)
{
	vertices = {{10, 10},{0, 10},{0, 20},{20, 0},{20, 10},{10, 10},{10, 0},{0, 0},{20, 20},{10,20}},
	cx = 10, cy = 10,
	color = {0.3, 0.5, 0.9, 1.0},
	param = {r = 3, hp = 9, power = 3, defence = 3, exp = 16}
}
Enemy.setEnemy(Enm.Spiral)

function Enm.Spiral:new(model, x, y, rot)
	x = x or Mys.field.cx
	y = y or -10
	rot = rot or 90 + model.random:next(-15, 15)
	
	if model.random:next() < 0.5 then
		self.sign = 1
	else
		self.sign = -1
	end
	Enemy.new(self, x, y, rot, model, self.param)
	self.v = 1
end

function Enm.Spiral:move()
	Motion.uniform(self)
	self.rot = self.rot + self.sign * 1.5 * math.cos(self.frame / 40)
end

function Enm.Spiral:fire()
	if self.frame % 16 == 0 then
		local way = 3 + self.level
		if way > 30 then way = 30 end
		for i = 0, way - 1 do
			self:shoot(self.x, self.y, self.rot + i / way * 360, 2.5, 1)
		end
	elseif self.level >= 30 and self.frame % 16 == 8 then
		local way = 3 + self.level
		if way > 30 then way = 30 end
		for i = 0, way - 1 do
			self:shoot(self.x, self.y, self.rot + i / way * 360, 3, 1)
		end
	end
end

-- Bee

subclass ("Bee", Enemy, Enm)
{
	vertices = {{0, 0}, {5, 0}, {5, 20}, {0, 20}, {0, 15}, {20, 15}, {20, 20}, {15, 20}, {15, 0}, {20, 0}, {20, 5}, {0, 5}},
	cx = 10, cy = 10,
	color = {0.7, 0.7, 0.1, 1.0},
	param = {r = 3, hp = 11, power = 1, defence = 5, exp = 32}
}
Enemy.setEnemy(Enm.Bee)
Enm.Bee.move = Motion.uniform

function Enm.Bee:new(model, x, y, rot)
	x = x or model.random:next(Mys.field.x, Mys.field.wx)
	y = y or -10
	rot = rot or 90
	
	Enemy.new(self, x, y, rot, model, self.param)
	self.v = 0.5
	self.k = model.random:next(0, 360)
end

function Enm.Bee:fire()
	local interval = 60
	if self.level >= 30 then interval = 30 end
	if self.frame % interval < 1 then
		local way = 1 + self.level
		if way > 10 then way = 10 end
		local way2 = 5
		for j = 0, way2 - 1 do
			for i = 0, way - 1 do
				self:shoot(self.x, self.y, self.rot + self.k + i * 2 + 360 * j / way2, 3, 1)
			end
		end
		self.k = self.k + 33.4
	end
end

-- Base

subclass ("Base", Enemy, Enm)
{
	vertices = {{0, 20}, {10, 20}, {20, 10}, {10, 0}, {0, 0}},
	cx = 10, cy = 10,
	color = {0.2, 0.8, 0.6, 1.0},
	param = {r = 3, hp = 20, power = 5, defence = 5, exp = 64}
}
Enemy.setEnemy(Enm.Base)
Enm.Base.move = Motion.uniform

function Enm.Base:new(model, x, y, rot)
	x = x or model.random:next(Mys.field.x, Mys.field.wx)
	y = y or -10
	rot = rot or 90
	
	Enemy.new(self, x, y, rot, model, self.param)
	self.v = 0.5
	self.sign = model.random:next() < 0.5 and 1 or -1
	self.k = model.random:next(0, 360)
end

function Enm.Base:fire()
	local interval = 9 - math.floor(self.level / 3)
	if interval < 2 then interval = 2 end
	if self.frame % interval == 0 then
		self:shoot(self.x, self.y, self.k, 3, 1)
		self:shoot(self.x, self.y, self.k, 4, 1)
		if self.level >= 30 then self:shoot(self.x, self.y, self.k, 5, 1) end
		local drot = 21.1843 - self.level
		if drot < 7.1 then drot = 7.1843 end
		self.k = self.k + drot * self.sign
	end
end

-- Block

subclass ("Block", Enemy, Enm)
{
	vertices = {{0, 0}, {20, 0}, {20, 20}, {0, 20}},
	cx = 10, cy = 10,
	color = {0.5, 0.5, 0.5, 1.0},
	param = {r = 3, hp = 20, power = 1, defence = 255, exp = 128}
}
Enemy.setEnemy(Enm.Block)
Enm.Block.move = Motion.uniform

function Enm.Block:new(model, x, y, rot)
	x = x or model.random:next(Mys.field.x + 50, Mys.field.wx - 50)
	y = y or -10
	rot = rot or 90 + model.random:next(-15, 15)
	
	Enemy.new(self, x, y, rot, model, self.param)
	self.v = 0.5
	self.sign = model.random:next() < 0.5 and 1 or -1
	self.k = model.random:next(0, 360)
end

function Enm.Block:fire()
	local n = math.floor(self.level / 2)
	if n > 20 then n = 20 end
	if self.frame % 2 == 0 and self.frame % 30 < n then
		local way = self.level >= 30 and 8 or 4
		for i = 0, way - 1 do
			self:shoot(self.x, self.y, self.rot + i * 360 / way + self.k, 3, 1)
		end
	elseif self.frame % 30 == 30 - 1 then
		self.k = self.k + 49.777 * self.sign
	end
end