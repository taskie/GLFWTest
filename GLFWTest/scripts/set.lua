-- class Set
-- \brief 集合。

class ("Set") { }

function Set:new()
	self.data = {}
	self.count = 1
end

function Set:nextId()
	local id = self.count
	self.count = self.count + 1
	return id
end

function Set:push(value)
	local id = self:nextId()
	self.data[id] = value
	return id
end

function Set:get(id)
	return self.data[id]
end

function Set:remove(id)
	self.data[id] = nil
end

function Set:forEach(func)
	for id, value in pairs(self.data) do
		func(id, value)
	end
end

function Set:pairs()
	return pairs(self.data)
end

function Set:copyIf(func)
	local newset = Set()
	newset.count = self.count
	for id, value in pairs(self.data) do
		if func(value) then
			newset.data[id] = value
		end
	end
	return newset
end

function Set:removeIf(func)
	for id, value in pairs(self.data) do
		if func(value) then
			self:remove(id)
		end
	end
end
