subclass ("Bullet", Actor) { }

function Bullet:new(shooter, x, y, rot, v, r, power, shape)
	Bullet.super.new(self, x, y, rot, shape)
	
	-- print(shooter, x, y, rot, v, r, power, shape)
	self.shooter = shooter
	self.v = v
	self.r = r
	self.power = power
	self.move = Motion.uniform
end

function Bullet:update()
	self:move()
	local area = Mys.field
	if not Mys.inRect(self, area.x, area.y, area.wx, area.hy) then
		self.isExisting = false
	end
	return Bullet.super.update(self)
end

function Bullet:damage(actor)
	actor:damagedByBullet(self)
	self.isExisting = false
end
