#include "Mesh.h"

void Mesh::SetPositionVertices(float* data) {
	// Vertices
	m_vertices = data;
}

void Mesh::ProcessVertices() {

	// Vertices
	float pos[] = {
		-50.0f, -50.0f, 0.0f, 0.0f,
		 50.0f, -50.0f, 1.0f, 0.0f,
		 50.0f,  50.0f, 1.0f, 1.0f,
		-50.0f,  50.0f, 0.0f, 1.0f
	};

	m_vertices = pos;

	// Indices of positions in order of drawing
	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	m_indices = indices;

}