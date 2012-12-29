class ("SaveLoad") { }

MP = require "scripts.lib.MessagePack"

function serializeProfile()
	profileBinary = MP.pack(profile)
end

function deserializeProfile()
	profile = MP.unpack(profileBinary)
end

if profileBinary then
	deserializeProfile()
end

local function setDefaultValue(t, key, value)
	t[key] = t[key] or value
end

profile = profile or {}
setDefaultValue(profile, "game", {})
setDefaultValue(profile.game, "stages", 10)
setDefaultValue(profile.game, "enemyProbability", 0.01)
setDefaultValue(profile.game, "bulletExpMode", false)
setDefaultValue(profile.game, "enemyWithEnemyMode", false)
setDefaultValue(profile.game, "verboseMode", false)
setDefaultValue(profile, "settings", {})
setDefaultValue(profile.settings, "bgmVolume", 0.8)
setDefaultValue(profile.settings, "seVolume", 1.0)
setDefaultValue(profile, "records", {})
setDefaultValue(profile.records, "ranking", {})
setDefaultValue(profile.records, "captured", {})
setDefaultValue(profile.records, "cleared", false)