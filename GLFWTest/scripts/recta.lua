Rct = {}

function Rct.color(colorArray)
	if type(colorArray) ~= "table" then
		return colorArray
	end
	return gl.Color(unpack(colorArray))
end

-- Rct.shapeEngine = gl.ShapeEngine()

-- Shape

class("Shape", Rct) {}

function Rct.Shape:new(shape)
	self.shape = shape
--	self.shapeId = Rct.shapeEngine:regist(shape)
end

function Rct.Shape:draw(x, y, rot)
	x = x or 0
	y = y or 0
	rot = rot or 0
	
	if self.shape then
		self.shape:setPosition(x, y):setRotate(rot):draw()
	end
end

-- Sprite

subclass("Sprite", Rct.Shape, Rct) {}

function Rct.Sprite:new()
	local shape = gl.ShapeContainer()
	Rct.Sprite.super.new(self, shape)
end

function Rct.Sprite:pushChild(obj)
	self.shape:pushChild(obj.shape)
end

-- Rect

subclass("Rect", Rct.Shape, Rct) {}

function Rct.Rect:new(w, h, mode, color, cx, cy)
	mode = mode or "point"
	color = color or {0, 0, 0, 0}

	self.w = w or 0
	self.h = h or 0
	self.cx = cx or (self.w / 2)
	self.cy = cy or (self.h / 2)

	local elem = gl.ShapeElement():color(Rct.color(color)):rectangle(0, 0, self.w, self.h)
	local shape = gl.ShapeContainer(elem):setAnchor(self.cx, self.cy)
	gl.ShapeContainer[mode](shape)
	Rct.Rect.super.new(self, shape)
end

-- Regular

subclass("Regular", Rct.Shape, Rct) {}

function Rct.Regular:new(n, r, mode, color)
	mode = mode or "point"
	color = color or {0, 0, 0, 0}
	
	self.n = n or 3
	self.r = r or 0
	
	local elem = gl.ShapeElement():color(Rct.color(color)):regularPolygon(self.n, self.r)
	local shape = gl.ShapeContainer(elem)
	gl.ShapeContainer[mode](shape)
	Rct.Regular.super.new(self, shape)
end

-- Circle

subclass("Circle", Rct.Regular, Rct) {}

function Rct.Circle:new(r, mode, color)
	local n = math.ceil(2 * math.pi / math.asin(1/(math.sqrt(r + 1))))
	Rct.Circle.super.new(self, n, r, mode, color)
end

-- Path

subclass("Path", Rct.Shape, Rct) {}

function Rct.Path:new(vertices, mode, color, cx, cy)
	mode = mode or "point"
	color = color or {0, 0, 0, 0}
	
	self.vertices = vertices
	self.cx, self.cy = cx or 0, cy or 0
	
	local elem = gl.ShapeElement():color(Rct.color(color))
	for i, vertex in ipairs(self.vertices) do
		elem:vertex(unpack(vertex))
	end
	local shape = gl.ShapeContainer(elem):setAnchor(self.cx, self.cy)
	gl.ShapeContainer[mode](shape)
	Rct.Path.super.new(self, shape)
end

-- Text

subclass("Text", Rct.Shape, Rct) {
	fontex = false
}

function Rct.Text:new(text, font, size, color, side)
	assert(Rct.Text.fontex)
	local stringShape = Rct.Text.fontex:utf8StringShape(text, font, size, Rct.color(color))
	
	self.w = stringShape:width()
	self.color = Rct.color(color)
	self.text = text
	self.font = font
	self.size = size
	self.side = side or "l"
	
	local shape = stringShape:get()
	if self.side == "c" then
		shape:setPosition(-self.w / 2, 0)
	elseif self.side == "r" then
		shape:setPosition(-self.w, 0)
	end
	local outer = gl.ShapeContainer()
	outer:pushChild(shape)
	
	Rct.Path.super.new(self, outer)
end

function Rct.Text:renew(text)
	if self.text ~= text then
		self:new(text, self.font, self.size, self.color, self.side)
	end
end

function Rct.Text:draw(x, y, rot)
	self.shape:setColorForce(self.color)
	
	x = x or 0
	y = y or 0
	rot = rot or 0
	
	if self.shape then
		self.shape:setPosition(x, y):setRotate(rot):draw()
	end
end