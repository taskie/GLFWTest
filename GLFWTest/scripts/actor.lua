Motion = {}

function Motion:uniform()
	local rad = math.rad(self.rot)
	self.x = self.x + self.v * math.cos(rad)
	self.y = self.y + self.v * math.sin(rad)
end

function Motion:uniaccel()
	assert(self.a)
	local rad = math.rad(self.rot)
	self.x = self.x + self.v * math.cos(rad)
	self.y = self.y + self.v * math.sin(rad)
	self.v = self.v + self.a
end

class ("Actor") { }

function Actor:new(x, y, rot, shape)
	self.x = x or 0
	self.y = y or 0
	self.rot = rot or 0
	self.shape = shape or Mys.nilShape
	self.isExisting = true
	self.frame = 0
end

function Actor:update()
	self.frame = self.frame + 1
	return self.isExisting
end

function Actor:draw()
	self.shape:draw(self.x, self.y, self.rot)
end
