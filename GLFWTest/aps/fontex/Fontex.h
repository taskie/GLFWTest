#pragma once

#include <memory>
#include <array>

#include "../font/Manager.h"
#include "../gl/ShapeContainer.h"

namespace aps
{
	namespace fontex
	{
		class StringShape
		{
		public:
			StringShape(gl::ShapeContainer shape, int size, int width);
			gl::ShapeContainer get();
			int size();
			int width();
			
		private:
			gl::ShapeContainer shape_;
			int size_, width_;
		};
		
		class Fontex
		{
		public:
			Fontex(font::Manager fontManager);
			StringShape utf8StringShape(std::string text, std::string fontName, int size);
			StringShape utf8StringShape(std::string text, std::string fontName, int size, gl::Color color);
			
		private:
			class Impl;
			std::shared_ptr<Impl> pImpl_;
		};
	}
}
