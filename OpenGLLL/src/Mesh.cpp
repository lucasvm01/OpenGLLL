#include "Mesh.h"

void Mesh::SetVerticesProperties(float* vertices, unsigned int* indices) {
	// Vertices
	m_vertices = vertices;
	m_indices = indices;
}