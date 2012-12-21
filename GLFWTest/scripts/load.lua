-- class, subclass
dofile("scripts/class.lua")

-- Set
dofile("scripts/set.lua")

-- Rct
dofile("scripts/recta.lua")
local fontManager = font.Manager()
fontManager:loadFont("thin", "fonts/mplus-2p-thin.ttf", 0)
fontManager:loadFont("regular", "fonts/mplus-2p-regular.ttf", 0)
fontManager:loadFont("black", "fonts/mplus-2p-black.ttf", 0)
Rct.Text.fontex = fontex.Fontex(fontManager)

-- Mys, Col
dofile("scripts/const.lua")

-- * GameModels *
-- Input
dofile("scripts/input.lua")

-- Field
dofile("scripts/field.lua")

-- Actor, Bullet, Character
dofile("scripts/actor.lua")
dofile("scripts/bullet.lua")
dofile("scripts/character.lua")

-- Player
dofile("scripts/player.lua")

-- Weapon
dofile("scripts/weapon.lua")

-- Stage
dofile("scripts/stage.lua")

-- Experience
dofile("scripts/experience.lua")

-- Damage
dofile("scripts/damage.lua")

-- GameModel
dofile("scripts/gamemodel.lua")

-- SideBar
dofile("scripts/sidebar.lua")

-- GameView
dofile("scripts/gameview.lua")

-- Enemy
dofile("scripts/abstractenemy.lua")
dofile("scripts/enemy.lua")

-- Mixer
Mix = {}

Mix.mixer = sound.Mixer()
Mix.mixer:loadMusic("febricula", "musics/febricula_2.wav")
Mix.mixer:play("febricula")

dofile("scripts/test.lua")