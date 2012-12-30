math.pi_half = math.pi / 2
math.pi_two = math.pi * 2

Col = {}

Col.black = Rct.color({0, 0, 0, 1})
Col.red = Rct.color({1, 0, 0, 1})
Col.green = Rct.color({0, 1, 0, 1})
Col.blue = Rct.color({0, 0, 1, 1})
Col.yellow = Rct.color({1, 1, 0, 1})
Col.cyan = Rct.color({0, 1, 1, 1})
Col.magenta = Rct.color({1, 0, 1, 1})
Col.white = Rct.color({1, 1, 1, 1})

Col.pink = Rct.color({1, 0.8, 0.8, 1})
Col.lime = Rct.color({0.8, 1, 0.8, 1})
Col.aqua = Rct.color({0.8, 0.8, 1, 1})
Col.lemon = Rct.color({1, 1, 0.8, 1})
Col.orange = Rct.color({1, 0.8, 0, 1})

Mys = {}

-- ÉäÉvÉåÉCå›ä∑ê´
Mys.version = "0.1.0"

Mys.fps = 60

Mys.mt = random.MersenneTwister()

Mys.screen = {}

Mys.screen.w = 640
Mys.screen.h = 480
Mys.screen.x = 0
Mys.screen.y = 0
Mys.screen.wx = Mys.screen.x + Mys.screen.w
Mys.screen.hy = Mys.screen.y + Mys.screen.h
Mys.screen.cx = Mys.screen.x + Mys.screen.w / 2
Mys.screen.cy = Mys.screen.y + Mys.screen.h / 2

Mys.field = {}

Mys.field.w = 320
Mys.field.h = 480
Mys.field.x = (Mys.screen.w - Mys.field.w) / 2
Mys.field.y = (Mys.screen.h - Mys.field.h) / 2
Mys.field.wx = Mys.field.x + Mys.field.w
Mys.field.hy = Mys.field.y + Mys.field.h
Mys.field.cx = Mys.field.x + Mys.field.w / 2
Mys.field.cy = Mys.field.y + Mys.field.h / 2

Mys.levelUpRatio = 1.01

function Mys.msToString(x)
	local strs = {}

	x = math.floor(x / 10)
	strs[3] = x % 100

	x = math.floor(x / 100)
	strs[2]= x % 60

	strs[1] = math.floor(x / 60)

	for i, str in ipairs(strs) do
		if str < 10 then
			strs[i] = "0" .. str
		end
	end

	return strs[1] .. ":" .. strs[2] .. ":" .. strs[3]
end

function Mys.clamp(x, a, b)
	return math.min(math.max(x, a), b)
end

function Mys.distance(a, b)
	return math.sqrt(math.pow(a.x - b.x, 2) + math.pow(a.y - b.y, 2))
end

function Mys.collision(a, b)
	return math.pow(a.x - b.x, 2) + math.pow(a.y - b.y, 2) <= math.pow(a.r + b.r, 2)
end

function Mys.angle(a, b)
	return math.deg(math.atan2(b.y - a.y, b.x - a.x))
end

function Mys.inRect(obj, x, y, wx, hy)
	return obj.x + obj.r >= x and obj.x - obj.r <= wx
			and obj.y + obj.r >= y and obj.y - obj.r <= hy
end

function Mys.binarySearch(array, val)
	local i, j = 1, #array + 1
	local pos

	while j - i >= 1 do
		pos = math.floor((i + j) / 2)
		if array[pos] < val then
			i = pos + 1
		elseif array[pos] > val then
			j = pos
		else
			j = pos
		end
	end

	return i
end

function Mys.choiceWithWeight(array, mt)
	local rnd = mt:next() * array[#array]
	return Mys.binarySearch(array, rnd)
end

function Mys.tableToWeightArray(t)
	local a = {}
	for i, x in ipairs(t) do
		if i ~= 1 then
			a[i] = a[i-1] + x[2]
		else
			a[i] = x[2]
		end
	end
	return a
end

function Mys.nextId(t, mt)
	local rnd
	repeat
		rnd = mt:nextInt()
	until t[rnd] == nil
	return rnd
end

Mys.nilShape = Rct.Shape()

function Mys.doNothing() end

function Mys.split(str, delim)
		if string.find(str, delim) == nil then
				return {str}
		end

		local result = {}
		local pat = "(.-)" .. delim .. "()"
		local lastPos
		for part, pos in string.gfind(str, pat) do
				table.insert(result, part)
				lastPos = pos
		end
		table.insert(result, string.sub(str, lastPos))
		
		return result
end

function Mys.readHiscore(fileName)
	local hiscoreArray = {}
	local file = io.open (fileName)
	for line in file:lines(fileName) do
		local scoreTable = Mys.split(line, ",")
		scoreTable[1] = tonumber(scoreTable[1])
		table.insert(hiscoreArray, scoreTable)
	end
	file:close()
	return hiscoreArray
end

function Mys.writeHiscore(fileName, hiscoreArray)
	file = io.open(fileName, "w+")
	for i, hiscore in ipairs(hiscoreArray) do
		local str = string.format("%d,%s,%s,%s,%s,%s\n", hiscore[1], hiscore[2], hiscore[3], hiscore[4], hiscore[5], hiscore[6])
		file:write(str)
	end
	file:close()
end

function Mys.insertHiscore(score, model)
	for k, player in model.players:pairs() do
	end

	local hiscoreTable = Mys.readHiscore("score.log")
	
	local player = Game.player
	local weapons = Game.player.weapons
	
	local weaponsName = {}
	for i = 1, player.weaponsChoiceMax do
		if weapons[i] ~= nil then
			weaponsName[i] = weapons[i].name
		else
			weaponsName[i] = ""
		end
	end
	
	local score = player.exp
	if isClear then score = score * 2 end
	
	table.insert(hiscoreTable, {score, weaponsName[1], weaponsName[2], weaponsName[3], weaponsName[4], os.date()})
	
	for i, ts in ipairs(hiscoreTable) do
		print(unpack(ts))
	end
	
	table.sort(hiscoreTable, function(x, y)
		return x[1] > y[1]
	end)
	hiscoreTable[11] = nil
	
	Mys.writeHiscore("score.log", hiscoreTable)
end

local ConstMT = {}

function ConstMT.__index(table, index)
	print("const! (index)", index)
end

function ConstMT.__newindex(table, index, value)
	print("const! (newindex)", index, value)
end

setmetatable(Mys, ConstMT)
setmetatable(Col, ConstMT)
