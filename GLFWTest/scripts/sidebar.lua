subclass ("SideBar", Actor) {}

function SideBar:new(model)
	self.super:new()
	self.model = model
	self.barRect = Rct.Rect(Mys.field.x, Mys.screen.h, "polygon", {0.7, 0.7, 0.7, 0.5}, 0, 0)
	
	self.margin = 15
	local textColor = {0.2, 0.2, 0.2, 1}
	self.playersInfo = {}
	self.playersInfo.hp = Rct.Text("HP", "black", 12, textColor, "l")
	self.playersInfo.hpValue = Rct.Text("4 / 33", "thin", 32, textColor, "l")
	self.playersInfo.hpBarLength = Mys.field.x - 2 * self.margin
	self.playersInfo.hpBar = Rct.Rect(self.playersInfo.hpBarLength, 3, "polygon", textColor, 0, 0)
	self.playersInfo.level = Rct.Text("LEVEL", "black", 12, textColor, "r")
	self.playersInfo.levelValue = Rct.Text("18", "thin", 96, textColor, "r")
	
	self.weaponInfo = {}
	self.weaponInfo.weapons = Rct.Text("WEAPONS", "black", 12, textColor, "r")
	self.weaponInfo.choice = 1
	self.weaponInfo.choiceTriangle = Rct.Regular(3, 5, "lineLoop", textColor)
	self.weaponInfo.actors = {}
end

function SideBar:update()
	for id, player in self.model.players:pairs() do
		self.playersInfo.levelValue:renew(player.level)
		local hp = player.hp
		local hpmax = player.hpmax
		local hpRatio = player.hp / player.hpmax
		self.playersInfo.hpValue:renew(hp .. " / " .. hpmax)
		self.playersInfo.hpBar.shape:setScale(hpRatio, 1)
		
		self.weaponInfo.choice = player.weapon.choice
		for i, actor in ipairs(player.weapon.actors) do
			self.weaponInfo.actors[i] = actor
		end
	end
	
	return SideBar.super.update(self)
end

function SideBar:draw()
	self.barRect:draw()
	self.barRect:draw(Mys.field.wx)
	
	local margin = self.margin
	self.playersInfo.hp:draw(Mys.field.wx + margin, Mys.screen.h - margin - 47)
	self.playersInfo.hpValue:draw(Mys.field.wx + margin, Mys.screen.h - margin - 10)
	self.playersInfo.hpBar:draw(Mys.field.wx + margin, Mys.screen.h - margin)
	self.playersInfo.level:draw(Mys.field.x - margin, Mys.screen.h - margin - 88)
	self.playersInfo.levelValue:draw(Mys.field.x - margin + 5, Mys.screen.h - margin)
	
	self.weaponInfo.weapons:draw(Mys.screen.wx - margin, Mys.screen.y + margin + 8)
	self.weaponInfo.choiceTriangle:draw(Mys.field.wx + margin, Mys.screen.y + margin + 8 + self.weaponInfo.choice * 30)
	for i, actor in pairs(self.weaponInfo.actors) do
		actor.shape:draw(Mys.field.wx + margin + 30, Mys.screen.y + margin + 8 + i * 30)
	end
end