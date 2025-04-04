#include "Mesh.h"

void Mesh::SetVerticesProperties(glm::vec3* vertices, unsigned int* indices) {
	// Vertices
	m_vertices = vertices;
	m_indices = indices;
}