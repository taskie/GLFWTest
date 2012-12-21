#pragma once

#include <memory>
#include <cstdint>

#include "ALHeader.h"

namespace aps
{
	namespace al
	{
		class Buffer
		{
		public:
			Buffer();
			~Buffer();
			
			ALuint name() const;
			
			void setData(std::int16_t *data, std::size_t arraySize, long frequency, bool isStereo);
			
		private:
			std::shared_ptr<ALuint> name_;
		};
	}
}