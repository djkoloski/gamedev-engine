#include <rendering/Shader.h>
#include <fstream>
#include <iostream>
#include <vector>
namespace GE
{
	static void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
	static GLuint createShader(const std::string& text, GLenum shaderType);

	Shader::Shader(const char *vertexShader, const char *fragmentShader)
	{
		std::vector<std::string> attributes;
		std::vector<std::string> uniforms;
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
			
			else if(line.size() > pos + 8 && line.substr(pos, 8) == "uniform ")
			{
				pos = line.find_first_of(' ', pos + 7);
				pos = line.find_first_not_of(' ', pos);
				std::string uniform;
				pos = line.find(' ',pos) + 1;
				uniform = line.substr(pos, line.find_first_of(" ;\t\n",pos) - pos);
				uniforms.push_back(uniform);
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
			int pos = line.find_first_not_of(" \t");
			if(line.size() > pos + 8 && line.substr(pos, 8) == "uniform ")
			{
				pos = line.find_first_of(' ', pos + 7);
				pos = line.find_first_not_of(' ', pos);
				std::string uniform;
				pos = line.find(' ',pos) + 1;
				uniform = line.substr(pos, line.find_first_of(" ;\t\n",pos) - pos);
				uniforms.push_back(uniform);
			}
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
		
		for(int i = 0; i < uniforms.size(); ++i)
		{
			AddUniform(uniforms[i]);
		}
		
		for(int i = 0; i < NUM_SHADERS; ++i)
		{
			glDeleteShader(m_shaders[i]);
		}
	}

	Shader::~Shader()
	{
		for(unsigned int i = 0; i < NUM_SHADERS; ++i)
		{
			glDetachShader(m_program, m_shaders[i]);
		}
		glDeleteProgram(m_program);
	}

	void Shader::Bind()
	{
		glUseProgram(m_program);
	}
	
	void Shader::AddUniform(const std::string& uniformName)
	{
		GLint loc = glGetUniformLocation(m_program, uniformName.c_str());
		if (loc == -1) return;
		
		m_uniforms[std::string(uniformName)] = loc;
	}
	
	void Shader::UpdateUniform(const std::string& uniformName, int value)
	{
		glUniform1i(m_uniforms[uniformName], value);
	}
	void Shader::UpdateUniform(const std::string& uniformName, float value)
	{
		glUniform1f(m_uniforms[uniformName], value);
	}
	void Shader::UpdateUniform(const std::string& uniformName, int* values, unsigned int size)
	{
		switch (size)
		{
		case 1:
			glUniform1iv(m_uniforms[uniformName], 1, values);
			break;
		
		case 2:
			glUniform2iv(m_uniforms[uniformName], 1, values);
			break;
		
		case 3:
			glUniform3iv(m_uniforms[uniformName], 1, values);
			break;
		
		case 4:
			glUniform4iv(m_uniforms[uniformName], 1, values);
			break;
		
		default:
			glUniform1iv(m_uniforms[uniformName], size, values);
			break;
		}
	}
	void Shader::UpdateUniform(const std::string& uniformName, float* values, unsigned int size)
	{
		switch (size)
		{
		case 1:
			glUniform1fv(m_uniforms[uniformName], 1, values);
			break;
		
		case 2:
			glUniform2fv(m_uniforms[uniformName], 1, values);
			break;
		
		case 3:
			glUniform3fv(m_uniforms[uniformName], 1, values);
			break;
		
		case 4:
			glUniform4fv(m_uniforms[uniformName], 1, values);
			break;
		
		default:
			glUniform1fv(m_uniforms[uniformName], size, values);
			break;
		}
	}
	void Shader::UpdateUniform(const std::string& uniformName, const GE::Math::Vector2& value)
	{
		glUniform2f(m_uniforms[uniformName], value.x, value.y);
	}
	void Shader::UpdateUniform(const std::string& uniformName, const GE::Math::Vector3& value)
	{
		glUniform3f(m_uniforms[uniformName], value.x, value.y, value.z);
	}
	void Shader::UpdateUniform(const std::string& uniformName, const GE::Math::Vector4& value)
	{
		glUniform4f(m_uniforms[uniformName], value.x, value.y, value.z, value.w);
	}
	void Shader::UpdateUniform(const std::string& uniformName, const GE::Math::Matrix2& value)
	{
		glUniformMatrix2fv(m_uniforms[uniformName], 1, false, value.d1);
	}
	void Shader::UpdateUniform(const std::string& uniformName, const GE::Math::Matrix3& value)
	{
		glUniformMatrix3fv(m_uniforms[uniformName], 1, false, value.d1);
	}
	void Shader::UpdateUniform(const std::string& uniformName, const GE::Math::Matrix4& value)
	{
		glUniformMatrix4fv(m_uniforms[uniformName], 1, false, value.d1);
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