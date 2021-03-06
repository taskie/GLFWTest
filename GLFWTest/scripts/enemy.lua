Enm = {}

-- Zaco

subclass ("Zaco", Enemy, Enm)
{
   vertices = {{0, 0}, {0, 20}, {13.3, 0}, {20, 10}, {13.3, 20}},
   cx = 10, cy = 10,
   color = {0.3, 0.4, 0.9, 1.0},
   param = {r = 10, hp = 1, power = 1, defence = 1,  exp = 1}
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
   local interval = 30 - self.level
   if interval < 5 then interval = 5 end
   
   if self.frame % interval == 0 then
      local angle = self.rot
      local way = (self.level >= 10) and 2 or 1
      local v = self.level / 3 + 4
      if v > 7 then v = 7 end
      for i = 0, way - 1 do
	 self:shoot(self.x, self.y, angle + 360 * i / way, v, 3, 1)
      end
   end
end

-- Test

subclass ("Test", Enemy, Enm)
{
   vertices = {{0, 0}, {10, 0}, {10, 20}, {0, 20}, {20, 10}},
   cx = 10, cy = 10,
   color = {0.1, 0.2, 0.2, 1.0},
   param = {r = 10, hp = 1, power = 1, defence = 1,  exp = 1}
}
Enemy.setEnemy(Enm.Test)
Enm.Test.move = Motion.uniaccel

function Enm.Test:new(model, x, y, rot)
   local dir = model.random:next() < 0.5
   x = x or (dir and Mys.screen.x + 10 or Mys.screen.wx - 10)
   y = y or -10
   rot = rot or ((dir and 20 or 160) + model.random:next(-10, 10))
   Enemy.new(self, x, y, rot, model, self.param)
   self.v = 1
   self.a = 0.02
   self.drot = dir and 1 or -1
end

function Enm.Test:fire()
   local interval = 15 - self.level
   if interval < 7 then interval = 7 end
   self.rot = self.rot + self.drot

   if self.frame % interval == 0 then
      local angle = self.rot
      self:shoot(self.x, self.y, angle, 3, 3, 1)
   end
end

-- Winder

subclass ("Winder", Enemy, Enm)
{
   vertices = {{0, 0}, {20, 0}, {10, 10}, {20, 20}, {0, 20}},
   cx = 10, cy = 10,
   color = {1, 0, 0.3, 1.0},
   param = {r = 10, hp = 3, power = 1, defence = 2,  exp = 1}
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
   local interval = 20 - math.floor(self.level / 2)
   if interval < 10 then interval = 10 end
   local angle = 45 - 2 * self.level
   if angle < 5 then angle = 5 end
   
   if self.frame % interval == 0 then
      self:shoot(self.x, self.y, self.rot + angle, 4, 3, 1)
      self:shoot(self.x, self.y, self.rot - angle, 4, 3, 1)
      if self.level >= 10 then
	 self:shoot(self.x, self.y, self.rot + angle * 4, 4, 3, 1)
	 self:shoot(self.x, self.y, self.rot - angle * 4, 4, 3, 1)
      end
   end
end

-- Quick

subclass ("Quick", Enemy, Enm)
{
   vertices = {{0, 0}, {20, 10}, {0, 20}, {10, 10}},
   cx = 10, cy = 10,
   color = {0.7, 0.5, 0.1, 1.0},
   param = {r = 10, hp = 3, power = 1, defence = 3,  exp = 1}
}
Enemy.setEnemy(Enm.Quick)
Enm.Quick.move = Motion.uniform

function Enm.Quick:new(model, x, y, rot)
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
   self.v = 3
end

function Enm.Quick:fire()
   local interval = 25 - math.floor(self.level / 2)
   if interval < 7 then interval = 7 end
   if self.frame % interval == 0 then
      local way = (self.level >= 10) and 7 or 3
      for i = 0, way - 1 do
	 self:shoot(self.x, self.y, self.rot + i * 360 / way, 1, 1)
      end
   end
end

-- Block

subclass ("Block", Enemy, Enm)
{
   vertices = {{0, 0}, {20, 0}, {20, 20}, {0, 20}},
   cx = 10, cy = 10,
   color = {0.3, 0.3, 0.3, 1.0},
   param = {r = 10, hp = 5, power = 1, defence = 4,  exp = 1}
}
Enemy.setEnemy(Enm.Block)
Enm.Block.move = Motion.uniform

function Enm.Block:new(model, x, y, rot)
   x = x or model.random:next(Mys.field.x + 50, Mys.field.wx - 50)
   y = y or -10
   rot = rot or 90 + model.random:next(-15, 15)
   
   Enemy.new(self, x, y, rot, model, self.param)
   self.v = 0.5
end

function Enm.Block:fire()
   local n = math.floor(self.level / 3)
   if n > 10 then n = 10 end
   if self.frame % 2 == 0 and self.frame % 60 < n then
      local way = self.level >= 10 and 8 or 4
      for i = 0, way - 1 do
	 local angle = 90
	 local nearest = self:nearestEnemy()
	 if nearest then
	    angle = Mys.angle(self, nearest)
	 end
	 self:shoot(self.x, self.y, i * 360 / way + angle, 2, 3, 1)
      end
   end
end

-- Scatter

subclass ("Scatter", Enemy, Enm)
{
   vertices = {{0,0},{5,0},{10,10},{15,0},{20,0},{20,5},{10,10},{20,15},{20,20},{15,20},{10,10},{5,20},{0,20},{0,15},{10,10},{0,5}},
   cx = 10, cy = 10,
   color = {0.4, 0.4, 0.7, 1.0},
   param = {r = 10, hp = 5, power = 2, defence = 5,  exp = 1}
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
   local interval = self.level >= 10 and 30 or 60
   if self.frame % interval < 1 then
      local way = 5 + self.level
      if way > 30 then way = 30 end
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
   param = {r = 10, hp = 7, power = 3, defence = 6,  exp = 1}
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
   local interval = 16 - math.floor(self.level / 2)
   if interval < 4 then interval = 4 end
   if self.frame % interval == 0 then
      local way = 4
      if self.level >= 10 then way = 8 end
      for i = 0, way - 1 do
	 self:shoot(self.x, self.y, self.rot + i / way * 360, 2.5, 1)
      end
   end
end

-- Bee

subclass ("Bee", Enemy, Enm)
{
   vertices = {{0, 0}, {5, 0}, {5, 20}, {0, 20}, {0, 15}, {20, 15}, {20, 20}, {15, 20}, {15, 0}, {20, 0}, {20, 5}, {0, 5}},
   cx = 10, cy = 10,
   color = {0.7, 0.7, 0.1, 1.0},
   param = {r = 10, hp = 7, power = 1, defence = 5,  exp = 1}
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
   if self.level >= 10 then interval = 45 end
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
   color = {0.1, 0.6, 0.4, 1.0},
   param = {r = 10, hp = 8, power = 3, defence = 10,  exp = 1}
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
      if self.level >= 10 then self:shoot(self.x, self.y, self.k, 5, 1) end
      local drot = 21.1843 - self.level
      if drot < 7.1 then drot = 7.1843 end
      self.k = self.k + drot * self.sign
   end
end

-- Sniper

subclass ("Sniper", Enemy, Enm)
{
   vertices = {{0, 10}, {10, 0}, {10, 5}, {20, 10}, {10, 15}, {10, 20}},
   cx = 10, cy = 10,
   color = {0.5, 0.3, 0.3, 1.0},
   param = {r = 10, hp = 3, power = 1, defence = 3,  exp = 1}
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
   if self.level >= 10 then interval = 30 end
   if self.frame % interval == 0 then
      local num = 2 + math.ceil(self.level / 3)
      if num > 10 then num = 10 end
      for i = 0, num - 1 do
	 self:shoot(self.x, self.y, self.rot, 1.5 + 0.5 * i, 3, 1)
      end
   end
end

-- Bug

subclass ("Bug", Enemy, Enm)
{
   vertices = {{0, 0}, {5, 5}, {10, 0}, {15, 5}, {20, 0}, {18, 10}, {20, 20}, {15, 15}, {10, 20}, {5, 15}, {0, 20}, {2, 10}},
   cx = 10, cy = 10,
   color = {0.7, 0.1, 0.7, 1.0},
   param = {r = 10, hp = 10, power = 10, defence = 30,  exp = 1}
}
Enemy.setEnemy(Enm.Bug)
Enm.Bug.move = Motion.uniform

function Enm.Bug:new(model, x, y, rot)
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
   self.v = 0.5
end

function Enm.Bug:fire()
   local interval = 20 - self.level
   if interval < 8 then interval = 8 end
   if self.level >= 10 then interval = 4 end
   if self.frame % interval < 1 then
      self:shoot(self.x, self.y, self.model.random:next(0, 360), self.model.random:next(0.3, 0.7), 1)
   end
end

-- Sharp

subclass ("Sharp", Enemy, Enm)
{
   vertices = {{0, 0}, {0, 20}, {5, 15}, {10, 15}, {10, 20}, {20, 10}, {10, 0}, {10, 5}, {5, 5}},
   cx = 10, cy = 10,
   color = {0.2, 0.7, 0.4, 1.0},
   param = {r = 10, hp = 10, power = 15, defence = 50,  exp = 1}
}
Enemy.setEnemy(Enm.Sharp)
Enm.Sharp.move = Motion.uniform

function Enm.Sharp:new(model, x, y, rot)
   x = x or model.random:next(Mys.field.x, Mys.field.wx)
   y = y or -10
   rot = rot or 90
   Enemy.new(self, x, y, rot, model, self.param)
   self.v = 1
end

function Enm.Sharp:fire()
   local interval = 30 - math.floor(self.level / 2)
   if interval < 20 then interval = 20 end
   
   local nearest = self:nearestEnemy()
   local angle = self.rot
   if nearest then
      angle = Mys.angle(self, nearest)
   end
   
   if self.frame % interval < 1 then
      self:shoot(self.x, self.y, angle, 2, 1)
      if self.level >= 10 then
	 self:shoot(self.x, self.y, angle, 3, 1)
      end
      self:shoot(self.x, self.y, angle, 4, 1)
   end
end

-- Fatal

subclass ("Fatal", Enemy, Enm)
{
   vertices = {{0, 0}, {20, 15}, {20, 5}, {0, 20}},
   cx = 10, cy = 10,
   color = {0.8, 0.4, 0.2, 1.0},
   param = {r = 10, hp = 12, power = 20, defence = 30,  exp = 1}
}
Enemy.setEnemy(Enm.Fatal)

function Enm.Fatal:move()
   self.rot = self.rot + self.drot
   return Motion.uniform(self)
end

function Enm.Fatal:new(model, x, y, rot)
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
   if model.random:next() < 0.5 then
      self.drot = 0.1
   else
      self.drot = -0.1
   end
   self.k = 0
end

function Enm.Fatal:fire()
   local interval = (self.level >= 10) and 7 or 14
   local way = self.level + 2
   if self.frame % interval < 1 then
      if self.k < way then
	 for i = 0, 4 do
	    self:shoot(self.x, self.y, self.rot + i * (360 / 5), 1 + self.k / 2, 1)
	 end
      end
      self.k = (self.k + 1) % (way * 2)
   end
end

-- Back

subclass ("Back", Enemy, Enm)
{
   vertices = {{0, 0}, {0, 20}, {10, 10}, {10, 20}, {20, 20}, {10, 10}, {20, 0}, {10, 0}, {10, 10}},
   cx = 10, cy = 10,
   color = {0.5, 0.5, 0.8, 1.0},
   param = {r = 10, hp = 15, power = 30, defence = 70,  exp = 1}
}
Enemy.setEnemy(Enm.Back)
Enm.Back.move = Motion.uniform

function Enm.Back:new(model, x, y, rot)
   local default = not x
   x = x or model.random:next(Mys.field.x, Mys.field.wx)
   y = y or -10
   rot = rot or 90
   if default then
      if model.random:next() < 0.5 then
	 x = Mys.screen.x - 10
      else
	 x = Mys.screen.wx + 10
      end
      y = Mys.screen.hy + 10
      local tx, ty
      tx = model.random:next(Mys.field.x, Mys.field.wx)
      ty = model.random:next(50, 300)
      rot = math.deg(math.atan2(ty - y, tx - x))
   end
   Enemy.new(self, x, y, rot, model, self.param)
   self.v = 0.8
   self.k = 0
end

function Enm.Back:fire()
   self.k = self.k + 1
   local interval = 20 - math.floor(self.level / 2)
   if interval < 10 then interval = 10 end
   if self.frame % interval < 1 then
      local way = (self.level >= 10) and 5 or 3
      for i = 0, way - 1 do
	 self:shoot(self.x, self.y, self.rot + i / way * 360 + self.k, 1, 1)
      end
   end
end

-- Reflect

subclass ("Reflect", Enemy, Enm)
{
   vertices = {{10, 0}, {0, 10}, {10, 20}, {20, 10}},
   cx = 10, cy = 10,
   color = {0.9, 0.1, 0.3, 1.0},
   param = {r = 10, hp = 20, power = 20, defence = 80,  exp = 1}
}
Enemy.setEnemy(Enm.Reflect)
Enm.Reflect.move = Motion.uniform

function Enm.Reflect:move()
   Motion.uniform(self)
   if self.frame >= Mys.fps * 20 then
      return
   end
   local dx = self.v * math.cos(math.rad(self.rot))
   local dy = self.v * math.sin(math.rad(self.rot))
   if (dx < 0 and self.x < Mys.field.x) or (dx > 0 and self.x > Mys.field.wx) then
      dx = -dx
   end
   if (dy < 0 and self.y < Mys.field.y) or (dy > 0 and self.y > Mys.field.hy) then
      dy = -dy
   end
   self.rot = math.deg(math.atan2(dy, dx))
end

function Enm.Reflect:new(model, x, y, rot)
   local default = not x
   x = x or model.random:next(Mys.field.x, Mys.field.wx)
   y = y or -10
   rot = rot or 90 + model.random:next(-30, 30)
   Enemy.new(self, x, y, rot, model, self.param)
   self.v = 2
end

function Enm.Reflect:fire()
   local interval = 90 - self.level
   if interval < 60 then interval = 60 end
   if self.frame % interval < 1 then
      local way = (self.level >= 10) and 16 or 8
      for i = 0, way - 1 do
	 self:shoot(self.x, self.y, self.rot + i / way * 360, 3, 1)
      end
   end
end

-- Ring

subclass ("Ring", Enemy, Enm)
{
   vertices = {{0, 0}, {20, 0}, {0, 20}, {20, 20}},
   cx = 10, cy = 10,
   color = {1, 0, 1, 1.0},
   param = {r = 10, hp = 1000, power = 10, defence = 30,  exp = 10000}
}
Enemy.setEnemy(Enm.Ring)
Enm.Ring.move = Motion.uniform

function Enm.Ring:new(model, x, y, rot)
   local default = not x
   x = x or Mys.field.cx
   y = y or -10
   rot = rot or 90
   Enemy.new(self, x, y, rot, model, self.param)
   self.v = 0.1
   self.k = model.random:next(0, 360)
   self.k2 = model.random:next(0, 360)
   self.isBoss = true
end

function Enm.Ring:fire()
   local interval = 15
   if self.frame % interval < 1 then
      local way = 5
      for i = 0, way - 1 do
	 local phi = i / way * 360
	 local v = 3
	 local r = 0.3
	 local rot = self.rot + self.k
	 local v2 = math.sqrt(v * (v + 2 * r * math.cos(math.rad(phi))) + r * r)
	 local phi2 = math.deg(math.asin(r * math.sin(math.rad(phi)) / v2))
	 local rot2 = rot + phi2
	 self:shoot(self.x, self.y, rot2, v2, 1)
      end
      for i = 0, way - 1 do
	 local phi = i / way * 360
	 local v = 1
	 local r = 0.05
	 local rot = self.rot + self.k2
	 local v2 = math.sqrt(v * (v + 2 * r * math.cos(math.rad(phi))) + r * r)
	 local phi2 = math.deg(math.asin(r * math.sin(math.rad(phi)) / v2))
	 local rot2 = rot + phi2
	 self:shoot(self.x, self.y, rot2, v2, 1)
      end
   end
   self.k = self.k + 17
   self.k2 = self.k2 - 7
end

-- BlackRing

subclass ("BlackRing", Enemy, Enm)
{
   vertices = {{0, 0}, {20, 0}, {0, 20}, {20, 20}},
   cx = 10, cy = 10,
   color = {0, 0, 0.2, 1.0},
   param = {r = 10, hp = 2000, power = 10, defence = 100,  exp = 100000}
}
Enemy.setEnemy(Enm.BlackRing)
Enm.BlackRing.move = Motion.uniform

function Enm.BlackRing:new(model, x, y, rot)
   local default = not x
   x = x or Mys.field.cx
   y = y or -10
   rot = rot or 90
   Enemy.new(self, x, y, rot, model, self.param)
   self.v = 0.1
   self.k = model.random:next(0, 360)
   self.k2 = model.random:next(0, 360)
   self.isBoss = true
end

function Enm.BlackRing:fire()
   local interval = 15
   if self.frame % interval < 1 then
      local way = 13
      for i = 0, way - 1 do
	 local phi = i / way * 360
	 local v = 3
	 local r = 0.3
	 local rot = self.rot + self.k
	 local v2 = math.sqrt(v * (v + 2 * r * math.cos(math.rad(phi))) + r * r)
	 local phi2 = math.deg(math.asin(r * math.sin(math.rad(phi)) / v2))
	 local rot2 = rot + phi2
	 self:shoot(self.x, self.y, rot2, v2, 1)
      end
      for i = 0, way - 1 do
	 local phi = i / way * 360
	 local v = 1
	 local r = 0.05
	 local rot = self.rot + self.k2
	 local v2 = math.sqrt(v * (v + 2 * r * math.cos(math.rad(phi))) + r * r)
	 local phi2 = math.deg(math.asin(r * math.sin(math.rad(phi)) / v2))
	 local rot2 = rot + phi2
	 self:shoot(self.x, self.y, rot2, v2, 1)
      end
   end
   self.k = self.k + 17
   self.k2 = self.k2 - 7
end

-- BlackSide

subclass ("BlackSide", Enemy, Enm)
{
   vertices = {{0, 0}, {0, 20}, {10, 0}, {20, 0}, {20, 20}, {10, 20}},
   cx = 10, cy = 10,
   color = {0, 0, 0.2, 1.0},
   param = {r = 10, hp = 1000, power = 10, defence = 50,  exp = 10000}
}
Enemy.setEnemy(Enm.BlackSide)
Enm.BlackSide.move = Motion.uniform

function Enm.BlackSide:new(model, x, y, rot)
   local default = not x
   x = x or Mys.field.cx
   y = y or -10
   rot = rot or 90
   Enemy.new(self, x, y, rot, model, self.param)
   self.v = 0.1
   self.isBoss = true
end

function Enm.BlackSide:fire()
   local interval = 120
   if self.frame % interval < 1 then
      local way = 13
      for i = 0, way - 1 do
	 local phi = i / way * 360
	 local v = 3.5
	 local r = 0.1
	 local nearest = self:nearestEnemy()
	 local rot = nearest and Mys.angle(self, nearest) or 90
	 local v2 = math.sqrt(v * (v + 2 * r * math.cos(math.rad(phi))) + r * r)
	 local phi2 = math.deg(math.asin(r * math.sin(math.rad(phi)) / v2))
	 local rot2 = rot + phi2
	 self:shoot(self.x, self.y, rot2, v2, 1)
      end
      for i = 0, way - 1 do
	 local phi = i / way * 360
	 local v = 4
	 local r = 0.2
	 local nearest = self:nearestEnemy()
	 local rot = nearest and Mys.angle(self, nearest) or 90
	 local v2 = math.sqrt(v * (v + 2 * r * math.cos(math.rad(phi))) + r * r)
	 local phi2 = math.deg(math.asin(r * math.sin(math.rad(phi)) / v2))
	 local rot2 = rot + phi2
	 self:shoot(self.x, self.y, rot2, v2, 1)
      end
   end
end

-- Radio

subclass ("Radio", Enemy, Enm)
{
   vertices = {{0, 0}, {10, 10}, {0, 20}, {20, 15}, {15, 10}, {20, 5}},
   cx = 10, cy = 10,
   color = {0.9, 0.4, 0.5, 1.0},
   param = {r = 10, hp = 10, power = 5, defence = 15,  exp = 1}
}
Enemy.setEnemy(Enm.Radio)
Enm.Radio.move = Motion.uniform

function Enm.Radio:new(model, x, y, rot)
   x = x or model.random:next(Mys.field.x, Mys.field.wx)
   y = y or -10
   rot = rot or model.random:next(80, 100)
   Enemy.new(self, x, y, rot, model, self.param)
   self.v = 1
end

function Enm.Radio:fire()
   local interval = 30 - self.level
   if interval < 10 then interval = 10 end

   if self.frame % interval == 0 then
      local angle = self.rot
      local way = (self.level >= 10) and 5 or 3
      for i = 0, way - 1 do
	 local v = self.model.random:next(2, 4)
	 self:shoot(self.x, self.y, angle + self.model.random:next(-15, 15), v, 3, 1)
      end
   end
end


-- Breakaway

subclass ("Breakaway", Enemy, Enm)
{
   vertices = {{0, 0}, {10, 0}, {10, 20}, {0, 20}, {20, 10}},
   cx = 10, cy = 10,
   color = {0.1, 0.2, 0.2, 1.0},
   param = {r = 10, hp = 10, power = 5, defence = 5,  exp = 1}
}
Enemy.setEnemy(Enm.Breakaway)
Enm.Breakaway.move = Motion.uniaccel

function Enm.Breakaway:new(model, x, y, rot)
   local dir = model.random:next() < 0.5
   x = x or (dir and Mys.screen.x + 10 or Mys.screen.wx - 10)
   y = y or -10
   rot = rot or ((dir and 20 or 160) + model.random:next(-10, 10))
   Enemy.new(self, x, y, rot, model, self.param)
   self.v = 1
   self.a = 0.02
   self.drot = dir and 1 or -1
end

function Enm.Breakaway:fire()
   local interval = 15 - self.level
   if interval < 7 then interval = 7 end
   self.rot = self.rot + self.drot

   if self.frame % interval == 0 then
      local angle = self.rot
      self:shoot(self.x, self.y, angle, 3, 3, 1)
      if self.level >= 10 then
	 self:shoot(self.x, self.y, angle, 2, 3, 1)
      end
   end
end

-- Splash

subclass ("Splash", Enemy, Enm)
{
   vertices = {{0, 0}, {10, 10}, {0, 20}, {10, 20}, {10, 15}, {20, 10}, {10, 5}, {10, 0}},
   cx = 10, cy = 10,
   color = {0.2, 0.4, 0.9, 1.0},
   param = {r = 10, hp = 20, power = 10, defence = 1,  exp = 1}
}
Enemy.setEnemy(Enm.Splash)
Enm.Splash.move = Motion.uniaccel

function Enm.Splash:new(model, x, y, rot)
   local dir = model.random:next() < 0.5
   x = x or (dir and Mys.screen.x + 10 or Mys.screen.wx - 10)
   y = y or -10
   rot = rot or ((dir and 20 or 160) + model.random:next(-10, 10))
   Enemy.new(self, x, y, rot, model, self.param)
   self.v = 1
   self.a = 0.02
end

function Enm.Splash:fire()
   local interval = 30 - self.level
   if interval < 15 then interval = 15 end

   if self.frame % interval == 0 then
      local way = self.level >= 10 and 7 or 5
      for i = 1, way do
	 local angle = self.rot + 360 * (i + 0.5) / way
	 self:shoot(self.x, self.y, angle, 1, 3, 1)
	 self:shoot(self.x, self.y, angle, 2, 3, 1)
      end
   end
end

-- Conveyor

subclass ("Conveyor", Enemy, Enm)
{
   vertices = {{0, 0}, {0, 20}, {10, 20}, {10, 15}, {20, 10}, {10, 5}, {10, 0}},
   cx = 10, cy = 10,
   color = {0.5, 0.3, 0.5, 1.0},
   param = {r = 10, hp = 20, power = 1, defence = 20,  exp = 1}
}
Enemy.setEnemy(Enm.Conveyor)
function Enm.Conveyor:move()
   self.y = self.y + 1
end

function Enm.Conveyor:new(model, x, y, rot)
   local dir = model.random:next() < 0.5
   x = x or (dir and Mys.field.x + 10 or Mys.field.wx - 10)
   y = y or -10
   rot = rot or (dir and 0 or 180)
   Enemy.new(self, x, y, rot, model, self.param)
   self.v = 1
   self.drot = model.random:next() < 0.5 and 1 or -1
end

function Enm.Conveyor:fire()
   local interval = 30 - self.level
   if interval < 10 then interval = 10 end

   if self.frame % interval == 0 then
      local angle = self.rot
      self:shoot(self.x, self.y, angle, 2, 3, 1)
      if self.level >= 10 then
	 self:shoot(self.x, self.y, angle, 3, 3, 1)
      end
   end
end

-- Curtain

subclass ("Curtain", Enemy, Enm)
{
   vertices = {{0, 0}, {0, 20}, {20, 20}, {20, 15}, {15, 15}, {15, 5}, {20, 5}, {20, 0}},
   cx = 10, cy = 10,
   color = {0.1, 0.3, 0.3, 1.0},
   param = {r = 10, hp = 20, power = 1, defence = 10,  exp = 1}
}
Enemy.setEnemy(Enm.Curtain)
Enm.Curtain.move = Motion.uniform

function Enm.Curtain:new(model, x, y, rot)
   x = x or Mys.field.cx + model.random:next(-100, 100)
   y = y or -10
   rot = rot or model.random:next(80, 100)
   Enemy.new(self, x, y, rot, model, self.param)
   self.v = 1
   self.drot = model.random:next() < 0.5 and 1 or -1
end

function Enm.Curtain:fire()
   local interval = 30 - self.level
   if interval < 10 then interval = 10 end
   self.rot = self.rot + self.drot

   if self.frame % interval == 0 then
      local angle = self.rot
      local way = (self.level >= 10) and 5 or 3
      for i = -way, way do
	 local v = 2
	 self:shoot(self.x, self.y, angle + i * 5, v, 3, 1)
      end
   end
end
