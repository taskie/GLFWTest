-- Test

Test = {}

input = Input()
field = Field()

function Test.input()
	print(input:isPressed("Z"), input:isJustPressed("Z"))
end

k = 0

bulletShapeA = Rct.Circle(5, "lineLoop", {1, 1, 1, 0.1})
bulletShapeB = Rct.Circle(5, "lineLoop", {1, 1, 0, 0.1})
bulletShapeC = Rct.Circle(5, "lineLoop", {0, 1, 1, 0.1})

function Test.field()
	field:add(Bullet(nil, Mys.field.cx, 200, k, 1, 3, 5, bulletShapeA))
	field:add(Bullet(nil, Mys.field.cx, 200, - k * 2, 3, 3, 5, bulletShapeB))
	field:add(Bullet(nil, Mys.field.cx, 200, k * 3, 5, 3, 5, bulletShapeC))
	k = k + math.pi / 13 + 0.1
	field:update()
end

stage = Stage()
model = GameModel(stage)
view = GameView(model)

function Test.update()
	model:update()
	view:update()
end

function Test.draw()
	view:draw()
end
