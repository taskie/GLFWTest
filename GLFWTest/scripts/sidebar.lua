subclass ("SideBar", Actor) {}

function SideBar:new(model)
	self.super:new()
	self.model = model
	self.barRect = Rct.Rect(Mys.field.x, Mys.screen.h, "polygon", {0.8, 0.8, 0.8, 0.5}, 0, 0)
	
	self.margin = 20
	local textColor = {0.2, 0.2, 0.2, 1}
	self.playersInfo = {}
	self.playersInfo.hp = Rct.Text("HP", "black", 12, textColor, "l")
	self.playersInfo.hpValue = Rct.Text("4 / 33", "thin", 28, textColor, "l")
	self.playersInfo.hpBarLength = Mys.field.x - 2 * self.margin
	self.playersInfo.hpBar = Rct.Rect(self.playersInfo.hpBarLength, 3, "polygon", textColor, 0, 0)
	self.playersInfo.level = Rct.Text("LEVEL", "black", 12, textColor, "r")
	self.playersInfo.levelValue = Rct.Text(9800, "thin", 96, textColor, "r")
	self.playersInfo.exp = Rct.Text("EXP", "regular", 12, textColor, "r")
	self.playersInfo.expValue = Rct.Text("0", "thin", 28, textColor, "r")
	local barLength = Mys.field.x - 2 * self.margin
	self.playersInfo.expBar = Rct.Rect(barLength, 3, "polygon", textColor, barLength, 0)
	
	self.weaponInfo = {}
	self.weaponInfo.weapons = Rct.Text("WEAPONS", "black", 12, textColor, "r")
	self.weaponInfo.choice = 1
	self.weaponInfo.choiceTriangle = Rct.Regular(3, 5, "lineLoop", textColor)
	self.weaponInfo.choiceMax = 1
	self.weaponInfo.endBar = Rct.Rect(barLength, 1, "polygon", textColor, barLength, 0)
	self.weaponInfo.actors = {}
	for id, player in self.model.players:pairs() do
		for i = 1, player.weapon.lengthMax do
			self.weaponInfo.actors[i] = {}
			self.weaponInfo.actors[i].shape = Mys.nilShape
			self.weaponInfo.actors[i].level = Rct.Text(" ", "regular", 12, textColor, "l")
			self.weaponInfo.actors[i].expBar = Rct.Rect(Mys.field.x - 50 - 2 * self.margin, 3, "polygon", textColor, 0, 0)
		end
	end
	
	self.stageInfo = {}
	self.stageInfo.stage = Rct.Text("STAGE", "black", 12, textColor, "l")
	self.stageInfo.stageValue = Rct.Text(0, "thin", 96, textColor, "l")
	self.stageInfo.time = Rct.Text("NEXT STAGE", "regular", 12, textColor, "l")
	self.stageInfo.timeValue = Rct.Text(0, "thin", 28, textColor, "l")
end

function SideBar:update()
	for id, player in self.model.players:pairs() do
		self.playersInfo.levelValue:renew(player.level)
		self.playersInfo.expValue:renew(player.exp)
		local hp = player.hp
		local hpmax = player.hpmax
		local hpRatio = player.hp / player.hpmax
		self.playersInfo.hpValue:renew(hp .. " / " .. hpmax)
		self.playersInfo.hpBar.shape:setScale(hpRatio, 1)
		local expBarBias = player.level ^ 3
		local expBarMax =player:calcRequiredExp() - expBarBias
		local expBarRatio = (player.exp - expBarBias) / expBarMax
		if player.level == player.levelMax then expBarRatio = 0 end
		self.playersInfo.expBar.shape:setScale(expBarRatio, 1)
		
		self.weaponInfo.choice = player.weapon.choice
		self.weaponInfo.choiceMax = player.weapon.lengthMax
		for i = 1, player.weapon.lengthMax do
			local actor = player.weapon.actors[i]
			if actor then
				self.weaponInfo.actors[i].shape = actor.shape
				self.weaponInfo.actors[i].level:renew("Lv. " .. actor.level)
				local expBarBias = actor.level ^ 3
				local expBarMax = actor:calcRequiredExp() - expBarBias
				local expBarRatio = (actor.exp - expBarBias) / expBarMax
				if actor.level == actor.levelMax then expBarRatio = 0 end
				self.weaponInfo.actors[i].expBar.shape:setScale(expBarRatio, 1)
			else
				self.weaponInfo.actors[i].shape = Mys.nilShape
				self.weaponInfo.actors[i].level:renew(" ")
				self.weaponInfo.actors[i].expBar.shape:setScale(0, 1)
			end
		end
	end
	
	self.stageInfo.stageValue:renew(self.model.stage.count)
	self.stageInfo.timeValue:renew(Mys.msToString((self.model.stage.stageFrameMax - self.model.stage.stageFrame) / Mys.fps * 1000))
	
	return SideBar.super.update(self)
end

function SideBar:draw()
	self.barRect:draw()
	self.barRect:draw(Mys.field.wx)
	
	local margin = self.margin
	self.playersInfo.hp:draw(Mys.field.wx + margin, Mys.screen.h - margin - 10 - 33)
	self.playersInfo.hpValue:draw(Mys.field.wx + margin, Mys.screen.h - margin - 10)
	self.playersInfo.hpBar:draw(Mys.field.wx + margin, Mys.screen.h - margin)
	self.playersInfo.exp:draw(Mys.field.x - margin + 1, Mys.screen.h - margin - 120 - 10 - 33)
	self.playersInfo.expValue:draw(Mys.field.x - margin + 2, Mys.screen.h - margin - 120 - 10)
	self.playersInfo.expBar:draw(Mys.field.x - margin, Mys.screen.h - margin - 120)
	self.playersInfo.level:draw(Mys.field.x - margin, Mys.screen.h - margin - 88)
	self.playersInfo.levelValue:draw(Mys.field.x - margin + 5, Mys.screen.h - margin)
	
	self.weaponInfo.weapons:draw(Mys.screen.wx - margin, Mys.screen.y + margin + 8)
	self.weaponInfo.choiceTriangle:draw(Mys.field.wx + margin - 5, Mys.screen.y + margin + 8 + self.weaponInfo.choice * 30)
	for i, actor in pairs(self.weaponInfo.actors) do
		actor.shape:draw(Mys.field.wx + margin + 20, Mys.screen.y + margin + 8 + i * 30)
		actor.level:draw(Mys.field.wx + margin + 40, Mys.screen.y + margin + 7 + i * 30)
		actor.expBar:draw(Mys.field.wx + margin + 40, Mys.screen.y + margin + 13 + i * 30)
	end
	self.weaponInfo.endBar:draw(Mys.screen.wx - margin, Mys.screen.y + margin + 8 - 8 + (self.weaponInfo.choiceMax + 1) * 30)
	
	self.stageInfo.stage:draw(Mys.screen.x + margin, Mys.screen.y + margin + 8)
	self.stageInfo.stageValue:draw(Mys.screen.x + margin, Mys.screen.y + margin + 8 + 88)
	self.stageInfo.time:draw(Mys.screen.x + margin, Mys.screen.y + margin + 128)
	self.stageInfo.timeValue:draw(Mys.screen.x + margin, Mys.screen.y + margin + 128 + 33)
end