#pragma once

#include<iostream>
#include <memory>
#include <string>
#include <vector>


#include "VertexArray.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"
#include "Shader.h"
#include "Texture.h"

#include"glm/glm.hpp"
#include"glm/gtc/matrix_transform.hpp"

class Object {
public:

	void SetPositionVertices(float* vertices, unsigned int* indices); // GetObject() from file?
	void DefineProperties();

	void SetShader(std::string shader_path);
	void SetTexture(std::string texture_path);
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

	void SetSpeed(float speed);

	void Move();

	void Draw(Renderer renderer);

	Mesh m_mesh;

	std::unique_ptr<Shader> m_shader;
	std::unique_ptr<Texture> m_texture;

	glm::vec3 m_translation;
	float m_speed;
	glm::mat4 m_proj;
	glm::mat4 m_view;
private:
};