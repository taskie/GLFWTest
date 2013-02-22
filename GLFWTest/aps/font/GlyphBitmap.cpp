//
//  GlyphBitmap.cpp
//  CppTest
//
//  Created by taskie on 2012/12/02.
//  Copyright (c) 2012年 taskie. All rights reserved.
//

#include "GlyphBitmap.h"

#include <vector>

using namespace aps::font;

// GlyphBitmap::Impl

class GlyphBitmap::Impl
{
public:
	Impl(unsigned char* bitmap, int width, int height, int left, int top, int pitch, double advance)
	: bitmap_(bitmap, bitmap + width * height)
	, width_(width), height_(height)
	, left_(left), top_(top), pitch_(pitch), advance_(advance)
	{
		
	}
	
	unsigned char pixel(int x, int y)
	{
		return bitmap_.at(y * width_ + x);
	}
	
	const unsigned char* data()
	{
		if (bitmap_.empty()) return nullptr;
		return bitmap_.data();
	}
	
	int width() { return width_; }
	int height() { return height_; }
	int size() { return width() * height(); }
	int left() { return left_; }
	int top() { return top_; }
	int pitch() { return pitch_; }
	double advance() { return advance_; }
	
private:
	std::vector<unsigned char> bitmap_;
	int width_, height_, left_, top_, pitch_;
	double advance_;
};

// GlyphBitmap

GlyphBitmap::GlyphBitmap(unsigned char* bitmap, int width, int height, int left, int top, int pitch, double advance)
: pImpl(new Impl(bitmap, width, height, left, top, pitch, advance))
{
	
}

unsigned char GlyphBitmap::pixel(int x, int y) { return pImpl->pixel(x, y); }
const unsigned char* GlyphBitmap::data() { return pImpl->data(); }
int GlyphBitmap::size() { return pImpl->size(); }
int GlyphBitmap::width() { return pImpl->width(); }
int GlyphBitmap::height() { return pImpl->height(); }
int GlyphBitmap::left() { return pImpl->left(); }
int GlyphBitmap::top() { return pImpl->top(); }
int GlyphBitmap::pitch() { return pImpl->pitch(); }
double GlyphBitmap::advance() { return pImpl->advance(); }