dofile("scripts/load.lua")

scene = Scn.Game()
-- scene = scene or Scn.Title()

function update()
	if scene.nextScene then
		scene = scene.nextScene
	end
	return scene:update()
end

function draw()
	scene:draw()
end
