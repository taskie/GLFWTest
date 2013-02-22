io = nil
local os_date = os.date
os = {date = os_date}

dofile("scripts/load.lua")

scene = scene or Scn.Title()

function update()
	if scene.nextScene then
		scene = scene.nextScene
	end
	return scene:update()
end

function draw()
	scene:draw()
end
