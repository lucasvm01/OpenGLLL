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
	virtual void DefineProperties() = 0;

	void SetShader(std::string shader_path);
	void SetTexture(std::string texture_path);

	// Translation
	virtual void TranslatePositiveY();
	virtual void TranslateNegativeY();

	virtual void TranslatePositiveX();
	virtual void TranslateNegativeX();

	virtual void TranslatePositiveZ();
	virtual void TranslateNegativeZ();

	// Rotation
	virtual void RotatePositiveX();
	virtual void RotateNegativeX();

	virtual void RotatePositiveY();
	virtual void RotateNegativeY();
	
	virtual void RotatePositiveZ();
	virtual void RotateNegativeZ();

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