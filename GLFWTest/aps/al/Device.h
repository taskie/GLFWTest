#pragma once

#include <memory>

#include "ALHeader.h"
#include "Context.h"

namespace aps
{
	namespace al
	{
		class Device
		{
		public:
			Device() : device_(alcOpenDevice(NULL), [](ALCdevice* p){ alcCloseDevice(p); }) { }
			
			Context context() { return Context(alcCreateContext(device_.get(), NULL)); }
			
		private:
			std::shared_ptr<ALCdevice> device_;
		};
	}
}