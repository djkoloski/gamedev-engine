#ifndef MESH_H
#define MESH_H

#include <glew/glew.h>
#include <math/Vector.hpp>
namespace GE
{
	class Mesh
	{
	public:
		Mesh(GE::Math::Vector3 *vertices, unsigned int numVertices, GE::Math::Vector2 *texCoords, unsigned int numTexCoords, unsigned int *indices, unsigned int numIndices);
		~Mesh();
		
		void Draw();
		
	private:
		enum  MeshBuffer
		{
			VERTEX_DATA,
			TEXCOORD_DATA,
			INDICES,
			
			NUM_BUFFERS
		};
		
		GLuint m_vertexArrayObject;
		GLuint m_vertexArrayBuffers[NUM_BUFFERS];

		GLuint m_drawCount;
	};
}
#endif //MESH_H