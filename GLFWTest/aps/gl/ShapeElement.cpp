#include "ShapeElement.h"

#include <algorithm>
#include <cmath>
#include <boost/foreach.hpp>

using namespace aps::gl;

// class ShapeElement
// public:

ShapeElement::ShapeElement()
: nowColor_{{0, 0, 0, 1}}
, nowTexCoord_{{0, 0, 0, 1}}
{ }

ShapeElement& ShapeElement::vertex(double x, double y, double z, double w)
{
	std::array<double, 4> v{{x, y, z, w}};
	push(&vertexes_, v);
	push(&colors_, nowColor_);
	push(&texCoords_, nowTexCoord_);
	return *this;
}

ShapeElement& ShapeElement::color(double r, double g, double b, double a)
{
	nowColor_ = std::array<double, 4>{{r, g, b, a}};
	return *this;
}

ShapeElement& ShapeElement::color(Color color)
{
	nowColor_ = std::array<double, 4>{{color.r(), color.g(), color.b(), color.a()}};
	return *this;
}

ShapeElement& ShapeElement::texCoord(double s, double t, double r, double q)
{
	nowTexCoord_ = std::array<double, 4>{{s, t, r, q}};
	return *this;
}

ShapeElement& ShapeElement::setColorForce(aps::gl::Color color)
{
	for (std::size_t i = 0; i < colors_.size(); ++i)
	{
		colors_.at(i) = color[i % 4];
	}
	return *this;
}

/** 長方形を作る。
 * @param x, y : 左上の座標
 * @param w : 幅
 * @param h : 高さ
 */
ShapeElement& ShapeElement::rectangle(double x, double y, double w, double h)
{
	vertex(x, y).vertex(x + w, y).vertex(x + w, y + h).vertex(x, y + h);
	return *this;
}

/** 正多角形を作る。
 * @param n : 角の数
 * @param r : 外接円の半径
 */
ShapeElement& ShapeElement::regularPolygon(int n, double r)
{
	for (int i = 0; i < n; i++) {
		double x = r * std::cos(pi * 2 * i / n);
		double y = r * std::sin(pi * 2 * i / n);
		vertex(x, y);
	}
	return *this;

}

/** 円を作る。
 * @param r : 半径
 */
ShapeElement& ShapeElement::circle(double r)
{
	int n = static_cast<int>(std::ceil(2 * pi / std::asin(1/(std::sqrt(r)))));
	regularPolygon(n, r);
	return *this;

}

// class ShapeElement
// private:

void ShapeElement::push(std::vector<double>* v, std::array<double, 4> tp)
{
	for (double x : tp) v->push_back(x);
}

ShapeElement& ShapeElement::draw(ShapeElement::DrawMode mode)
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	
	glVertexPointer(4, GL_DOUBLE, 0, &vertexes_[0]);
	glColorPointer(4, GL_DOUBLE, 0, &colors_[0]);
	glTexCoordPointer(4, GL_DOUBLE, 0, &texCoords_[0]);
	
	glDrawArrays(static_cast<GLenum>(mode), 0, static_cast<GLsizei>(vertexes_.size()) / 4);
	
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	
	return *this;
}

// class ShapeElement
// private:

/// 円周率。
const double ShapeElement::pi = 3.141592653589793238;