#include <rendering/Shader.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
namespace GE
{
	static void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
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
				pos = line.find(' ',pos) + 1;
				attrib = line.substr(pos, line.find_first_of(" ;\t\n",pos) - pos);
				attributes.push_back(attrib);
			}
			line += '\n';
			vertShader += line;		
		}
		vertexSrc.close();
		fragSrc.open(fragmentShader);
		
		while(fragSrc.good())
		{
			std::string line;
			getline(fragSrc, line);
			line += '\n';
			fragShader += line;
		}
		fragSrc.close();
		
		m_shaders[0] = createShader(vertShader, GL_VERTEX_SHADER);
		m_shaders[1] = createShader(fragShader, GL_FRAGMENT_SHADER);
		
		for(unsigned int i = 0; i < NUM_SHADERS; ++i)
		{
			glAttachShader(m_program, m_shaders[i]);
		}
		
		for(unsigned int i = 0; i < attributes.size(); ++i)
		{
			glBindAttribLocation(m_program, i, attributes[i].c_str()); 
		}
		
		glLinkProgram(m_program);
		checkShaderError(m_program, GL_LINK_STATUS, true, "Error: Program linking failed: ");
		glValidateProgram(m_program);
		checkShaderError(m_program, GL_VALIDATE_STATUS, true, "Error: Program is invalid: ");
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
		
		checkShaderError(shader, GL_COMPILE_STATUS, false, "Error: Shader compilation failed: ");
		
		return shader;
	}
	
	static void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
	{
		GLint success = 0;
		GLchar error[1024] = { 0 };

		if (isProgram)
		{
			glGetProgramiv(shader, flag, &success);
		}
		else
		{
			glGetShaderiv(shader, flag, &success);
		}

		if (success == GL_FALSE)
		{
			if (isProgram)
			{
				glGetProgramInfoLog(shader, sizeof(error), NULL, error);
			}
			else
			{
				glGetShaderInfoLog(shader, sizeof(error), NULL, error);
			}
			std::cerr << errorMessage << ": '" << error << "'" << std::endl;
		}
}
}