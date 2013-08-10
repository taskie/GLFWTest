-- KeyAssign

subclass ("KeyAssign", Actor, Scn) { }

local function atIndex(t, value)
   for i, v in ipairs(t) do
      if v == value then return i end
   end
   return nil
end

function Scn.KeyAssign:new(old)
   Scn.KeyAssign.super.new(self)
   
   local textColor = Col.text
   self.oldScene = old
   self.input = Input()
   self.background = Bck.default
   
   self.barRect = Rct.Rect(Mys.field.x, Mys.screen.h, "polygon", Col.bar, 0, 0)
   
   self.items = {}
   self.items.texts = {"Capture (Z)", "Choice (X)", "Slow (Shift)", "Pause (Esc)", "Exit"}
   self.items.parameterNames = {"Z", "X", "LSHIFT", "ESC"}
   self.items.values = {}
   self.items.valueTextShapes = {}
   
   do
      local param = profile.joystick
      local values = self.items.values
      for i, name in ipairs(self.items.parameterNames) do
         self.items.values[i] = profile.joystick[name]
      end
   end
   
   for i, value in ipairs(self.items.values) do
      self.items.valueTextShapes[i] = Rct.Text(tostring(self.items.values[i]), "thin", 64, Col.lightText, "r")
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


function Scn.KeyAssign:update()
   self.background:update()
   Mxr:update()
   
   if self.input:isJustPressed("DOWN") then
      Mxr:play("weaponchoice")
      self.items.choice = self.items.choice + 1
      if self.items.choice > self.items.choiceMax then
	 self.items.choice = 1
      end
   end
   
   if self.input:isJustPressed("UP") then
      Mxr:play("weaponchoice")
      self.items.choice = self.items.choice - 1
      if self.items.choice < 1 then
	 self.items.choice = self.items.choiceMax
      end
   end
   
   if self.items.texts[self.items.choice] == "Exit" then
   if self.input:isJustPressed("Z") then
	 Mxr:play("ok")
	 do
	    local param = profile.joystick
	    local values = self.items.values
	    for i, name in ipairs(self.items.parameterNames) do
	       param[name] = values[i]
	    end
	 end
	 self.nextScene = Scn.Title()
      end
      else
      	for i = 1, 16 do
      		local state = self.input.joystick.device:buttonState(i)
      		if state:pressed() and state:just() then
      			local values = self.items.values
      			local choice = self.items.choice
      			local index = atIndex(values, i)
      			if index then
      				values[index], values[choice] = values[choice], values[index]
	      			valueTextShapes[choice]:renew(tostring(values[index]))
	      			valueTextShapes[choice]:renew(tostring(values[choice]))
      			else
	      			values[choice] = i
	      			valueTextShapes[choice]:renew(tostring(i))
      			end
	 			Mxr:play("ok")
      			break
      		end
      	end
   end
   
   return Scn.KeyAssign.super.update(self)
end

function Scn.KeyAssign:draw()
   self.background:draw()
   self.barRect:draw()
   self.barRect:draw(Mys.field.wx)
   self.items.choiceTriangle:draw(Mys.field.x + 15, 100 - 12 + (self.items.choice - 1) * 80)
   for i, shape in ipairs(self.items.valueTextShapes) do
      shape:draw(Mys.field.wx - 30, 100 + 40 + (i - 1) * 80)
   end
   for i, shape in ipairs(self.items.textShapes) do
      shape:draw(Mys.field.x + 30, 100 + (i - 1) * 80)
   end
end
