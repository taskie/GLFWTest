subclass ("Background", Actor) {}

function Background:new(x, y, rot, model, param)
	Background.super.new(self, x, y, rot)
	
	self.bgRect = Rct.Rect(Mys.screen.w, Mys.screen.h, "polygon", {0.95, 0.95, 0.95}, 0, 0)
	
	self.lines = Set()
	self.lines:push(Rct.Path({{200, 200, -100}, {200, 200, 100}}, "lines", {1.0, 1.0, 0}))
	self.lines:push(Rct.Path({{400, 400, -100}, {400, 400, 100}}, "lines", {1.0, 1.0, 0}))
end

function Background:update()
	return Background.super.update(self)
end

function Background:draw()
	self.bgRect:draw()
	for k, line in self.lines:pairs() do
		line:draw()
	end
end