#include "Buffer.h"

#include <iostream>

using namespace aps::al;

Buffer::Buffer()
{
	ALuint* name = new ALuint();
	alGenBuffers(1, name);
	name_.reset(name, [](ALuint* p){ alDeleteBuffers(1, p); delete p; });
}

Buffer::~Buffer()
{
	
}

ALuint Buffer::name() const { return (name_) ? *name_ : 0; }

void Buffer::setData(std::int16_t *data, std::size_t arraySize, long frequency, bool isStereo)
{
	ALenum format = (isStereo) ? AL_FORMAT_STEREO16 : AL_FORMAT_MONO16;
	alBufferData(name(), format, data, static_cast<ALsizei>(arraySize * 2), static_cast<ALsizei>(frequency));
}
