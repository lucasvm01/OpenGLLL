#pragma once

#include<iostream>
#include <memory>
#include <string>
#include <vector>

#include"glm/glm.hpp"
#include"glm/gtc/matrix_transform.hpp"

#include "../Texture.h"
#include "../Shader.h"
#include "../Renderer.h"

#include "../VertexBufferLayout.h"

class Object {
public:
	Object() : m_shader(nullptr), m_texture(nullptr) {}

	virtual void SetPositionVertices(glm::vec3* vertices, unsigned int* indices) = 0; // GetObject() from file?
	virtual void DefineProperties() = 0;

	void SetShader(std::string shader_path);
	void SetTexture(std::string texture_path);

	virtual void MoveUp() = 0;
	virtual void MoveDown() = 0;
	virtual void MoveLeft() = 0;
	virtual void MoveRight() = 0;
	void SetSpeed(float speed);

	virtual void Move() = 0;

	void Draw(Renderer renderer);

	Mesh m_mesh;

	std::unique_ptr<Shader> m_shader;
	std::unique_ptr<Texture> m_texture;

	glm::vec3 m_translation;
	float m_speed;

	glm::mat4 m_proj;
	glm::mat4 m_view;
};