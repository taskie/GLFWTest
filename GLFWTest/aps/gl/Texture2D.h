#pragma once

#include <memory>
#include <unordered_map>

#include "GLHeader.h"

namespace aps
{
	namespace gl
	{
		class Texture2D
		{
		public:
			Texture2D(GLuint textureId, GLuint rawWidth, GLuint rawHeight, GLuint width, GLuint height);
			Texture2D(GLuint rawWidth, GLuint rawHeight, GLuint width, GLuint height);
			~Texture2D();
			
			GLuint rawWidth();
			GLuint rawHeight();
			GLuint width();
			GLuint height();
			
			Texture2D& bind();
			Texture2D& unbind();
			
			Texture2D& image2D(GLenum target, GLint level, GLint internalFormat,
								 GLenum format, GLenum type, const GLvoid* data);
			Texture2D& parameter(GLenum key, GLenum value);
			Texture2D& parameter(std::unordered_map<GLenum, GLenum> parameter);
			
			static Texture2D fromData(const GLubyte data[], int width, int height);
			
		private:
			std::shared_ptr<GLuint> textureId_;
			
			GLuint rawWidth_, rawHeight_;
			GLuint width_, height_;
		};
	}
}