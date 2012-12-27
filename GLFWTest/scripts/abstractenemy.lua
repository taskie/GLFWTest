subclass ("Enemy", Character) {}

function Enemy:new(x, y, rot, model, param)
	Enemy.super.new(self, x, y, rot, model, param)
	self.bulletsField = model.enemiesBullets
	self.enemiesField = model.players
	
	self.shape = Enm[self.classname].shape
	self.bulletShape = Enm[self.classname].bulletShape
	self.expBulletShape = Enm[self.classname].expBulletShape
end

function Enemy:update()
	if self.x + self.r * 5 < 0 or self.x - self.r * 5 > Mys.screen.w
	or self.y + self.r * 5 < 0 or self.y - self.r * 5 > Mys.screen.h then
		self:death()
	end
	
	self:move()
	
	if self.x > Mys.field.x and self.x < Mys.field.wx
	and self.y > Mys.field.y and self.y < Mys.field.hy then
		self:fire()
	end

	return Enemy.super.update(self)
end

function Enemy.createShape(classtable)
	classtable.shape = Rct.Path(classtable.vertices, "lineLoop", classtable.color, classtable.cx, classtable.cy)
end

function Enemy.createBulletShape(classtable, r)
	local color = classtable.color
	local expBulletShape = Rct.Circle(r, "lineLoop", {color[1], color[2], color[3], 0.3})
	local bulletShapePolygon = Rct.Circle(r, "polygon", {color[1], color[2], color[3], 0.8})

	local bulletShape = Rct.Sprite()
	bulletShape:pushChild(bulletShapePolygon)
	bulletShape:pushChild(expBulletShape)

	classtable.bulletShape = bulletShape
	classtable.expBulletShape = expBulletShape
end

function Enemy.createParticles(classtable)
	local lines = {}
	local color = classtable.color
	color = {color[1], color[2], color[3], 0.4}
	local old = false
	for i, vertex in ipairs(classtable.vertices) do
		if old then
			table.insert(lines, Rct.Path({old, vertex}, "lines", color, classtable.cx, classtable.cy))
		end
		old = vertex
	end
	table.insert(lines, Rct.Path({old, classtable.vertices[1]}, "lines", color, classtable.cx, classtable.cy))
	classtable.particles = lines
end

function Enemy.setEnemy(classtable)
	Enemy.createShape(classtable)
	Enemy.createBulletShape(classtable, 5)
	Enemy.createParticles(classtable)
end
