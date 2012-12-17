-- field.lua
-- GameModel

--- \brief 円形当たり判定を行うアクターを格納する。
class ("Field") { }

function Field:new(x, y, w, h, cellSize)
	self.x, self.y = x or Mys.field.x, y or Mys.field.y
	w, h = w or Mys.field.w, h or Mys.field.h
	self.cellSize = cellSize or 10
	
	-- all actors
	self.actors = Set()
	
	-- bucket
	self.bucketW = math.ceil(w / self.cellSize)
	self.bucketH = math.ceil(h / self.cellSize)
	self.bucket = {}
	for i = 1, self.bucketH do
		self.bucket[i] = {}
		for j = 1, self.bucketW do
			self.bucket[i][j] = {}
		end
	end
end

--- \brief アクターの追加を行う。
--- actor = アクター（update, x, y の他に r を持つ）
--- \return アクターのID
function Field:add(actor)
	assert(actor.r)
	return self.actors:push(actor)
end

--- \brief 登録されているアクターをIDから得る。
--- id = アクターのID
--- \return アクター
function Field:get(id)
	return self.actors:get(id)
end

--- \brief 登録されたアクターを削除する。
--- id = アクターのID
function Field:remove(id)
	self.actors:remove(id)
end

--- \brief アクターのpairsを得る。
--- \return pairs
function Field:pairs()
	return self.actors:pairs()
end

--- \brief アクターのアップデートを行う。
--- \return Fieldオブジェクトが有効かどうか（常にtrue）
function Field:update()
	self:resetBucket()
	self:updateAllActors()
	
	for id, actor in self.actors:pairs() do
		local x, y, r = actor.x, actor.y, actor.r
		local xbeg, xend, ybeg, yend = self:coveringRect(x, y, r)
		if xbeg then
			for i = ybeg, yend do
				for j = xbeg, xend do
					table.insert(self.bucket[i][j], id)
				end
			end
		end
	end
	
	return true
end

--- \brief アクターの表示を行う。
function Field:draw()
	self.actors:forEach(function (id, actor) actor:draw() end)
end

--- \brief アクターと衝突しているオブジェクトのテーブルを得る。
--- actor = アクター（x, y の他に r を持つ）
--- \return キーをアクターのID、値をオブジェクトとするテーブル
function Field:collision(actor)
	assert(actor.r)
	local x, y, r = actor.x, actor.y, actor.r
	local xbeg, xend, ybeg, yend = self:coveringRect(x, y, r)
	if not xbeg then return {} end
			
	local idset = {}
	local checked = {}
	for i = ybeg, yend do
		for j = xbeg, xend do
			for index, id in ipairs(self.bucket[i][j]) do
				if not checked[id] then
					local other = self.actors:get(id)
					if (not other.shooter or other.shooter ~= actor)
					and Mys.collision(actor, other) then
						idset[id] = other
					end
					checked[id] = true
				end
			end
		end
	end
	
	return idset
end

--- \brief フィールド間での衝突判定を行う。
--- field = 衝突相手のフィールド
--- \return キーをアクターのID、値を「相手フィールドでのcollisionの結果」とするテーブル
function Field:collisionForField(field)
	local idCollisionTable = {}
	
	for id, actor in self.actors:pairs() do
		local idset = field:collision(actor)
		idCollisionTable[id] = {actor = actor, others = idset}
	end
	
	return idCollisionTable
end

-- private

function Field:coveringRect(x, y, r)
	local xbeg = Mys.clamp(math.ceil((x - self.x - r) / self.cellSize), 1, self.bucketW + 1)
	if xbeg == self.bucketW + 1 then return nil end
	local xend = Mys.clamp(math.ceil((x - self.x + r) / self.cellSize), 0, self.bucketW)
	if xend == 0 then return nil end
	local ybeg = Mys.clamp(math.ceil((y - self.y - r) / self.cellSize), 1, self.bucketH + 1)
	if ybeg == self.bucketH + 1 then return nil end
	local yend = Mys.clamp(math.ceil((y - self.y + r) / self.cellSize), 0, self.bucketH)
	if yend == 0 then return nil end

	return xbeg, xend, ybeg, yend
end

function Field:resetBucket()
	for i = 1, self.bucketH do
		for j = 1, self.bucketW do
			self.bucket[i][j] = {}
		end
	end
end

function Field:updateAllActors()
	self.actors:removeIf(
		function(actor) return not actor:update() end
	)
end
