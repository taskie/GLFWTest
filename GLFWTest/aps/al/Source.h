#pragma once

#include <memory>
#include <deque>

#include "ALHeader.h"
#include "Buffer.h"

namespace aps
{
	namespace al
	{
		class Source
		{
		public:
			Source();
			~Source();
			ALuint name() const;
			
			void setBuffer(Buffer buffer);
			void pushBuffer(Buffer buffer);
			void popProcessedBuffers();
			void clearBuffers();
			int buffersLength();
			int processedBuffersLength();
			int unprocessedBuffersLength();
			
			ALfloat gain() const;
			void setGain(ALfloat gain);
			
			void play();
			void pause();
			void stop();
			void rewind();
			
			bool isInitial() const;
			bool isPlaying() const;
			bool isPaused() const;
			bool isStopped() const;
			
			ALint state() const;
			
		private:
			std::shared_ptr<ALuint> name_;
			std::deque<Buffer> queuedBuffers_;
		};
	}
}