-- Settings

subclass ("Settings", Actor, Scn) { }

local function atIndex(t, value)
   for i, v in ipairs(t) do
      if v == value then return i end
   end
   return nil
end

function Scn.Settings:new(old)
   Scn.Settings.super.new(self)
   
   local textColor = Col.text
   self.oldScene = old
   self.input = Input()
   self.background = Bck.default
   
   self.barRect = Rct.Rect(Mys.field.x, Mys.screen.h, "polygon", Col.bar, 0, 0)
   
   self.items = {}
   self.items.texts = {"SE Volume", "BGM Volume", "Exit"}
   self.items.parameterNames = {"seVolume", "bgmVolume"}
   self.items.values = {{}, {}}
   self.items.valueTexts = {{}, {}}
   for i = 1, 11 do
      local value = (i - 1) * 10
      self.items.values[1][i] = value
      self.items.values[2][i] = value
      self.items.valueTexts[1][i] = tostring(value)
      self.items.valueTexts[2][i] = tostring(value)
   end
   self.items.valueTextShapes = {}
   self.items.valueChoices = {}
   
   do
      local param = profile.settings
      local values = self.items.values
      for i, name in ipairs(self.items.parameterNames) do
	 self.items.valueChoices[i] = atIndex(values[i], math.floor(param[name] * 100 + 0.5)) or 1
      end
   end
   
   for i, choice in ipairs(self.items.valueChoices) do
      self.items.valueTextShapes[i] = Rct.Text(self.items.valueTexts[i][choice], "thin", 64, Col.lightText, "r")
   end
   
   self.items.choice = 1
   self.items.choiceMax = #self.items.texts
   self.items.choiceTriangle = Rct.Regular(3, 5, "lineLoop", textColor)
   self.items.textShapes = {}
   for i, text in ipairs(self.items.texts) do
      self.items.textShapes[i] = Rct.Text(text, "thin", 32, textColor, "l")
   end
   self.nextScene = false
end


function Scn.Settings:update()
   self.background:update()
   Mxr:update()
   
   if self.input:isJustPressed("DOWN") then
      Mxr:stop("conduit")
      Mxr:play("weaponchoice")
      self.items.choice = self.items.choice + 1
      if self.items.choice > self.items.choiceMax then
	 self.items.choice = 1
      end
   end
   
   if self.input:isJustPressed("UP") then
      Mxr:stop("conduit")
      Mxr:play("weaponchoice")
      self.items.choice = self.items.choice - 1
      if self.items.choice < 1 then
	 self.items.choice = self.items.choiceMax
      end
   end
   
   if self.input:isJustPressed("LEFT") then
      local choice = self.items.choice
      if self.items.valueChoices[choice]
	 and self.items.valueChoices[choice] - 1 >= 1
      then
	 Mxr:play("ok")
	 self.items.valueChoices[choice] = self.items.valueChoices[choice] - 1
	 self.items.valueTextShapes[choice]:renew(self.items.valueTexts[choice][self.items.valueChoices[choice]])
	 local name = self.items.parameterNames[choice]
	 profile.settings[name] = self.items.values[choice][self.items.valueChoices[choice]] / 100
	 if name == "bgmVolume" then
	    
	 end
      end
   end
   
   if self.input:isJustPressed("RIGHT") then
      local choice = self.items.choice
      if self.items.valueChoices[choice]
	 and self.items.valueChoices[choice] + 1 <= #self.items.values[choice]
      then
	 self.items.valueChoices[choice] = self.items.valueChoices[choice] + 1
	 self.items.valueTextShapes[choice]:renew(self.items.valueTexts[choice][self.items.valueChoices[choice]])
	 local name = self.items.parameterNames[choice]
	 profile.settings[name] = self.items.values[choice][self.items.valueChoices[choice]] / 100
	 if name == "bgmVolume" then

	 end
	 Mxr:rewindAndPlay("ok")
      end
   end
   
   if self.input:isJustPressed("Z") then
      if self.items.texts[self.items.choice] == "Exit" then
	 Mxr:play("ok")
	 do
	    local param = profile.settings
	    local values = self.items.values
	    for i, name in ipairs(self.items.parameterNames) do
	       param[name] = values[i][self.items.valueChoices[i]] / 100
	    end
	 end
	 self.nextScene = Scn.Title()
      end
   end
   
   return Scn.Settings.super.update(self)
end

function Scn.Settings:draw()
   self.background:draw()
   self.barRect:draw()
   self.barRect:draw(Mys.field.wx)
   self.items.choiceTriangle:draw(Mys.field.x + 15, 290 - 12 + (self.items.choice - 1) * 80)
   for i, shape in ipairs(self.items.valueTextShapes) do
      shape:draw(Mys.field.wx - 30, 290 + 40 + (i - 1) * 80)
   end
   for i, shape in ipairs(self.items.textShapes) do
      shape:draw(Mys.field.x + 30, 290 + (i - 1) * 80)
   end
end
