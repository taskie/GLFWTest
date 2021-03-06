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

-- Mxr
dofile("scripts/mixer.lua")
local musics = {"maikon", "conduit", "retrofire", "influx", "febricula", "cascade", "stig"}
for i, music in ipairs(musics) do
	Mxr:loadVorbisMusic(music)
end

local sounds = {"enemydamaged", "enemydestroyed", "levelup", "ng", "ok", "playerdamaged", "playershoot", "weaponchoice"}
for i, sound in ipairs(sounds) do
	Mxr:loadWaveSound(sound)
end

-- Input
dofile("scripts/input.lua")

-- SaveLoad
dofile("scripts/saveload.lua")

-- * GameModels *

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

-- BackGround
dofile("scripts/background.lua")

-- DamageScreen
dofile("scripts/damagescreen.lua")

-- Scene
Scn = {}
dofile("scripts/title.lua")
dofile("scripts/gamescene.lua")
dofile("scripts/gameover.lua")
dofile("scripts/gameclear.lua")
dofile("scripts/customize.lua")
dofile("scripts/settings.lua")
dofile("scripts/keyconfig.lua")
dofile("scripts/savereplay.lua")
dofile("scripts/records.lua")
dofile("scripts/pause.lua")