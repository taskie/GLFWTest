#pragma once

#include <vector>
#include <array>

#include "GLHeader.h"

namespace aps
{
	namespace gl
	{
		class ShapeElement
		{
		public:
			ShapeElement();
			
			ShapeElement& vertex(double x, double y, double z = 0.0, double w = 1.0);
			ShapeElement& color(double r, double g, double b, double a = 1.0);
			ShapeElement& texCoord(double s, double t = 0.0, double r = 0.0, double q = 1.0);
			
			ShapeElement& draw(GLenum mode);
			
			ShapeElement& rectangle(double x, double y, double w, double h);
			ShapeElement& regularPolygon(int n, double r);
			ShapeElement& circle(double r);
			
		private:
			std::array<double, 4> nowColor_;
			std::array<double, 4> nowTexCoord_;
			
			std::vector<double> vertexes_;
			std::vector<double> colors_;
			std::vector<double> texCoords_;
			
			void push(std::vector<double>* v, std::array<double, 4> tp);
			
			static const double pi;
		};
	}
}
