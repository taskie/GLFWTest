//
//  BinaryReader.cpp
//  GLFWTest
//
//  Created by taskie on 2012/12/20.
//  Copyright (c) 2012年 alprosys. All rights reserved.
//

#include "BinaryReader.h"

#include <iostream>
#include <algorithm>

using namespace aps::binary;

std::uint8_t aps::binary::byteToWord8(char byte)
{
	return static_cast<std::uint8_t>(byte);
}

std::uint16_t aps::binary::bytesToWord16LE(const char bytes[2])
{
	return byteToWord8(bytes[0]) | static_cast<std::uint16_t>(byteToWord8(bytes[1])) << 8;
}

std::uint16_t aps::binary::bytesToWord16BE(const char bytes[2])
{
	return byteToWord8(bytes[1]) | static_cast<std::uint16_t>(byteToWord8(bytes[0])) << 8;
}

std::uint32_t aps::binary::bytesToWord32LE(const char bytes[4])
{
	return bytesToWord16LE(bytes) | static_cast<std::uint32_t>(bytesToWord16LE(bytes + 2)) << 16;
}

std::uint32_t aps::binary::bytesToWord32BE(const char bytes[4])
{
	return bytesToWord16BE(bytes + 2) | static_cast<std::uint32_t>(bytesToWord16BE(bytes)) << 16;
}

std::uint64_t aps::binary::bytesToWord64LE(const char bytes[8])
{
	return bytesToWord32LE(bytes) | static_cast<std::uint64_t>(bytesToWord32LE(bytes + 4)) << 32;
}

std::uint64_t aps::binary::bytesToWord64BE(const char bytes[8])
{
	return bytesToWord32BE(bytes + 4) | static_cast<std::uint64_t>(bytesToWord32BE(bytes)) << 32;
}

BinaryReader::BinaryReader() { }

BinaryReader::~BinaryReader() { }

std::uint8_t BinaryReader::word8()
{
	char c; pIn_->read(&c, sizeof(c));
	return byteToWord8(c);
}

std::uint16_t BinaryReader::word16LE()
{
	char cs[2]; pIn_->read(cs, sizeof(cs));
	return bytesToWord16LE(cs);
}

std::uint16_t BinaryReader::word16BE()
{
	char cs[2]; pIn_->read(cs, sizeof(cs));
	return bytesToWord16BE(cs);
}

std::uint32_t BinaryReader::word32LE()
{
	char cs[4]; pIn_->read(cs, sizeof(cs));
	return bytesToWord32LE(cs);
}

std::uint32_t BinaryReader::word32BE()
{
	char cs[4]; pIn_->read(cs, sizeof(cs));
	return bytesToWord32BE(cs);
}

std::uint64_t BinaryReader::word64LE()
{
	char cs[8]; pIn_->read(cs, sizeof(cs));
	return bytesToWord64LE(cs);
}

std::uint64_t BinaryReader::word64BE()
{
	char cs[8]; pIn_->read(cs, sizeof(cs));
	return bytesToWord64BE(cs);
}

std::vector<char> BinaryReader::charArray(std::size_t size)
{
	std::vector<char> s(size);
	pIn_->read(&s[0], size);
	return s;
}

std::vector<char> BinaryReader::securedCharArray(std::size_t size)
{
	std::vector<char> s;
	s.reserve(size);
	
	for (int i = 0; i < size; ++i)
	{
		char c; pIn_->get(c);
		if (!pIn_->good()) break;
		s.push_back(c);
	}
	
	s.shrink_to_fit();
	return s;
}

std::vector<std::uint8_t> BinaryReader::bytes(std::size_t size)
{
	std::vector<char> s = charArray(size);
	std::vector<std::uint8_t> bs(s.size());
	std::transform(s.begin(), s.end(), bs.begin(), byteToWord8);
	return bs;
}

std::vector<std::uint8_t> BinaryReader::securedBytes(std::size_t size)
{
	std::vector<char> s = securedCharArray(size);
	std::vector<std::uint8_t> bs(s.size());
	std::transform(s.begin(), s.end(), bs.begin(), byteToWord8);
	return bs;
}

std::string BinaryReader::string(std::size_t size)
{
	std::vector<char> s = charArray(size);
	return std::string(s.begin(), s.end());
}

std::string BinaryReader::securedString(std::size_t size)
{
	std::vector<char> s = securedCharArray(size);
	return std::string(s.begin(), s.end());
}

void BinaryReader::skip(std::size_t size)
{
	charArray(size);
}

bool BinaryReader::isGood() const
{
	if (pIn_ && pIn_->good()) return true;
	return false;
}

void BinaryReader::setInputStream(std::istream* pIn)
{
	pIn_.reset(pIn);
}

BinaryFileReader::BinaryFileReader(std::string filePath)
{
	setInputStream(new std::ifstream(filePath, std::ifstream::in | std::ifstream::binary));
}