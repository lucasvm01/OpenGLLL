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
	virtual void DefineProperties(std::string shader_path, std::string texture_path) = 0;

	void SetShader(std::string shader_path);
	void SetTexture(std::string texture_path);

	virtual void MovementUp() = 0;
	virtual void MovementDown() = 0;
	virtual void MovementLeft() = 0;
	virtual void MovementRight() = 0;
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