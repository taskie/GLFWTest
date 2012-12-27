//
//  BinaryReader.h
//  GLFWTest
//
//  Created by taskie on 2012/12/20.
//  Copyright (c) 2012年 alprosys. All rights reserved.
//

#ifndef __GLFWTest__BinaryReader__
#define __GLFWTest__BinaryReader__

#include <string>
#include <vector>
#include <fstream>
#include <memory>
#include <cstdint>
#include <climits>

static_assert(CHAR_BIT == 8, "These codes works in \"1byte == 8bit\" environments only.");

namespace aps
{
	namespace binary
	{
		std::uint8_t byteToWord8(char byte);
		std::uint16_t bytesToWord16LE(const char bytes[2]);
		std::uint16_t bytesToWord16BE(const char bytes[2]);
		std::uint32_t bytesToWord32LE(const char bytes[4]);
		std::uint32_t bytesToWord32BE(const char bytes[4]);
		std::uint64_t bytesToWord64LE(const char bytes[8]);
		std::uint64_t bytesToWord64BE(const char bytes[8]);
		
		class BinaryReader
		{
		public:
			BinaryReader();
			virtual ~BinaryReader();
			
			std::uint8_t word8();
			std::uint16_t word16LE();
			std::uint16_t word16BE();
			std::uint32_t word32LE();
			std::uint32_t word32BE();
			std::uint64_t word64LE();
			std::uint64_t word64BE();
			std::vector<char> charArray(std::size_t size);
			std::vector<char> securedCharArray(std::size_t size);
			std::vector<std::uint8_t> bytes(std::size_t size);
			std::vector<std::uint8_t> securedBytes(std::size_t size);
			std::string string(std::size_t size);
			std::string securedString(std::size_t size);
			void skip(std::size_t size);
			
			void seekBegin();
			
			bool isGood() const;
			
		protected:
			void setInputStream(std::istream* pIn);
			
		public:
			std::unique_ptr<std::istream> pIn_;
		};
		
		class BinaryFileReader : public BinaryReader
		{
		public:
			BinaryFileReader(std::string filePath);
		};
	}
}

#endif /* defined(__GLFWTest__BinaryReader__) */
