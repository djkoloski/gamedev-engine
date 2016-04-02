#ifndef MESH_H
#define MESH_H

#include <glew/glew.h>
#include <math/Vector.hpp>
namespace GE
{
	class Mesh
	{
	public:
		Mesh(Vector3 *vertices, unsigned int numVertices, unsigned int *indices, unsigned int numIndices);
		~Mesh();
		
		void Draw();
		
	private:
		enum  MeshBuffer
		{
			VERTEX_DATA,
			INDICES,
			
			NUM_BUFFERS
		};
		
		GLuint m_vertexArrayObject;
		GLuint m_vertexArrayBuffers[NUM_BUFFERS];

		GLuint m_drawCount;
	};
}
#endif //MESH_H