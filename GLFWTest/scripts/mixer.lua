Mxr = Mxr or {
	mixer = sound.Mixer()
}

function Mxr:loadMusic(key, path) self.mixer:loadMusic(key, path) end
function Mxr:loadSound(key, path) self.mixer:loadSound(key, path) end
function Mxr:play(key) self.mixer:play(key) end
function Mxr:pause(key) self.mixer:pause(key) end
function Mxr:stop(key) self.mixer:stop(key) end
function Mxr:rewind(key) self.mixer:rewind(key) end
function Mxr:update() self.mixer:update() end

function Mxr:loadWaveSound(key)
	self:loadSound(key, "sounds/" .. key .. ".wav")
end

function Mxr:loadVorbisMusic(key)
	self:loadMusic(key, "musics/" .. key .. ".ogg")
end

function Mxr:rewindAndPlay(key)
	self.mixer:rewind(key)
	self.mixer:play(key)
end