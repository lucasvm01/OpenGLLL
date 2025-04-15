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
	Object() : m_shader(nullptr), m_texture(nullptr),
		m_proj(glm::ortho(0.0f, 640.0f, 0.0f, 480.0f, -1.0f, 1.0f)),
		m_view(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0))) {}

	virtual void SetPositionVertices(glm::vec3* vertices, unsigned int* indices) = 0; // GetObject() from file?
	virtual void DefineProperties(int op) = 0;

	void SetShader(std::string shader_path);
	void SetTexture(std::string texture_path);

	// Translation
	virtual void MovementPositiveY();
	virtual void MovementNegativeY();

	virtual void MovementPositiveX();
	virtual void MovementNegativeX();

	virtual void MovementPositiveZ();
	virtual void MovementNegativeZ();

	// Rotation
	virtual void RotationPositiveX() = 0;
	virtual void RotationNegativeX() = 0;

	virtual void RotationPositiveY() = 0;
	virtual void RotationNegativeY() = 0;
	
	virtual void RotationPositiveZ() = 0;
	virtual void RotationNegativeZ() = 0;

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
	glm::mat4 m_rotation;
};