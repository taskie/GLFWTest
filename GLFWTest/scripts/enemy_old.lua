Game = {}

Enm = {}

Enm.Base = class(Character) {}

function Enm.Base:new(x, y, rot, size, hp, power, defence, exp)
  if x == nil then
    x = Mys.rand(Mys.field.x, Mys.field.wx)
  end
  if y == nil then
    y = -10
  end
  if rot == nil then
    rot = math.pi_half
  end

  Character.new(self, x, y, rot, size, hp, power, defence, exp)
  self.r = 10
  self.bucket = Game.enemyBulletsBucket
  
  -- self.name = ""
end

function Enm.Base:update()
  if self.existing then
    if self.x + self.size * 3 < 0 or self.x - self.size * 3 > Mys.screen.w
        or self.y + self.size * 3 < 0 or self.y - self.size * 3 > Mys.screen.h then
      self:death()
    end

    self:move()

    if self.x > Mys.field.x and self.x < Mys.field.wx
        and self.y > Mys.field.y and self.y < Mys.field.hy then
      self:attack()
    end
  else
    return false
  end

  self.frame = self.frame + 1
  return true
end

function Enm.Base:draw()
  if self.existing then
    self.shape:draw(self.x, self.y, self.rot)
  end
end

local function nearestEnemy(self)
  local target = self.nearestEnemy[2]
  if target ~= nil then
    return Mys.angle(self, target)
  else
    return - math.pi_half
  end
end

-- Zaco

Enm.Zaco = class(Enm.Base) {
  name = "Zaco",
  shape = Rct.Path({{0, 0}, {0, 20}, {13.3, 0}, {20, 10}, {13.3, 20}}, GL_LINE_LOOP, {0.3, 0.8, 1, 1}, 10, 10),
  bulletShape = Rct.Circle(5, GL_POLYGON, {0.3, 0.8, 1, 0.8}),
  move = Motion.uniform
}

function Enm.Zaco:new(x, y, rot)
  local size, hp, power, defence, exp = 10, 1, 1, 1, 1
  Enm.Base.new(self, x, y, rot, size, hp, power, defence, exp)
  self.v = 1
end

function Enm.Zaco:attack()
  if self.frame % 30 < 1 then
    local angle = Mys.angle(self, Game.player)
    local way = 1
    for i = 0, way - 1 do
      self:shoot(self.x, self.y, 3, angle + math.pi_two * i / way, 3)
    end
  end
end

function Enm.Zaco:fire()
  if self.frame % 30 < 1 then
    local angle = nearestEnemy(self)
    local way = (self.level - 1) * 3 + 1
    for i = 0, way - 1 do
      self:shoot(self.x, self.y, 3, angle + math.pi_two * i / way, 3)
    end
  end
end


-- Winder

Enm.Winder = class(Enm.Base) {
  name = "Winder",
  shape = Rct.Path({{0, 0}, {20, 0}, {10, 10}, {20, 20}, {0, 20}}, GL_LINE_LOOP, {1, 0, 0.3, 1}, 10, 10),
  bulletShape = Rct.Circle(5, GL_POLYGON, {1, 0, 0.3, 0.8}),
  move = Motion.uniform
}

function Enm.Winder:new(x, y, rot)
  if x == nil then
    x = Mys.rand(Mys.field.x, Mys.field.wx)
    y = -10
    rot = math.atan2(Game.player.y - y, Game.player.x - x)
  end
  local size, hp, power, defence, exp = 10, 7, 1, 3, 3
  Enm.Base.new(self, x, y, rot, size, hp, power, defence, exp)
  self.v = 1.5
end

function Enm.Winder:attack()
  local itv = 20 - self.level * 2
  local angle = 1 - 0.1 * self.level
  if angle < 0.2 then angle = 0.2 end
  if itv < 8 then itv = 8 end
  if self.frame % itv == 0 then
    self:shoot(self.x, self.y, 4, self.rot - angle, 3)
    self:shoot(self.x, self.y, 4, self.rot + angle, 3)
  end
