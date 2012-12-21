#pragma once

#include <memory>

#include "ALHeader.h"

namespace aps
{
	namespace al
	{
		class Context
		{
		public:
			Context(ALCcontext* context)
			: context_(context, [](ALCcontext* p){ alcDestroyContext(p); }) { }
			
			void current()
			{
				alcMakeContextCurrent(context_.get());
			}
			
		private:
			std::shared_ptr<ALCcontext> context_;
		};
	}
}