#ifndef TEXTURE_H
#define TEXTURE_H

#include <glew\glew.h>

namespace GE
{
	class Texture
	{
	public:
		Texture(unsigned char* data, unsigned int width, unsigned int height, GLenum channels = GL_RGBA, GLenum filter = GL_LINEAR);
		~Texture();
		
		void Bind(GLuint unit);
		
	private:
		GLuint m_texture;
	};
}

#endif