end

function Enm.Winder:fire()
  Enm.Winder.attack(self)
end


-- Sniper

Enm.Sniper = class(Enm.Base) {
  name = "Sniper",
  shape = Rct.Path({{0, 10}, {10, 0}, {10, 5}, {20, 10}, {10, 15}, {10, 20}}, GL_LINE_LOOP, {0.9, 0.7, 0.7, 1}, 10, 10),
  bulletShape = Rct.Circle(5, GL_POLYGON, {0.9, 0.7, 0.7, 0.8}),
  move = Motion.uniform
}

function Enm.Sniper:new(x, y, rot)
  local size, hp, power, defence, exp = 10, 9, 2, 3, 5
  rot = rot or math.pi_half + Mys.rand(-0.2, 0.2)
  Enm.Base.new(self, x, y, rot, size, hp, power, defence, exp)
  self.v = 1
end

function Enm.Sniper:attack()
  local itv = 60 + math.floor(60 / self.level)
  if self.frame % itv < 1 then
    local num = 2 + self.level
    if num > 10 then num = 10 end
    for i = 0, num - 1 do
      self:shoot(self.x, self.y, 1.5 + 0.5 * i, self.rot, 3)
    end
  end
end

function Enm.Sniper:fire()
  Enm.Sniper.attack(self)
end


-- Quick

Enm.Quick = class(Enm.Base) {
  name = "Quick",
  shape = Rct.Path({{0, 0}, {20, 10}, {0, 20}, {10, 10}}, GL_LINE_LOOP, {0.9, 0.7, 0.3, 1}, 10, 10),
  bulletShape = Rct.Circle(5, GL_POLYGON, {0.9, 0.7, 0.3, 0.8}),
  move = Motion.uniform
}

function Enm.Quick:new(x, y, rot)
  if x == nil then
    x = MT:next() * Mys.screen.w
    y = -10
    rot = math.atan2(Game.player.y - y, Game.player.x - x)
  end
  local size, hp, power, defence, exp = 10, 7, 3, 3, 4
  Enm.Base.new(self, x, y, rot, size, hp, power, defence, exp)
  self.v = 5
  self.lastShot = 0
end

function Enm.Quick:attack()
  if self.frame - self.lastShot >= Mys.fps and Mys.collision(self, Game.player) then
    local way = 4 + self.level;
    local angle = Mys.angle(self, Game.player)
    for i = 0, way - 1 do
      self:shoot(self.x, self.y, 7, angle + math.pi_two * i / way, 3)
    end
    self.lastShot = self.frame
  end
end

function Enm.Quick:fire()
  if self.lastShot == nil then self.lastShot = 0 end
  local target = self.nearestEnemy[2]
  if target == nil then return end
  if self.frame - self.lastShot >= 5  and self.nearestEnemy[1] < 30 then
    local way = 4 + self.level;
    local angle = nearestEnemy(self)
    for i = 0, way - 1 do
      self:shoot(self.x, self.y, 7, angle + math.pi_two * i / way, 3)
    end
    self.lastShot = self.frame
  end
end


-- Scatter

Enm.Scatter = class(Enm.Base) {
  name = "Scatter",
  shape = Rct.Path({{0,0},{5,0},{10,10},{15,0},{20,0},{20,5},{10,10},{20,15},{20,20},{15,20},{10,10},{5,20},{0,20},{0,15},{10,10},{0,5}}, GL_LINE_LOOP, {0.5, 0.5, 1, 1}, 10, 10),
  bulletShape = Rct.Circle(5, GL_POLYGON, {0.5, 0.5, 1, 0.8}),
  move = Motion.uniform
}

