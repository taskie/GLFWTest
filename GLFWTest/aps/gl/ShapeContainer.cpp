#include "ShapeContainer.h"

#include <cassert>

using namespace aps::gl;

ShapeContainer::ShapeContainer()
: ShapeContainer(ShapeElement(), GL_POINTS)
{
	
}

ShapeContainer::ShapeContainer(ShapeElement shapeElement, GLenum mode)
: mode_(mode)
, anchor_({0, 0, 0})
, position_({0, 0, 0})
, scale_({1, 1, 1})
, rotate_({0, 0, 0, 1})
{
	shapeElement_.reset(new ShapeElement(shapeElement));
}

ShapeElement* ShapeContainer::operator->()
{
	assert(shapeElement_ != nullptr);
	return shapeElement_.get();
}

ShapeContainer& ShapeContainer::setMode(GLenum mode)
{
	mode_ = mode;
	return *this;
}

ShapeContainer& ShapeContainer::setAnchor(double x, double y, double z)
{
	anchor_ = std::array<double, 3>({x, y, z});
	return *this;
}

ShapeContainer& ShapeContainer::setPosition(double x, double y, double z)
{
	position_ = std::array<double, 3>({x, y, z});
	return *this;
}

ShapeContainer& ShapeContainer::setScale(double scale)
{
	scale_ = std::array<double, 3>({scale, scale, scale});
	return *this;
}

ShapeContainer& ShapeContainer::setScale(double x, double y, double z)
{
	scale_ = std::array<double, 3>({x, y, z});
	return *this;
}

ShapeContainer& ShapeContainer::setRotate(double angle, double x, double y, double z)
{
	rotate_ = std::array<double, 4>({angle, x, y, z});
	return *this;
}

GLenum ShapeContainer::mode() { return mode_; }
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
	
	std::tie(x, y, z) = position_;
	glTranslated(x, y, z);
	
	std::tie(x, y, z) = anchor_;
	glTranslated(x, y, z);
	
	std::tie(angle, x, y, z) = rotate_;
	glRotated(angle, x, y, z);
	
	std::tie(x, y, z) = scale_;
	glScaled(x, y, z);
	
	std::tie(x, y, z) = anchor_;
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
	std::array<double, 4> color = {1, 1, 1, 1};
	return rectWithTexture(texture, color);
}

ShapeContainer ShapeContainer::rectWithTexture(aps::gl::Texture2D texture, std::array<double, 4> color)
{
	auto elem = ShapeElement();
	elem.color(color[0], color[1], color[2], color[3])
	.texCoord(0, 0).vertex(0, 0).texCoord(1, 0).vertex(1, 0)
	.texCoord(1, 1).vertex(1, 1).texCoord(0, 1).vertex(0, 1);
	
	auto shape = ShapeContainer(elem, GL_QUADS);
	shape.setTexture(texture);
	shape.setScale(texture.width(), texture.height());
	
	return shape;
}