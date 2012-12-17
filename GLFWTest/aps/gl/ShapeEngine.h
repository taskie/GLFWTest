#pragma once

#include <vector>

#include "ShapeContainer.h"

namespace aps
{
	namespace gl
	{
		class ShapeEngine
		{
		public:
			ShapeEngine();
			unsigned int regist(ShapeContainer shape)
			{
				unsigned int count = static_cast<unsigned int>(shapes_.size());
				shapes_.push_back(shape);
				return count;
			}
			void draw(unsigned int id, double x, double y, double rot)
			{
				shapes_.at(id).setPosition(x, y).setRotate(rot).draw();
			}
		private:
			std::vector<ShapeContainer> shapes_;
		};
	}
}