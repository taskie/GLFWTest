#pragma once

#include <string>
#include <vector>
#include <memory>
#include <array>

#include "Color.h"
#include "ShapeElement.h"
#include "Texture2D.h"

namespace aps
{
	namespace gl
	{
		class ShapeContainer
		{
		public:
			ShapeContainer();
			ShapeContainer(ShapeElement shapeElement);
			ShapeContainer(ShapeElement shapeElement, ShapeElement::DrawMode mode);
			~ShapeContainer() = default;
			
			ShapeElement* operator->();
			
			ShapeContainer& point();
			ShapeContainer& lines();
			ShapeContainer& lineLoop();
			ShapeContainer& lineStrip();
			ShapeContainer& triangles();
			ShapeContainer& triangleStrip();
			ShapeContainer& polygon();
			
			ShapeContainer& setMode(ShapeElement::DrawMode mode);
			ShapeContainer& setAnchor(double x = 0, double y = 0, double z = 0);
			ShapeContainer& setPosition(double x = 0, double y = 0, double z = 0);
			ShapeContainer& setScale(double scale);
			ShapeContainer& setScale(double x, double y, double z = 1);
			ShapeContainer& setRotate(double angle = 0, double x = 0, double y = 0, double z = 1);
			ShapeContainer& setColorForce(Color color);
			
			ShapeElement::DrawMode mode();
			std::array<double, 3> anchor();
			std::array<double, 3> position();
			std::array<double, 3> scale();
			std::array<double, 4> rotate();
			
			void pushChild(ShapeContainer child);
			void setTexture(Texture2D texture);
			
			static ShapeContainer rectWithTexture(Texture2D texture);
			static ShapeContainer rectWithTexture(Texture2D texture, Color color);
			
			void draw() const;
			
		private:
			std::shared_ptr<ShapeElement> shapeElement_;
			std::shared_ptr<Texture2D> texture_;
			std::vector<ShapeContainer> children_;
			ShapeElement::DrawMode mode_;
			
			std::array<double, 3> anchor_;
			std::array<double, 3> position_;
			std::array<double, 3> scale_;
			std::array<double, 4> rotate_;
		};
	}
}