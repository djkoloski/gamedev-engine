#include <rendering/Shader.h>
#include <fstream>
#include <string>
#include <vector>
namespace GE
{
	static GLuint createShader(const std::string& text, GLenum shaderType);

	Shader::Shader(const char *vertexShader, const char *fragmentShader)
	{
		std::vector<std::string> attributes;
		m_program = glCreateProgram();
		
		std::string vertShader;
		std::string fragShader;
		std::ifstream vertexSrc;
		std::ifstream fragSrc;
		vertexSrc.open(vertexShader);
		while(vertexSrc.good())
		{
			std::string line;
			getline(vertexSrc, line);
			int pos = line.find_first_not_of(" \t");
			if(line[pos] == 'i' && line[pos+1] == 'n' && line[pos+2] == ' ')
			{
				pos = line.find_first_of(' ', pos + 2);
				pos = line.find_first_not_of(' ', pos);
				std::string attrib;
				attrib = line.substr(pos, line.find_first_of(" ;\t\n")-pos);
				attributes.push_back(attrib);
			}
			line += '\n';
			vertShader += line;		
		}
		
		while(fragSrc.good())
		{
			std::string line;
			getline(fragSrc, line);
			line += '\n';
			fragShader += line;
		}
		
		createShader(vertShader, GL_VERTEX_SHADER);
		createShader(fragShader, GL_FRAGMENT_SHADER);
		
		for(unsigned int i = 0; i < NUM_SHADERS; ++i)
		{
			glAttachShader(m_program, m_shaders[i]);
		}
		
		for(unsigned int i = 0; i < attributes.size(); ++i)
		{
			glBindAttribLocation(m_program, i, attributes[i].c_str()); 
		}
		
		glLinkProgram(m_program);
		glValidateProgram(m_program);
	}

	Shader::~Shader()
	{
		for(unsigned int i = 0; i < NUM_SHADERS; ++i)
		{
			glDetachShader(m_program, m_shaders[i]);
			glDeleteShader(m_shaders[i]);
		}
		glDeleteProgram(m_program);
	}

	void Shader::Bind()
	{
		glUseProgram(m_program);
	}

	static GLuint createShader(const std::string& text, GLenum shaderType)
	{
		GLuint shader = glCreateShader(shaderType);
		
		const GLchar* p[1];
		GLint pLengths[1];	
		p[0] = text.c_str();
		pLengths[0] = text.size();
		
		glShaderSource(shader, 1, p, pLengths);
		glCompileShader(shader);
		
		return shader;
	}
}