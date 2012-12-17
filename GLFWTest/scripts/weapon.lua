subclass ("Weapon", Character) {}

function Weapon:new(enemy, player)
	for k, v in pairs(enemy) do
		self[k] = v
	end
	self.rot = player.rot
	
	self.shape = enemy.shape
	local color = {unpack(enemy.color)}
	self.bulletShape = Rct.Regular(3, 7, "lineLoop", {color[1], color[2], color[3], 0.3})
	self.move = enemy.move
	self.fire = enemy.fire
	self.name = enemy.classname
	self.owner = player
	self.bulletsField = enemy.model.playersBullets
	self.enemiesField = enemy.model.enemies
end

function Weapon:update()
	self:move()
	self.x = self.owner.x
	self.y = self.owner.y
	self:fire()
	return Weapon.super.update(self)
end