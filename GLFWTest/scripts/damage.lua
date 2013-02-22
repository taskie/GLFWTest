subclass ("Damage", Actor) { }

function Damage:new(damage, x, y, rot, v)
	local shape = Rct.Text(damage, "regular", 8, Col.red, "c")
	Damage.super.new(self, x, y, 0, shape)
	self.v = v / 5 + Mys.mt:next(0.5, 1)
	self.angle = rot + Mys.mt:next(-45, 45)
end

function Damage:update()
	self.x = self.x + self.v * math.cos(math.rad(self.angle))
	self.y = self.y + self.v * math.sin(math.rad(self.angle))
	if self.frame >= 1 * Mys.fps then
		self.isExisting = false
	end
	return Damage.super.update(self)
end