subclass ("DamageScreen", Actor) {}

function DamageScreen:new(x, y, rot, model, param)
	DamageScreen.super.new(self, x, y, rot)
	
	self.overRect = Rct.Rect(Mys.screen.w, Mys.screen.h, "polygon", {1, 0, 0, 0.1}, 0, 0)
end

function DamageScreen:update()
	if self.frame >= 1 then
		self.isExisting = false
	end
	return DamageScreen.super.update(self)
end

function DamageScreen:draw()
	self.overRect:draw()
end