function Enm.Scatter:new(x, y, rot)
  local size, hp, power, defence, exp = 10, 24, 6, 6, 8
  if x == nil then
    y = MT:next() * 240
    if MT:next() < 0.5 then
      x = -10
      rot = 0
    else
      x = Mys.screen.wx + 10
      rot = math.pi
    end
  end
  Enm.Base.new(self, x, y, rot, size, hp, power, defence, exp)
  self.v = 1
end

function Enm.Scatter:attack()
  if self.frame % 60 < 1 then
    local way = 7 + self.level
    for i = 0, way - 1 do
      self:shoot(self.x, self.y, Mys.rand(1.5, 4), MT:next() * math.pi_two, 3)
    end
  end
end

function Enm.Scatter:fire()
  Enm.Scatter.attack(self)
end


-- Spiral

Enm.Spiral = class(Enm.Base) {
  name = "Spiral",
  shape = Rct.Path({{10, 10},{0, 10},{0, 20},{20, 0},{20, 10},{10, 10},{10, 0},{0, 0},{20, 20},{10,20}}, GL_LINE_LOOP, {0.7, 0.8, 1, 1}, 10, 10),
  bulletShape = Rct.Circle(5, GL_POLYGON, {0.7, 0.8, 1, 0.8}),
  move = function(self)
    Motion.uniform(self)
    self.rot = self.rot + self.sign * 0.02 * math.cos(self.frame / 40)
  end
}

function Enm.Spiral:new(x, y, rot)
  local size, hp, power, defence, exp = 10, 30, 5, 9, 12
  Enm.Base.new(self, x, y, rot, size, hp, power, defence, exp)
  self.v = 1
  if MT:next() < 0.5 then
    self.sign = 1
  else
    self.sign = -1
  end
end

function Enm.Spiral:attack()
  if self.frame % 12 < 1 then
    local way = 3 + self.level
    for i = 0, way - 1 do
      self:shoot(self.x, self.y, 2.5, self.rot + i / way * math.pi_two, 3)
    end
  end
end

function Enm.Spiral:fire()
  if self.frame % 12 < 1 then
    local way = 3 + self.level
    for i = 0, way - 1 do
      self:shoot(self.x, self.y, 2.5, math.sin(self.frame / 40) + i / way * math.pi_two, 3)
    end
  end
end


-- Bee

Enm.Bee = class(Enm.Base) {
  name = "Bee",
  shape = Rct.Path({{0, 0}, {5, 0}, {5, 20}, {0, 20}, {0, 15}, {20, 15}, {20, 20}, {15, 20}, {15, 0}, {20, 0}, {20, 5}, {0, 5}}, GL_LINE_LOOP, {0.8, 0.8, 0.2, 1}, 10, 10),
  bulletShape = Rct.Circle(5, GL_POLYGON, {0.8, 0.8, 0.2, 0.8}),
  move = Motion.uniform
}

function Enm.Bee:new(x, y, rot)
  local size, hp, power, defence, exp = 10, 35, 2, 10, 16
  Enm.Base.new(self, x, y, rot, size, hp, power, defence, exp)
  self.v = 1
  self.k = 0
end

function Enm.Bee:attack()
  if self.frame % 60 < 1 then
    local way = 4 + self.level
    if way > 10 then way = 10 end
    local way2 = 5
    for i = 0, way - 1 do
      for j = 0, way - 1 do
        self:shoot(self.x, self.y, 3, self.rot + self.k + i / 20 + math.pi_two * j / way2, 3)
      end
    end
    self.k = self.k + 0.5
  end
end

function Enm.Bee:fire()
  Enm.Bee.attack(self)
end


-- Forest

Enm.Forest = class(Enm.Base) {
  name = "Forest",
  shape = Rct.Path({{0, 20}, {10, 20}, {20, 10}, {10, 0}, {0, 0}}, GL_LINE_LOOP, {0.2, 1, 0.8, 1}, 10, 10),
  bulletShape = Rct.Circle(5, GL_POLYGON, {0.2, 1, 0.8, 0.8}),
  move = Motion.uniform
}

