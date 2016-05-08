#include <rendering/Texture.h>
#include <cassert>

namespace GE
{
	Texture::Texture(unsigned char* data, unsigned int width, unsigned int height, GLenum channels, GLenum filter)
	{
		glGenTextures(1, &m_texture);
		glBindTexture(GL_TEXTURE_2D, m_texture);
		
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
	
		glTexImage2D(GL_TEXTURE_2D, 0, channels, width, height, 0, channels, GL_UNSIGNED_BYTE, data);
	}
	
	Texture::~Texture()
	{
		glDeleteTextures(1, &m_texture);
	}
	
	void Texture::Bind(GLuint unit)
	{
		assert(unit < 32);
		
		glActiveTexture(GL_TEXTURE0 + unit);
		glBindTexture(GL_TEXTURE_2D, m_texture);
	}
}