//
//  Vorbis.cpp
//  GLFWTest
//
//  Created by taskie on 2012/12/19.
//  Copyright (c) 2012年 alprosys. All rights reserved.
//

#include "Vorbis.h"

using namespace aps::sound;

VorbisFile::VorbisFile(std::string path)
: bitstream_(0), bad_(false)
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

void VorbisFile::rewind()
{
	if (bad()) return;
	ov_pcm_seek_page(file(), 0);
}

std::vector<std::int16_t> VorbisFile::read(std::size_t size)
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

std::vector<std::int16_t> VorbisFile::readAll()
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

long VorbisFile::rate() const { return rate_; }
int VorbisFile::channels() const { return channels_; }
bool VorbisFile::isStereo() const { return channels_ == 2; }

bool VorbisFile::bad() const { return bad_; }

OggVorbis_File* VorbisFile::file() { return file_.get(); }