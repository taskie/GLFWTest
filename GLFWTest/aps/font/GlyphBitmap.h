#pragma once

#include <memory>

namespace aps
{
	namespace font
	{
		class GlyphBitmap
		{
		public:
			GlyphBitmap(unsigned char* bitmap, int width, int height, int left, int top, int pitch, double advance);
			unsigned char pixel(int x, int y);
			const unsigned char* data();
			int width();
			int height();
			int left();
			int top();
			int pitch();
			double advance();
			
		private:
			class Impl;
			std::shared_ptr<Impl> pImpl;
		};
	}
}
