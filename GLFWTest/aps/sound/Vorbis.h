#pragma once

#include <memory>
#include <string>
#include <vector>
#include <cstdint>
#include <cstring>
#include <stdexcept>
#include <iostream>

extern "C"
{
#include <vorbis/codec.h>
	#include <vorbis/vorbisfile.h>
}

namespace aps
{
	namespace sound
	{
		class VorbisFile
		{
		public:
			VorbisFile(std::string path)
			: bitstream_(0)
			{
				OggVorbis_File* vorbisFile = new OggVorbis_File();
				int error = ov_fopen(path.c_str(), vorbisFile);
				if (error)
				{
					bad_ = true;
					return;
				}
				
				file_.reset(vorbisFile, [](OggVorbis_File* p){ ov_clear(p); delete p; });
				
				vorbis_info* info = ov_info(file(), -1);
				rate_ = info->rate;
				channels_ = info->channels;
			}
			
			void rewind()
			{
				ov_raw_seek(file(), 0);
				bitstream_ = 0;
			}
			
			std::vector<std::int16_t> read(std::size_t size)
			{
				char buf[4096];
				std::size_t accum = 0;
				std::vector<std::int16_t> wave;
				while (accum < size)
				{
					std::size_t ret = ov_read(file(), buf, sizeof(buf), 0, 2, 1, &bitstream_);
					if (ret <= 0) break;
					wave.resize(accum + ret / 2);
					std::memcpy(&wave[accum], buf, ret);
					accum += ret / 2;
				}
				return wave;
			}
			
			std::vector<std::int16_t> readAll()
			{
				char buf[4096];
				std::size_t accum = 0;
				std::vector<std::int16_t> wave;
				for ( ; ;)
				{
					std::size_t ret = ov_read(file(), buf, sizeof(buf), 0, 2, 1, &bitstream_);
					if (ret <= 0) break;
					wave.resize(accum + ret / 2);
					std::memcpy(&wave[accum], buf, ret);
					accum += ret / 2;
				}
				return wave;
			}
			
			long rate() const { return rate_; }
			int channels() const { return channels_; }
			bool isStereo() const { return channels_ == 2; }
			
			bool bad() const { return bad_; }
			
		private:
			OggVorbis_File* file() { return file_.get(); }
			
			std::shared_ptr<OggVorbis_File> file_;
			long rate_;
			int channels_;
			int bitstream_;
			bool bad_;
		};
	}
}