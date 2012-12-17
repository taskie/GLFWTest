#pragma once

#include <vector>
#include <array>

#include "GLHeader.h"
#include "Color.h"

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
			ShapeElement& color(Color color);
			ShapeElement& texCoord(double s, double t = 0.0, double r = 0.0, double q = 1.0);
			ShapeElement& setColorForce(Color color);
			
			enum DrawMode
			{
				Point = GL_POINT,
				Lines = GL_LINES,
				LineLoop = GL_LINE_LOOP,
				LineStrip = GL_LINE_STRIP,
				Triangles = GL_TRIANGLES,
				TriangleStrip = GL_TRIANGLE_STRIP,
				PolyGon = GL_POLYGON
			};
			
			ShapeElement& draw(DrawMode mode);
			
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
