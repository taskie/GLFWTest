#include "Source.h"

#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

using namespace aps::al;

Source::Source()
{
	ALuint* name = new ALuint();
	alGenSources(1, name);
	name_.reset(name, [](ALuint* p){ alDeleteSources(1, p); delete p; });
}

Source::~Source()
{
	clearBuffers();
}

ALuint Source::name() const { return (name_) ? *name_ : 0; }

void Source::setBuffer(Buffer buffer)
{
	alSourcei(name(), AL_BUFFER, buffer.name());
}

void Source::pushBuffer(aps::al::Buffer buffer)
{
	ALuint buf = buffer.name();
	alSourceQueueBuffers(name(), 1, &buf);
	queuedBuffers_.push_back(buffer);
}

void Source::popProcessedBuffers()
{
	ALint processedNum = processedBuffersLength();
	if (processedNum == 0) return;
	
	if (processedNum >= queuedBuffers_.size()) {
		processedNum = static_cast<ALint>(queuedBuffers_.size());
	}
	
	std::vector<ALuint> ids(processedNum);
	for (int i = 0; i < processedNum; ++i) ids[i] = queuedBuffers_[i].name();
	alSourceUnqueueBuffers(name(), processedNum, &ids[0]);
	queuedBuffers_.erase(queuedBuffers_.begin(), std::next(queuedBuffers_.begin(), processedNum));
}

void Source::clearBuffers()
{
	stop();
	alSourcei(name(), AL_BUFFER, AL_NONE);
	queuedBuffers_.clear();
}

int Source::buffersLength()
{
	ALint queuedNum;
	alGetSourcei(name(), AL_BUFFERS_QUEUED, &queuedNum);
	return queuedNum;
}

int Source::processedBuffersLength()
{
	ALint processedNum;
	alGetSourcei(name(), AL_BUFFERS_PROCESSED, &processedNum);
	return processedNum;
}

int Source::unprocessedBuffersLength()
{
	ALint processedNum = processedBuffersLength();
	ALint queuedNum = buffersLength();
	return queuedNum - processedNum;
}

void Source::setGain(ALfloat gain)
{
	alSourcef(name(), AL_GAIN, gain);
}

void Source::play() { alSourcePlay(name()); }
void Source::pause() { alSourcePause(name()); }
void Source::stop() { alSourceStop(name()); }
void Source::rewind() { alSourceRewind(name()); }

bool Source::isInitial() const { return state() == AL_INITIAL; }
bool Source::isPlaying() const { return state() == AL_PLAYING; }
bool Source::isPaused() const { return state() == AL_PAUSED; }
bool Source::isStopped() const { return state() == AL_STOPPED; }

ALint Source::state() const
{
	ALint value;
	alGetSourcei(name(), AL_SOURCE_STATE, &value);
	return value;
}