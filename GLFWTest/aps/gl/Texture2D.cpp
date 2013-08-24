#include "Texture2D.h"

#include <algorithm>
#include <vector>

using namespace aps::gl;

// class Texture2D
// public:

static void Texture2DDeleter(GLuint* p)
{
	glDeleteTextures(1, p);
	delete p;
}

Texture2D::Texture2D(GLuint textureId,
						 GLuint rawWidth, GLuint rawHeight, GLuint width, GLuint height)
: rawWidth_(rawWidth), rawHeight_(rawHeight), width_(width), height_(height)
{
	textureId_.reset(new GLuint(textureId), Texture2DDeleter);
}

Texture2D::Texture2D(GLuint rawWidth, GLuint rawHeight, GLuint width, GLuint height)
: rawWidth_(rawWidth), rawHeight_(rawHeight), width_(width), height_(height)
{
	GLuint textureId;
	glGenTextures(1, &textureId);
	textureId_.reset(new GLuint(textureId), Texture2DDeleter);
}

Texture2D::~Texture2D()
{
	
}

GLuint Texture2D::rawWidth() { return rawWidth_; }

GLuint Texture2D::rawHeight() { return rawHeight_; }

GLuint Texture2D::width() { return width_; }

GLuint Texture2D::height() { return height_; }

Texture2D& Texture2D::bind()
{
	glBindTexture(GL_TEXTURE_2D, *textureId_);
	return *this;
}

Texture2D& Texture2D::unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
	return *this;
}

Texture2D& Texture2D::image2D(GLenum target, GLint level, GLint internalFormat,
								  GLenum format, GLenum type, const GLvoid* data)
{
	bind();
	glTexImage2D(target, level, internalFormat, width(), height(), 0, format, type, data);
	unbind();
	return *this;
}

Texture2D& Texture2D::parameter(GLenum key, GLenum value)
{
	bind();
	glTexParameteri(GL_TEXTURE_2D, key, value);
	unbind();
	return *this;
}

Texture2D& Texture2D::parameter(std::unordered_map<GLenum, GLenum> parameter)
{
	bind();
	for (auto pair : parameter)
	{
		glTexParameteri(GL_TEXTURE_2D, pair.first, pair.second);
	}
	unbind();
	return *this;
}

static int powOfTwo(int size)
{
	int value = 1;
	while (value < size) { value <<= 1; }
	return value;
}

Texture2D Texture2D::fromData(const GLubyte data[], int rawWidth, int rawHeight)
{
	if (rawWidth == 0 || rawHeight == 0) return Texture2D(0, 0, 0, 0);
	
	int width = powOfTwo(rawWidth);
	int height = powOfTwo(rawHeight);
	
	std::vector<GLubyte> dataEx(width * height * 4, 0);
	for (int y = 0; y < rawHeight; ++y)
	{
		for (int x = 0; x < rawWidth; ++x)
		{
			// RGBA
			for (int k = 0; k < 4; ++k)
			{
				dataEx[(y * width + x) * 4 + k] = data[(y * rawWidth + x) * 4 + k];
			}
		}
	}
	
	Texture2D texture(rawWidth, rawHeight, width, height);
	texture.image2D(GL_TEXTURE_2D, 0, GL_RGBA, GL_RGBA, GL_UNSIGNED_BYTE, dataEx.data());
	
	std::unordered_map<GLenum, GLenum> parameter = {
		{GL_TEXTURE_MAG_FILTER, GL_LINEAR}, {GL_TEXTURE_MIN_FILTER, GL_LINEAR}
	};
	texture.parameter(parameter);

	return texture;
}

