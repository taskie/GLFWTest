subclass ("Background", Actor) {}

local function shapesUpdate(self)
   self.frame = self.frame + 1
   Motion.uniform(self)
   if self.y > Mys.screen.hy + 150 then
      self.isExisting = false
   end
   return self.isExisting
end

function Background:new(x, y, rot, model, param)
   Background.super.new(self, x, y, rot)
   
   self.bgRect = Rct.Rect(Mys.screen.w, Mys.screen.h, "polygon", Col.background, 0, 0)
   
   self.lines = Set()
   self.lines:push(Rct.Path({{200, 200, -100}, {200, 200, 100}}, "lines", {1.0, 1.0, 0}))
   self.lines:push(Rct.Path({{400, 400, -100}, {400, 400, 100}}, "lines", {1.0, 1.0, 0}))
   
   self.shapes = Set()
   for i = 1, 20 do
      local color = {Mys.mt:next(0.7, 1.0), Mys.mt:next(0.6, 0.9), Mys.mt:next(0.6, 0.9), 0.15}
      local actor = Actor(Mys.mt:next(0, Mys.screen.wx), Mys.mt:next(-150, Mys.screen.hy), 0,
			  Rct.Rect(Mys.mt:next(200, 300), Mys.mt:next(50, 150), "polygon", color))
      actor.v = Mys.mt:next(0.1, 0.4)
      actor.rot = 90
      actor.update = shapesUpdate
      self.shapes:push(actor)
   end
   
   self.accelMode = false
   self.accelFrame = 0
   self.accelFrameMax = 60
end

function Background:accel(frame)
   self.accelMode = 0
   self.accelFrame = 0
   self.accelFrameMax = frame or 60
end

function Background:update()
   if Mys.mt:next() < (self.accelMode and 0.03 or 0.01) then
      local color = {Mys.mt:next(0.7, 1.0), Mys.mt:next(0.6, 0.9), Mys.mt:next(0.6, 0.9), 0.15}
      local actor = Actor(Mys.mt:next(0, Mys.screen.wx), -150, 0,
			  Rct.Rect(Mys.mt:next(200, 300), Mys.mt:next(50, 150), "polygon", color))
      actor.v = (self.accelMode and Mys.mt:next(0.3, 0.5) or Mys.mt:next(0.1, 0.4))
      actor.rot = 90
      actor.update = shapesUpdate
      self.shapes:push(actor)
   end
   if self.accelMode then
      for k, shape in self.shapes:pairs() do
	 local rate = 1 + 0.015 * math.sin(math.pi * 5 / 4 * self.accelFrame / self.accelFrameMax)
	 shape.v = shape.v * rate
	 if shape.v < 0.1 then shape.v = 0.1 end
      end
      self.accelFrame = self.accelFrame + 1
      if self.accelFrame >= self.accelFrameMax then
	 self.accelMode = false
      end
   end
   self.shapes:removeIf(function(shape) return not shape:update() end)
   return Background.super.update(self)
end

function Background:draw()
   self.bgRect:draw()
   for k, line in self.lines:pairs() do
      line:draw()
   end
   for k, shape in self.shapes:pairs() do
      shape:draw()
   end
end

Bck = {}
Bck.default = Background()
