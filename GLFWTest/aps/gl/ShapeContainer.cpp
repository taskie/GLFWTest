#include "ShapeContainer.h"

#include <cassert>

using namespace aps::gl;

ShapeContainer::ShapeContainer()
: ShapeContainer(ShapeElement(), ShapeElement::Point)
{
	
}

ShapeContainer::ShapeContainer(ShapeElement shapeElement)
: ShapeContainer(shapeElement, ShapeElement::Point)
{
	
}

ShapeContainer::ShapeContainer(ShapeElement shapeElement, ShapeElement::DrawMode mode)
: mode_(mode)
, anchor_{{0, 0, 0}}
, position_{{0, 0, 0}}
, scale_{{1, 1, 1}}
, rotate_{{0, 0, 0, 1}}
{
	shapeElement_.reset(new ShapeElement(shapeElement));
}

ShapeElement* ShapeContainer::operator->()
{
	assert(shapeElement_ != nullptr);
	return shapeElement_.get();
}

ShapeContainer& ShapeContainer::point() { return setMode(ShapeElement::Point); }
ShapeContainer& ShapeContainer::lines() { return setMode(ShapeElement::Lines); }
ShapeContainer& ShapeContainer::lineLoop() { return setMode(ShapeElement::LineLoop); }
ShapeContainer& ShapeContainer::lineStrip() { return setMode(ShapeElement::LineStrip); }
ShapeContainer& ShapeContainer::triangles() { return setMode(ShapeElement::Triangles); }
ShapeContainer& ShapeContainer::triangleStrip() { return setMode(ShapeElement::TriangleStrip); }
ShapeContainer& ShapeContainer::polygon() { return setMode(ShapeElement::PolyGon); }

ShapeContainer& ShapeContainer::setMode(ShapeElement::DrawMode mode)
{
	mode_ = mode;
	return *this;
}

ShapeContainer& ShapeContainer::setAnchor(double x, double y, double z)
{
	anchor_ = std::array<double, 3>{{x, y, z}};
	return *this;
}

ShapeContainer& ShapeContainer::setPosition(double x, double y, double z)
{
	position_ = std::array<double, 3>{{x, y, z}};
	return *this;
}

ShapeContainer& ShapeContainer::setScale(double scale)
{
	scale_ = std::array<double, 3>{{scale, scale, scale}};
	return *this;
}

ShapeContainer& ShapeContainer::setScale(double x, double y, double z)
{
	scale_ = std::array<double, 3>{{x, y, z}};
	return *this;
}

ShapeContainer& ShapeContainer::setRotate(double angle, double x, double y, double z)
{
	rotate_ = std::array<double, 4>{{angle, x, y, z}};
	return *this;
}

ShapeContainer& ShapeContainer::setColorForce(aps::gl::Color color)
{
	if (shapeElement_) shapeElement_->setColorForce(color);
	for (auto shape : children_) shape.setColorForce(color);
	return *this;
}

ShapeElement::DrawMode ShapeContainer::mode() { return mode_; }
std::array<double, 3> ShapeContainer::anchor() { return anchor_; }
std::array<double, 3> ShapeContainer::position() { return position_; }
std::array<double, 3> ShapeContainer::scale() { return scale_; }
std::array<double, 4> ShapeContainer::rotate() { return rotate_; }

void ShapeContainer::pushChild(aps::gl::ShapeContainer child)
{
	children_.push_back(child);
}

void ShapeContainer::setTexture(aps::gl::Texture2D texture)
{
	texture_ = std::make_shared<Texture2D>(texture);
}

void ShapeContainer::draw() const
{
	glMatrixMode(GL_MODELVIEW);
	
	glPushMatrix();
	
	double angle, x, y, z;
	
	x = position_[0];
	y = position_[1];
	z = position_[2];
	glTranslated(x, y, z);
	
	// std::tie(x, y, z) = anchor_;
	// glTranslated(x, y, z);
	
	angle = rotate_[0];
	x = rotate_[1];
	y = rotate_[2];
	z = rotate_[3];
	glRotated(angle, x, y, z);
	
	x = scale_[0];
	y = scale_[1];
	z = scale_[2];
	glScaled(x, y, z);
	
	x = anchor_[0];
	y = anchor_[1];
	z = anchor_[2];
	glTranslated(-x, -y, -z);
	
	if (texture_)
	{
		glEnable(GL_TEXTURE);
		texture_->bind();
	}
	
	shapeElement_->draw(mode_);
	
	if (texture_)
	{
		texture_->unbind();
		glDisable(GL_TEXTURE);
	}
	
	for (auto child : children_)
	{
		child.draw();
	}
	
	glPopMatrix();
}

ShapeContainer ShapeContainer::rectWithTexture(aps::gl::Texture2D texture)
{
	std::array<double, 4> color{{1, 1, 1, 1}};
	return rectWithTexture(texture, color);
}

ShapeContainer ShapeContainer::rectWithTexture(aps::gl::Texture2D texture, aps::gl::Color color)
{
	auto elem = ShapeElement();
	elem.color(color[0], color[1], color[2], color[3])
	.texCoord(0, 0).vertex(0, 0).texCoord(1, 0).vertex(1, 0)
	.texCoord(1, 1).vertex(1, 1).texCoord(0, 1).vertex(0, 1);
	
	auto shape = ShapeContainer(elem, ShapeElement::PolyGon);
	shape.setTexture(texture);
	shape.setScale(texture.width(), texture.height());
	
	return shape;
}