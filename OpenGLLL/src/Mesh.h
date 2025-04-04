#pragma once

#include <memory>

#include"IndexBuffer.h"
#include"VertexArray.h"
#include <glm/ext/vector_float3.hpp>

class Mesh {
public:
public:
	void SetVerticesProperties(glm::vec3* vertices, unsigned int* indices);

	glm::vec3* m_vertices;
	unsigned int* m_indices;

	std::unique_ptr<VertexArray> m_VAO;
	std::unique_ptr<VertexBuffer> m_VBO;
	std::unique_ptr<IndexBuffer> m_IBO;


	// void SetUniformMat4f(const std::string& name, glm::mat4 mvp);
	// void SetMPV ???

};