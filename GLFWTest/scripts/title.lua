-- Title

subclass ("Title", Actor, Scn) { }

function Scn.Title:new()
   Scn.Title.super.new(self)
   
   local textColor = Col.text
   self.input = Input()
   self.background = Bck.default
   self.barRect = Rct.Rect(Mys.field.x, Mys.screen.h, "polygon", Col.bar, 0, 0)
   self.maskRect = Rct.Rect(Mys.screen.w - 2 * Mys.field.x, Mys.screen.h, "polygon", {1, 1, 1, 0.5}, 0, 0)
   self.mystig = Rct.Text("MYSTiG", "thin", 96, textColor, "l")
   self.infration = Rct.Text("hyper inflation", "thin", 48, textColor, "l")
   self.version = Rct.Text("Ver. " .. Mys.version, "regular", 16, textColor, "l")
   self.debug = Rct.Text("", "regular", 16, textColor, "l")
   
   self.items = {}
   self.items.texts = {"Start", "Customize", "Records", "Settings", "Key Config", "Quit"}
   if not profile.records.cleared then self.items.texts[2] = " " end
   self.items.choice = 1
   self.items.choiceMax = #self.items.texts
   self.items.choiceTriangle = Rct.Regular(3, 5, "lineLoop", textColor)
   self.items.xShifts = {}
   self.items.xShiftMax = 15
   self.items.textShapes = {}
   for i, text in ipairs(self.items.texts) do
      self.items.xShifts[i] = 0
      self.items.textShapes[i] = Rct.Text(text, "thin", 32, textColor, "r")
   end
   self.items.xShifts[1] = self.items.xShiftMax
   
   self.random = Mys.mt
   self.enemies = Field()
   self.enemiesBullets = Field()
   self.capturedArray = {}
   for k, v in pairs(profile.records.captured) do
      table.insert(self.capturedArray, k)
   end
   
   self.nextScene = false
end

function Scn.Title:update()
   self.background:update()
   
   -- self.debug:renew("")
   
   if #self.capturedArray ~= 0 and (self.random:next() < 0.01 or self.enemies:isEmpty()) then
      local name = self.capturedArray[self.random:nextInt(1, #self.capturedArray)]
      -- name = "Test"
      local enemy = Enm[name](self)
      if not enemy.isBoss then
	 self.enemies:add(enemy)
      end
   end
   
   self.enemies:update()
   self.enemiesBullets:update()
   
   if self.input:isJustPressed("DOWN") then
      Mxr:play("weaponchoice")
      self.items.choice = self.items.choice + 1
      while self.items.texts[self.items.choice] == " " do
	 self.items.choice = self.items.choice + 1
      end
      if self.items.choice > self.items.choiceMax then
	 self.items.choice = 1
      end
   end
   
   if self.input:isJustPressed("UP") then
      Mxr:play("weaponchoice")
      self.items.choice = self.items.choice - 1
      while self.items.texts[self.items.choice] == " " do
	 self.items.choice = self.items.choice - 1
      end
      if self.items.choice < 1 then
	 self.items.choice = self.items.choiceMax
      end
   end
   
   if self.input:isJustPressed("Z") then
      self.nextScene = false
      if self.items.texts[self.items.choice] == "Start" then
	 Mxr:play("ok")
	 self.nextScene = Scn.Game(LoggingInput(), nil, profile.game)
      elseif self.items.texts[self.items.choice] == "Customize" then
	 Mxr:play("ok")
	 self.nextScene = Scn.Customize()
      elseif self.items.texts[self.items.choice] == "Settings" then
	 Mxr:play("ok")
	 self.nextScene = Scn.Settings()
      elseif self.items.texts[self.items.choice] == "Records" then
	 Mxr:play("ok")
	 self.nextScene = Scn.Records()
      elseif self.items.texts[self.items.choice] == "Key Config" then
	 Mxr:play("ok")
	 self.nextScene = Scn.KeyConfig()
      elseif self.items.texts[self.items.choice] == "Quit" then
	 return false
      end
   end
   
   for i, text in ipairs(self.items.texts) do
      if self.items.choice == i then
	 self.items.xShifts[i] = self.items.xShifts[i] + 1
	 if self.items.xShifts[i] > self.items.xShiftMax then
	    self.items.xShifts[i] = self.items.xShiftMax
	 end
      else
	 self.items.xShifts[i] = self.items.xShifts[i] - 1
	 if self.items.xShifts[i] < 0 then
	    self.items.xShifts[i] = 0
	 end
      end
   end
   
   return Scn.Title.super.update(self)
end

local function drawField(field)
   for id, actor in field:pairs() do
      actor:draw()
   end
end

function Scn.Title:draw()
   self.background:draw()
   drawField(self.enemies)
   drawField(self.enemiesBullets)
   self.barRect:draw()
   self.barRect:draw(Mys.field.wx)
   --	self.maskRect:draw(Mys.field.x)
   self.mystig:draw(Mys.screen.x + 50, 120)
   self.debug:draw(Mys.screen.x + 50, 400)
   self.infration:draw(Mys.screen.x + 50, 180)
   self.version:draw(Mys.screen.x + 50, 240)
   self.items.choiceTriangle:draw(Mys.screen.wx - 40, 260 - 12 + (self.items.choice - 1) * 40, 180)
   for i, shape in ipairs(self.items.textShapes) do
      shape:draw(Mys.screen.wx - 50 - self.items.xShifts[i], 260 + (i - 1) * 40)
   end
end
