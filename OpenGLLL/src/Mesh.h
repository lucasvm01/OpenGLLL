#pragma once

#include <memory>

#include"IndexBuffer.h"
#include"VertexArray.h"

class Mesh {
public:
public:
	void SetVerticesProperties(float* vertices, unsigned int* indices);

	float* m_vertices;
	unsigned int* m_indices;


	std::unique_ptr<VertexArray> m_VAO;
	std::unique_ptr<VertexBuffer> m_VBO;
	std::unique_ptr<IndexBuffer> m_IBO;


	// void SetUniformMat4f(const std::string& name, glm::mat4 mvp);
	// void SetMPV ???

};