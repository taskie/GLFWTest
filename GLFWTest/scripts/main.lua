dofile("scripts/load.lua")

-- [[
local back = Rct.Rect(640, 480, "polygon", {1, 1, 1, 1}, 0, 0)
local sideback = Rct.Rect(160, 480, "polygon", {0.9, 0.1, 0.0, 0.5}, 0, 0)

local text = Rct.Text(0, "thin", 72, {0.0, 0.0, 0.0, 1}, "r")
local text2 = Rct.Text("2013", "thin", 48, {0.0, 0.0, 0.0, 1}, "r")

local bg = Rct.Circle(100, "polygon", {1, 0.9, 0, 0.1})
-- ]]

function update()
	Test.update()
end

function draw()
	Test.draw()
end