function Enm.Forest:new(x, y, rot)
  local size, hp, power, defence, exp = 10, 50, 10, 10, 20
  Enm.Base.new(self, x, y, rot, size, hp, power, defence, exp)
  self.v = 0.5
end

function Enm.Forest:attack()
  local itv = 7 - self.level
  if itv < 2 then itv = 2 end
  if self.frame % itv < 1 then
    self:shoot(self.x, self.y, 4, self.frame, 3)
    self:shoot(self.x, self.y, 3, self.frame, 3)
  end
end

function Enm.Forest:fire()
  Enm.Forest.attack(self)
end


-- Bug

Enm.Bug = class(Enm.Base) {
  name = "Bug",
  shape = Rct.Path({{0, 0}, {5, 5}, {10, 0}, {15, 5}, {20, 0}, {18, 10}, {20, 20}, {15, 15}, {10, 20}, {5, 15}, {0, 20}, {2, 10}}, GL_LINE_LOOP, {0.8, 0.3, 0.8, 1}, 10, 10),
  bulletShape = Rct.Circle(5, GL_POLYGON, {0.8, 0.3, 0.8, 0.8}),
  move = Motion.uniform
}

function Enm.Bug:new(x, y, rot)
  local size, hp, power, defence, exp = 10, 60, 5, 15, 25
  local initflag = false
  if rot == nil then
    initflag = true
  end
  Enm.Base.new(self, x, y, rot, size, hp, power, defence, exp)
  if initflag then
    self.x = Mys.rand(Mys.screen.x, Mys.screen.wx)
    self.rot = Mys.angle(self, Game.player)
  end
  self.v = 1
end

function Enm.Bug:attack()
  local itv = 3 + math.floor(7 / self.level)
  if self.frame % itv < 1 then
    self:shoot(self.x, self.y, Mys.rand(0.3, 0.7), MT:next() * math.pi_two, 5)
  end
end

function Enm.Bug:fire()
  Enm.Bug.attack(self)
end


-- Sharp

Enm.Sharp = class(Enm.Base) {
  name = "Sharp",
  shape = Rct.Path({{0, 0}, {0, 20}, {5, 15}, {10, 15}, {10, 20}, {20, 10}, {10, 0}, {10, 5}, {5, 5}}, GL_LINE_LOOP, {0.2, 1, 0.4, 1}, 10, 10),
  bulletShape = Rct.Circle(5, GL_POLYGON, {0.2, 1, 0.4, 0.8}),
  move = Motion.uniform
}

function Enm.Sharp:new(x, y, rot)
  local size, hp, power, defence, exp = 10, 50, 5, 15, 30
  Enm.Base.new(self, x, y, rot, size, hp, power, defence, exp)
  self.v = 1
end

function Enm.Sharp:attack()
  if self.frame % 20 < 1 then
    local angle = Mys.angle(self, Game.player)
    self:shoot(self.x, self.y, 4 + self.level / 2, angle, 5)
    self:shoot(self.x, self.y, 2, angle, 5)
  end
end

function Enm.Sharp:fire()
  if self.frame % 20 < 1 then
    local angle = nearestEnemy(self)
    self:shoot(self.x, self.y, 4 + self.level / 2, angle, 5)
    self:shoot(self.x, self.y, 2, angle, 5)
  end
end


-- Fatal

Enm.Fatal = class(Enm.Base) {
  name = "Fatal",
  shape = Rct.Path({{0, 0}, {20, 15}, {20, 5}, {0, 20}}, GL_LINE_LOOP, {1, 0.8, 0.2, 1}, 10, 10),
  bulletShape = Rct.Circle(5, GL_POLYGON, {1, 0.8, 0.2, 0.8}),
  move = Motion.uniform
}

