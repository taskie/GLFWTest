class ("Stage") { }

function Stage:new()
end

function Stage:createEnemy(model, enemytype, exp)
	exp = exp or 0
	if model.random:next() < 0.001 then
		local enemy = enemytype(model)
		model.enemies:add(enemy)
		enemy:takeExp(exp)
	end
end

local exp = 0

function Stage:next(model)
	self:createEnemy(model, Enm.Zaco, exp)
	self:createEnemy(model, Enm.Winder, exp)
	self:createEnemy(model, Enm.Sniper, exp)
	self:createEnemy(model, Enm.Scatter, exp)
	self:createEnemy(model, Enm.Spiral, exp)
	self:createEnemy(model, Enm.Bee, exp)
	self:createEnemy(model, Enm.Base, exp)
	self:createEnemy(model, Enm.Block, exp)
end

function Stage:createPlayer(model)
	return Player(Mys.field.cx, Mys.field.cy + 100, -90, model, Input())
end

