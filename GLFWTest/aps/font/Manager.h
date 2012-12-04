#pragma once

#include <memory>
#include <string>

#include "GlyphBitmap.h"

namespace aps
{
	namespace font
	{
		class Manager
		{
		public:
			Manager();
			bool loadFont(std::string name, std::string filePath, long faceIndex);
			GlyphBitmap getGlyphBitmap(std::string name, unsigned long charCode, int size);
			double kerning(std::string name, unsigned int left, unsigned int right, int size);
			std::string errorMessage();
			
		private:
			class Impl;
			std::shared_ptr<Impl> pImpl;
		};
	}
}
