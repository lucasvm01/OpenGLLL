#pragma once

#include<iostream>
#include <memory>
#include <string>
#include <vector>

#include"glm/glm.hpp"
#include"glm/gtc/matrix_transform.hpp"

#include "Texture.h"
#include "Shader.h"
#include "IndexBuffer.h"
#include "VertexArray.h"

#include"VertexBufferLayout.h"

class Mesh {
public:
	void SetPositionVertices(float* data);

	void ProcessVertices();

	void SetShader(std::string shader_path);
	void SetTexture(std::string texture_path);

	int HandleInput(std::vector<int> keys);

	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

	void SetSpeed(float speed);

	void Move();

	glm::vec3 m_translation;
	float m_speed;
	glm::mat4 m_proj;
	glm::mat4 m_view;
		
	std::unique_ptr<Shader> m_shader;
	std::unique_ptr<Texture> m_texture;

	std::unique_ptr<VertexArray> m_VAO;
	std::unique_ptr<VertexBuffer> m_VBO;
	std::unique_ptr<IndexBuffer> m_IBO;
	// void SetUniformMat4f(const std::string& name, glm::mat4 mvp);
	// void SetMPV ???

private:
	float* m_pos;
	unsigned int* m_indices;
};