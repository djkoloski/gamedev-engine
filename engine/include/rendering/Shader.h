#ifndef SHADER_H
#define SHADER_H

#include <glew\glew.h>
#include <string>
#include <map>
#include <math\Vector.hpp>
#include <math\Matrix.hpp>

namespace GE
{
	class Shader
	{
	public:
		Shader(const char *vertexShader, const char *fragmentShader);
		~Shader();
		
		void Bind();
		
		void AddUniform(const std::string& uniformName);
		
		void UpdateUniform(const std::string& uniformName, int value);
		void UpdateUniform(const std::string& uniformName, float value);
		void UpdateUniform(const std::string& uniformName, int* values, unsigned int size);
		void UpdateUniform(const std::string& uniformName, float* values, unsigned int size);
		void UpdateUniform(const std::string& uniformName, const GE::Math::Vector2& value);
		void UpdateUniform(const std::string& uniformName, const GE::Math::Vector3& value);
		void UpdateUniform(const std::string& uniformName, const GE::Math::Vector4& value);
		void UpdateUniform(const std::string& uniformName, const GE::Math::Matrix2& value);
		void UpdateUniform(const std::string& uniformName, const GE::Math::Matrix3& value);
		void UpdateUniform(const std::string& uniformName, const GE::Math::Matrix4& value);
		
		
	private:
		enum ShaderType
		{
			VERTEX_SHADER,
			FRAGMENT_SHADER,
			
			NUM_SHADERS
		};
		
		GLuint m_program;
		GLuint m_shaders[NUM_SHADERS];
		
		std::map<std::string, GLint> m_uniforms;
		
	};
}
#endif //SHADER_H