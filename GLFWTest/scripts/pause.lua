-- Pause

subclass ("Pause", Actor, Scn) { }

function Scn.Pause:new()
   Scn.Pause.super.new(self)
   
   local textColor = Col.text
   self.input = Input()
   self.background = Bck.default
   self.barRect = Rct.Rect(Mys.field.x, Mys.screen.h, "polygon", Col.bar, 0, 0)
   self.pauseTextShape = Rct.Text("Pause", "thin", 64, textColor, "r")
   
   self.items = {}
   self.items.texts = {"Continue", "Return to Title"}
   self.items.choice = 1
   self.items.choiceMax = #self.items.texts
   self.items.choiceTriangle = Rct.Regular(3, 5, "lineLoop", textColor)
   self.items.textShapes = {}
   for i, text in ipairs(self.items.texts) do
      self.items.textShapes[i] = Rct.Text(text, "thin", 32, textColor, "l")
   end
   self.nextScene = false
end

function Scn.Pause:update()
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
   
   if self.input:isJustPressed("Z") then
      if self.items.texts[self.items.choice] == "Continue" then
	 return "continue"
      elseif self.items.texts[self.items.choice] == "Return to Title" then
	 return "title"
      end
   end
   
   return Scn.Pause.super.update(self)
end

function Scn.Pause:draw()
   self.background:draw()
   self.barRect:draw()
   self.barRect:draw(Mys.field.wx)
   self.pauseTextShape:draw(Mys.field.wx - 10, 200)
   self.items.choiceTriangle:draw(Mys.field.x + 20, 260 - 12 + (self.items.choice - 1) * 40)
   for i, shape in ipairs(self.items.textShapes) do
      shape:draw(Mys.field.x + 40, 260 + (i - 1) * 40)
   end
end
