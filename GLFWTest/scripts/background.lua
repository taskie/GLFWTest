subclass ("Background", Actor) {}

function Background:new(x, y, rot, model, param)
	Background.super.new(self, x, y, rot)
	
	self.bgRect = Rct.Rect(Mys.screen.w, Mys.screen.h, "polygon", {0.95, 0.95, 0.95}, 0, 0)
end

function Background:update()
	return Background.super.update(self)
end

function Background:draw()
	self.bgRect:draw()
end