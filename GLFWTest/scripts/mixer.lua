Mxr = Mxr or {
	mixer = sound.Mixer(),
	fadeOutInfo = {},
	soundType = {}
}

function Mxr:loadMusic(key, path)
	self.mixer:loadMusic(key, path)
	self.soundType[key] = "music"
end

function Mxr:loadSound(key, path)
	self.mixer:loadSound(key, path)
	self.soundType[key] = "sound"
end

function Mxr:play(key)
	if self.soundType[key] == "music" then
		self:setGain(key, profile.settings.bgmVolume or 0.8)
	else
		self:setGain(key, profile.settings.seVolume or 1)
	end
	self.mixer:play(key)
end

function Mxr:pause(key) self.mixer:pause(key) end
function Mxr:stop(key) self.mixer:stop(key) end
function Mxr:rewind(key) self.mixer:rewind(key) end
function Mxr:gain(key) return self.mixer:gain(key) end
function Mxr:setGain(key, gain) self.mixer:setGain(key, gain) end

function Mxr:update()
	self.mixer:update()
	local finishedItems = {}
	for key, info in pairs(self.fadeOutInfo) do
		self:setGain(key, (1 - info.frame / info.frameMax) * info.baseGain)
		info.frame = info.frame + 1
		if info.frame > info.frameMax then
			table.insert(finishedItems, key)
		end
	end
	for i, key in ipairs(finishedItems) do
		self:stop(key)
		self.fadeOutInfo[key] = nil
	end
end

function Mxr:loadWaveSound(key)
	self:loadSound(key, "sounds/" .. key .. ".wav")
end

function Mxr:loadVorbisMusic(key)
	self:loadMusic(key, "musics/" .. key .. ".ogg")
end

function Mxr:rewindAndPlay(key)
	self:rewind(key)
	self:play(key)
end

function Mxr:fadeOut(key, frameMax)
	self.fadeOutInfo[key] = {baseGain = Mxr:gain(key), frame = 0, frameMax = frameMax}
end