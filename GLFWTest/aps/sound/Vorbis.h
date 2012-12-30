#pragma once

#include <memory>
#include <string>
#include <vector>
#include <cstdint>
#include <cstring>
#include <stdexcept>
#include <iostream>
#include <vorbis/vorbisfile.h>

namespace aps
{
	namespace sound
	{
		class VorbisFile
		{
		public:
			VorbisFile(std::string path);
			void rewind();
			std::vector<std::int16_t> read(std::size_t size);
			std::vector<std::int16_t> readAll();
			long rate() const;
			int channels() const;
			bool isStereo() const;
			bool bad() const;
			
		private:
			OggVorbis_File* file();
			
			std::shared_ptr<OggVorbis_File> file_;
			long rate_;
			int channels_;
			int bitstream_;
			bool bad_;
		};
	}
}