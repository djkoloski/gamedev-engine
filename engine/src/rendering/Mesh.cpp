#include <rendering/Mesh.h>

namespace GE
{
	Mesh::Mesh(GE::Math::Vector3 *vertices, unsigned int numVertices, unsigned int *indices, unsigned int numIndices)
	{
		m_drawCount = numIndices;
		glGenVertexArrays(1, &m_vertexArrayObject);
		glBindVertexArray(m_vertexArrayObject);
		
		glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
		glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[VERTEX_DATA]);
		glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(GE::Math::Vector3), vertices, GL_STATIC_DRAW);
		
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, false, 0, 0);
		
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vertexArrayBuffers[INDICES]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, numIndices * sizeof(GLuint), indices, GL_STATIC_DRAW);
		
		glBindVertexArray(0);
	}

	Mesh::~Mesh()
	{
		glDeleteBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
		glDeleteVertexArrays(1, &m_vertexArrayObject);
	}

	void Mesh::Draw()
	{
		glBindVertexArray(m_vertexArrayObject);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vertexArrayBuffers[INDICES]);
		glDrawElements(GL_TRIANGLES, m_drawCount, GL_UNSIGNED_INT, 0);
	}
}