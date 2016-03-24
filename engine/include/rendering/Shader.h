#ifndef SHADER_H
#define SHADER_H

#include <glew\glew.h>

namespace GE
{
	class Shader
	{
	public:
		Shader(const char *vertexShader, const char *fragmentShader);
		~Shader();
		
		void Bind();
		
	private:
		enum ShaderType
		{
			VERTEX_SHADER,
			FRAGMENT_SHADER,
			
			NUM_SHADERS
		};
		
		GLuint m_program;
		GLuint m_shaders[NUM_SHADERS];
		
	};
}
#endif //SHADER_H