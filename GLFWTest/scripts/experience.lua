subclass ("Experience", Actor) { }

function Experience:new(x, y, rot, exp, to, v, r, shape)
	Experience.super.new(self, x, y, rot, shape)
	self.exp = exp
	self.to = to
	self.r = r
	self.v = v
	self.dx = v * math.cos(math.rad(self.rot))
	self.dy = v * math.sin(math.rad(self.rot))
	self.move = Motion.uniform
end

function Experience:update()
	if self.frame > Mys.fps * 5 then self.isExisting = false end
	local depth = 10
	while depth > 0 and self.to and not self.to.isExisting do
		self.to = self.to.killer
		depth = depth - 1
	end
	if depth == 0 then self.to = false end
	if self.frame > Mys.fps * 0.5 then
		if self.to then
			if Mys.collision(self, self.to) then
				self:giveExp(self.to)
				self.isExisting = false
			end
			local distance = Mys.distance(self, self.to)
			self.dx = self.dx + 0.3 * math.cos(math.rad(Mys.angle(self, self.to))) * distance
			self.dy = self.dy + 0.3 * math.sin(math.rad(Mys.angle(self, self.to))) * distance
		end
		self.v = math.sqrt(math.pow(self.dx, 2) + math.pow(self.dy, 2))
		if self.v > 7 then
			local ratio = self.v / 7
			self.v = 7
			self.dx = self.dx / ratio
			self.dy = self.dy / ratio
		end
		self.rot = math.deg(math.atan2(self.dy, self.dx))
	end
	self:move()
	
	return Experience.super.update(self)
end

function Experience:giveExp(actor)
	actor:takeExp(self.exp)
	self.isExisting = false
end

Exp = {}

subclass ("Bullet", Experience, Exp) { }

function Exp.Bullet:new(to, bullet, expshape)
	Exp.Bullet.super.new(self, bullet.x, bullet.y, bullet.rot, 1, to, bullet.v, bullet.r + 3, expshape)
end

subclass ("Path", Experience, Exp) { }

local mt = random.MersenneTwister()

function Exp.Path:new(to, actor)
	Exp.Path.super.new(self, actor.x, actor.y, actor.rot, actor.exp, to, actor.v, actor.r + 3, false)
	
	self.lines = actor.particles
	self.particles = {}
	for i, line in ipairs(self.lines) do
		table.insert(self.particles, {
			line = line, x = 0, y = 0, rot = 0,
			dx = mt:next(-0.4, 0.4), dy = mt:next(-0.4, 0.4), drot = mt:next(-0.08, 0.08)
		})
	end
end

function Exp.Path:update()
	for i, particle in ipairs(self.particles) do
		particle.x = particle.x + particle.dx
		particle.y = particle.y + particle.dy
		particle.rot = particle.rot + particle.drot
	end
	
	return Exp.Path.super.update(self)
end

function Exp.Path:draw()
	for i, particle in ipairs(self.particles) do
		particle.line:draw(self.x + particle.x, self.y + particle.y, self.rot + particle.rot)
	end
end