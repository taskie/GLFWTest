//
//  Wave.h
//  GLFWTest
//
//  Created by taskie on 2012/12/20.
//  Copyright (c) 2012年 alprosys. All rights reserved.
//

#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <fstream>
#include <cstdint>
#include <cstring>

#include "../binary/BinaryReader.h"

namespace aps
{
	namespace sound
	{
		class WaveFile
		{
		public:
			WaveFile(std::string path)
			: bad_(false)
			{
				file_.reset(new binary::BinaryFileReader(path));
				if (file_->isGood())
				{
					parseHeader();
				}
				else
				{
					bad_ = true;
				}
			}
			
			std::vector<std::int16_t> read(std::size_t size)
			{
				std::vector<std::int16_t> wave;
				
				if (!file_->isGood()) return wave;
				std::vector<std::uint8_t> bytes = file_->bytes(size);
				if (bitStream_ + bytes.size() > dataSize_)
				{
					bytes.resize(dataSize_ - bitStream_);
				}
				bitStream_ += bytes.size();
				
				wave.resize(bytes.size() / 2);
				std::memcpy(&wave[0], &bytes[0], bytes.size());
				
				return wave;
			}
			
			std::vector<std::int16_t> readAll()
			{
				std::vector<std::int16_t> wave;
				
				if (!file_->isGood()) return wave;
				std::vector<std::uint8_t> bytes = file_->bytes(dataSize_);
				if (bitStream_ + bytes.size() > dataSize_)
				{
					bytes.resize(dataSize_ - bitStream_);
				}
				bitStream_ += bytes.size();
				
				wave.resize(bytes.size() / 2);
				std::memcpy(&wave[0], &bytes[0], bytes.size());
				
				return wave;
			}
			
			long rate() const { return rate_; }
			int channels() const { return channels_; }
			bool isStereo() const { return channels_ == 2; }
			
			bool bad() const { return bad_; }
			
		private:
			
			void parseHeader()
			{
				if (file_->string(4) != "RIFF") { bad_ = true; return; }
				file_->word32LE();	// fileSize
				if (file_->string(4) != "WAVE") { bad_ = true; return; }
				if (file_->string(4) != "fmt ") { bad_ = true; return; }
				file_->word32LE();	// fmtSize
				file_->word16LE();	// fmtId
				channels_ = file_->word16LE();
				rate_ = file_->word32LE();
				file_->word32LE();	// fmtVelocity
				file_->word16LE();	// fmtBlockSize
				file_->word16LE();	// fmtBit
				if (file_->string(4) != "data") { bad_ = true; return; }
				dataSize_ = file_->word32LE();	// fmtVelocity
				
				if (!file_->isGood()) { bad_ = true; return; }
				bitStream_ = 0;	
			}
			
			std::shared_ptr<binary::BinaryFileReader> file_;
			bool bad_;
			long rate_;
			std::size_t bitStream_;
			std::size_t dataSize_;
			int channels_;
		};
	}
}