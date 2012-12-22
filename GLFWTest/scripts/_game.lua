class ("Game") {}

function Game:new(isHell)
	if isHell == nil then isHell = false end
	Game.isHell = isHell
	Game.player = Player()
	Game.enemies = {}
	Game.particlesArray = {}
	Game.damages = {}
	Game.exps = {}
	Game.enemyBulletsBucket = BulletsBucket()
	Game.playerBulletsBucket = BulletsBucket()
	Game.stage = Stage(isHell)
	Game.sideBar = SideBar(isHell)
	Game.drawables = {}
	Game.drawables.stage = Drawable(Rct.Text("READY ...", "m+t36", Col.yellow, "c"), Mys.screen.cx, 80, 0, Mys.fps * 3)
	Game.frame = 0
	Game.damaged = false
	Game.damagedRect = Rct.Rect(Mys.screen.w, Mys.screen.h, nil, {1, 0, 0, 0.1}, 0, 0)
end

function Game.updateAll(objs)
	for k, obj in pairs(objs) do
		if not obj:update() then
			objs[k] = nil
		end
	end
end

function Game:update()
	Game.enemyBulletsBucket:update()
	Game.playerBulletsBucket:update()

	Game.player:update()

	Game.updateAll(Game.enemies)
	Game.updateAll(Game.particlesArray)
	Game.updateAll(Game.damages)
	Game.updateAll(Game.exps)
	Game.updateAll(Game.drawables)

	if SGM:isKeyDown(SDLK_a) then
		Game.stage:next()
	end
	Game.stage:update()

	Game.damaged = false
	do
		local bullets = Game.enemyBulletsBucket:get(Game.player.x, Game.player.y, Game.player.r)

		for id, bullet in pairs(bullets) do
			if Mys.collision(Game.player, bullet) then
				local pan = Game.player.x / Mys.screen.wx
				MXR:playSound("playerdamaged", pan)
				Game.damaged = true
				local damage = Game.player:damageByBullet(bullet)
				Game.damages[Mys.nextId(Game.damages)] = Damage(damage, Game.player.x, Game.player.y)
				Game.player:damaged(damage)
				Game.enemyBulletsBucket:remove(id)

				if not Game.player.existing then
					MXR:playSound("ng", pan)
					Game.player.hp = 0
					Main.scene = GameOver(Game)
					break
				end
			end
		end
	end

	do
		for k, enemy in pairs(Game.enemies) do
			local bullets = Game.playerBulletsBucket:get(enemy.x, enemy.y, enemy.r)

			for id, bullet in pairs(bullets) do
				if Mys.collision(enemy, bullet) then
					Game.playerBulletsBucket:remove(id)

					local damage = enemy:damageByBullet(bullet)
					enemy:damaged(damage)
					Game.damages[Mys.nextId(Game.damages)] = Damage(damage, enemy.x, enemy.y)
					local pan = enemy.x / Mys.screen.wx
					MXR:playSound("enemydamaged", pan)

					if not enemy.existing then
						MXR:playSound("enemydestroyed", pan)
						Game.particlesArray[Mys.nextId(Game.particlesArray)] = Particles(enemy)
						Game.exps[Mys.nextId(Game.exps)] = Experience(enemy.exp, enemy.x, enemy.y)
						bullet.from:takeExp(enemy.exp)
						break
					end
				end
			end
		end
	end

	Game.sideBar:update()
	Game.frame = Game.frame + 1
end

function Game.drawAll(objs)
	for k, obj in pairs(objs) do
		obj:draw()
	end
end

function Game:draw()
	Game.playerBulletsBucket:draw()
	Game.player:draw()

	Game.drawAll(Game.enemies)
	Game.drawAll(Game.particlesArray)
	Game.drawAll(Game.damages)
	Game.drawAll(Game.exps)
	Game.drawAll(Game.drawables)

	Game.enemyBulletsBucket:draw()
	Game.sideBar:draw()

	if Game.damaged then Game.damagedRect:draw() end
end
