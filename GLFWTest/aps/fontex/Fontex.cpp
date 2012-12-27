#include "Fontex.h"

#include "../gl/Texture2D.h"

#include <unordered_map>
#include <locale>
#ifndef _WIN32
#include <codecvt>
#endif
#include <iterator>
#include <boost/range/algorithm.hpp>

namespace aps
{
	namespace fontex
	{
		class Shape
		{
		public:
			Shape(){}
			Shape(unsigned int character, gl::ShapeContainer shape, font::GlyphBitmap bitmap)
			: shape_(shape)
			, character_(character)
			, width_(bitmap.width()), height_(bitmap.height())
			, left_(bitmap.left()), top_(bitmap.top()), pitch_(bitmap.pitch())
			, advance_(bitmap.advance())
			{
				
			}
			
			gl::ShapeContainer get()
			{
				gl::ShapeContainer shape;
				shape.pushChild(shape_);
				return shape_;
			}
			
			unsigned int character() { return character_; }
			int width() { return width_; }
			int height() { return height_; }
			int left() { return left_; }
			int top() { return top_; }
			int pitch() { return pitch_; }
			double advance() { return advance_; }
			
		private:
			gl::ShapeContainer shape_;
			unsigned int character_;
			int width_, height_, left_, top_, pitch_;
			double advance_;
			
		};
	}
}

using namespace aps::fontex;

class Fontex::Impl
{
public:
	Impl(font::Manager fontManager)
	: fontManager_(fontManager)
	{
		
	}
	
	StringShape utf8StringShape(std::string text, std::string fontName, int size)
	{
		std::array<double, 4> color{{0, 0, 0, 1}};
		return utf8StringShape(text, fontName, size, color);
	}
	
	StringShape utf8StringShape(std::string text, std::string fontName, int size, aps::gl::Color color)
	{
#ifndef _WIN32
		std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t> ucs2conv;
		std::u16string ucs2 = ucs2conv.from_bytes(text);
		
		std::vector<Shape> shapes;
		boost::transform(ucs2, std::back_inserter(shapes),
						 [this, fontName, size, color](std::size_t c){ return getShape(fontName, c, size, color); });
#else
		std::vector<Shape> shapes;
		boost::transform(text, std::back_inserter(shapes),
						 [this, fontName, size, color](std::size_t c){ return getShape(fontName, c, size, color); });
#endif
		unsigned int old = 0;
		int pen = 0;
		gl::ShapeContainer stringShape;
		for (auto shape : shapes) {
			if (old != 0) pen += fontManager_.kerning(fontName, old, shape.character(), size);
			old = shape.character();
			auto container = shape.get();
			container.setPosition(pen + shape.left(), -shape.top());
			stringShape.pushChild(container);
			pen += shape.advance();
		}
		
		return StringShape(stringShape, size, pen);
	}
	
private:
	Shape getShape(std::string fontName, std::size_t charCode, int size, aps::gl::Color color)
	{
		auto fontDictIter = cache_.find(fontName);
		if (fontDictIter == cache_.end())
		{
			cache_[fontName] = std::unordered_map<int, std::unordered_map<std::size_t, Shape>>();
			fontDictIter = cache_.find(fontName);
		}
		auto& fontDict = fontDictIter->second;
		
		auto fontSizeDictIter = fontDict.find(size);
		if (fontSizeDictIter == fontDict.end())
		{
			fontDict[size] = std::unordered_map<std::size_t, Shape>();
			fontSizeDictIter = fontDict.find(size);
		}
		auto& fontSizeDict = fontSizeDictIter->second;
		
		gl::ShapeContainer shape;
		
		auto cachedShapeIter = fontSizeDict.find(charCode);
		if (cachedShapeIter != fontSizeDict.end())
		{
			return cachedShapeIter->second;
		}
		else
		{
			aps::font::GlyphBitmap bitmap = fontManager_.getGlyphBitmap(fontName, charCode, size);
			
			std::vector<GLubyte> data(bitmap.width() * bitmap.height() * 4);
			for (int y = 0; y < bitmap.height(); ++y)
			{
				for (int x = 0; x < bitmap.width(); ++x)
				{
					for (int k = 0; k < 3; ++k)
					{
						data[(y * bitmap.width() + x) * 4 + k] = 0xFF;
					}
					data[(y * bitmap.width() + x) * 4 + 3] = bitmap.pixel(x, y);
				}
			}
			
			auto texture = aps::gl::Texture2D::fromData(&data[0], bitmap.width(), bitmap.height());
			texture.parameter(GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			texture.parameter(GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			auto texShape = aps::gl::ShapeContainer::rectWithTexture(texture, color);
			Shape shape(static_cast<unsigned int>(charCode), texShape, bitmap);
			cache_[fontName][size][charCode] = shape;
			return shape;
		}
	}
	
	font::Manager fontManager_;
	std::unordered_map<std::string, std::unordered_map<int, std::unordered_map<std::size_t, Shape>>> cache_;
};

// class StringShape
// public:

StringShape::StringShape(gl::ShapeContainer shape, int size, int width)
: shape_(shape), size_(size), width_(width)
{
	
}

aps::gl::ShapeContainer StringShape::get() {
	gl::ShapeContainer shape;
	shape.pushChild(shape_);
	return shape;
}

int StringShape::size() { return size_; }
int StringShape::width() { return width_; }

// class Fontex
// public:

Fontex::Fontex(font::Manager fontManager)
: pImpl_(new Impl(fontManager))
{
	
}

StringShape Fontex::utf8StringShape(std::string text, std::string fontName, int size, aps::gl::Color color)
{
	return pImpl_->utf8StringShape(text, fontName, size, color);
}

StringShape Fontex::utf8StringShape(std::string text, std::string fontName, int size)
{
	return pImpl_->utf8StringShape(text, fontName, size);
}