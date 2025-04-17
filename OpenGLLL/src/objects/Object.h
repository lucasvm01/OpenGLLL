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
	Object() : 
		m_shader(nullptr), m_texture(nullptr), m_facing_angles(glm::vec3(1.0f)),
		m_rotate_x(false), m_rotate_y(false), m_rotate_z(false),
		m_proj(glm::ortho(0.0f, 640.0f, 0.0f, 480.0f, -1.0f, 1.0f)),
		m_view(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0))) {}

	virtual void SetPositionVertices(glm::vec3* vertices, unsigned int* indices) = 0; // GetObject() from file?
	virtual void DefineProperties() = 0;

	void SetShader(std::string shader_path);
	void SetTexture(std::string texture_path);

	inline void SetSpeed(float speed) { m_speed = speed; }

	// Translation
	virtual void TranslatePositiveY();
	virtual void TranslateNegativeY();

	virtual void TranslatePositiveX();
	virtual void TranslateNegativeX();

	virtual void TranslatePositiveZ();
	virtual void TranslateNegativeZ();

	// Rotation
	virtual void RotatePositiveX(float step);
	virtual void RotateNegativeX(float step);

	virtual void RotatePositiveY(float step);
	virtual void RotateNegativeY(float step);
	
	virtual void RotatePositiveZ(float step);
	virtual void RotateNegativeZ(float step);


	// Set rotations
	inline void SetRotationX()  { m_rotate_x = true; }
	inline void StopRotationX() { m_rotate_x = false; }

	inline void SetRotationY()  { m_rotate_y = true; }
	inline void StopRotationY() { m_rotate_y = false; }

	inline void SetRotationZ()  { m_rotate_z = true; }
	inline void StopRotationZ() { m_rotate_z = false; }

	virtual void Move() = 0;
	virtual void Rotate(float time);

	void Draw(Renderer renderer);

	Mesh m_mesh;

	std::unique_ptr<Shader> m_shader;
	std::unique_ptr<Texture> m_texture;

	glm::vec3 m_translation;
	float m_speed;

	bool m_rotate_x;
	bool m_rotate_y;
	bool m_rotate_z;

	glm::vec3 m_facing_angles;

	glm::mat4 m_proj;
	glm::mat4 m_view;
	glm::mat4 m_rotation;
};