function Enm.Fatal:new(x, y, rot)
  local size, hp, power, defence, exp = 10, 80, 8, 20, 35
  if rot == nil then
    rot = Mys.angle(self, Game.player) + Mys.rand(-math.pi, math.pi) / 4
  end
  Enm.Base.new(self, x, y, rot, size, hp, power, defence, exp)
  self.v = 1
  if MT:next() < 0.5 then
    self.drot = 0.005
  else
    self.drot = -0.005
  end
end

function Enm.Fatal:attack()
  self.rot = self.rot + self.drot
  if self.frame % 20 < 1 then
    local way = 3 + self.level
    if way > 7 then way = 7 end
    for i = 0, 1 do
      for j = 1, way do
        self:shoot(self.x, self.y, j, self.rot + (i * 2 - 1) * math.pi_half, 3)
      end
    end
  end
end

function Enm.Fatal:fire()
  Enm.Fatal.attack(self)
end

-- Back

Enm.Back = class(Enm.Base) {
  name = "Back",
  shape = Rct.Path({{0, 0}, {0, 20}, {10, 10}, {10, 20}, {20, 20}, {10, 10}, {20, 0}, {10, 0}, {10, 10}}, GL_LINE_LOOP, {0.5, 0.5, 0.8, 1}, 10, 10),
  bulletShape = Rct.Circle(5, GL_POLYGON, {0.5, 0.5, 0.8, 0.8}),
  move = Motion.uniform
}

function Enm.Back:new(x, y, rot)
  local size, hp, power, defence, exp = 10, 100, 15, 30, 50
  if x == nil then
    if MT:next() < 0.5 then
      x = Mys.screen.x - 10
    else
      x = Mys.screen.wx + 10
    end
    y = Mys.screen.hy + 10
    local tx, ty
    tx = Mys.rand(Mys.field.x, Mys.field.wx)
    ty = Mys.rand(50, 300)
    rot = math.atan2(ty - y, tx - x)
  end
  Enm.Base.new(self, x, y, rot, size, hp, power, defence, exp)
  self.v = 1
  self.k = 0
end

function Enm.Back:attack()
  if self.frame % 10 < 1 then
    self.k = self.k + 0.2
    local way = 3
    for i = 0, way - 1 do
      self:shoot(self.x, self.y, 1, self.rot + i / way * math.pi_two + self.k, 3)
    end
  end
end

function Enm.Back:fire()
  Enm.Back.attack(self)
end


-- Reflect

Enm.Reflect = class(Enm.Base) {
  name = "Reflect",
  shape = Rct.Path({{10, 0}, {0, 10}, {10, 20}, {20, 10}}, GL_LINE_LOOP, {0.9, 0.2, 0, 1}, 10, 10),
  bulletShape = Rct.Circle(5, GL_POLYGON, {0.9, 0.2, 0, 0.8}),
  move = function(self)
    Motion.uniform(self)
    if self.frame >= Mys.fps * 20 then
      return
    end
    local dx = self.v * math.cos(self.rot)
    local dy = self.v * math.sin(self.rot)
    if (dx < 0 and self.x < Mys.field.x) or (dx > 0 and self.x > Mys.field.wx) then
      dx = -dx
    end
    if (dy < 0 and self.y < Mys.field.y) or (dy > 0 and self.y > Mys.field.hy) then
      dy = -dy
    end
    self.rot = math.atan2(dy, dx)
  end
}

function Enm.Reflect:new(x, y, rot)
  local size, hp, power, defence, exp = 10, 200, 12, 30, 100
  local initflag = false
  if rot == nil then initflag = true end
  Enm.Base.new(self, x, y, rot, size, hp, power, defence, exp)
  if initflag then
    self.rot = Mys.angle(self, Game.player)
  end
  self.v = 2.5
end

function Enm.Reflect:attack()
  if self.frame % 60 < 1 then
    local way = 7 + self.level
    for i = 0, way - 1 do
      self:shoot(self.x, self.y, 2, self.rot + i / way * math.pi_two, 3)
    end
  end
end

function Enm.Reflect:fire()
  Enm.Reflect.attack(self)
end
