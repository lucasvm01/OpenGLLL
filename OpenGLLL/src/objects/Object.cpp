#include "Object.h"

void Object::SetShader(std::string shader_path) {
	m_shader = std::make_unique<Shader>(shader_path);
	m_shader->Bind();
}

void Object::SetTexture(std::string texture_path) {
	m_texture = std::make_unique<Texture>(texture_path);
	m_texture->Bind();
}

// Translation
void Object::TranslatePositiveY() {
	m_translation = glm::vec3(0.0f, m_speed, 0.0f) + m_translation;
}

void Object::TranslateNegativeY() {
	m_translation = glm::vec3(0.0f, -m_speed, 0.0f) + m_translation;
}

void Object::TranslatePositiveX() {
	m_translation = glm::vec3(m_speed, 0.0f, 0.0f) + m_translation;
}

void Object::TranslateNegativeX() {
	m_translation = glm::vec3(-m_speed, 0.0f, 0.0f) + m_translation;
}

void Object::TranslatePositiveZ() {
	m_translation = glm::vec3(0.0f, 0.0f, m_speed) + m_translation;
}

void Object::TranslateNegativeZ() {
	m_translation = glm::vec3(0.0f, 0.0f,-m_speed) + m_translation;
}

// Rotation
void Object::RotatePositiveX(float step) {
	m_facing_angles.x += step;
}

void Object::RotateNegativeX(float step) {
	m_facing_angles.x += step;
}

void Object::RotatePositiveY(float step) {
	m_facing_angles.x += step;
}

void Object::RotateNegativeY(float step) {
	m_facing_angles.x += step;
}

void Object::RotatePositiveZ(float step) {
	m_facing_angles.x += step;
}

void Object::RotateNegativeZ(float step) {
	m_facing_angles.x += step;
}


void Object::Rotate(float time) {
	glm::mat4 rotationZ = glm::mat4(1);
	glm::mat4 rotationX = glm::mat4(1);
	glm::mat4 rotationY = glm::mat4(1);

	// Rotation in Z
	if (m_rotate_z)
	rotationZ = glm::mat4(
		glm::cos(time),-glm::sin(time), 0, 0,
		glm::sin(time), glm::cos(time), 0, 0,
		0,			    0,				1, 0,
		0,				0,				0, 1
	);
	
	// Rotation in X
	if(m_rotate_x)
	rotationX = glm::mat4(
		1,			    0,				0, 0,
		0, glm::cos(time),-glm::sin(time), 0,
		0, glm::sin(time), glm::cos(time), 0,
		0,				0,				0, 1
	);

	// Rotation in Y
	if(m_rotate_y)
	rotationY = glm::mat4(
		glm::cos(time), 0,-glm::sin(time), 0,
		0,			    1,				0, 0,
		glm::sin(time), 0, glm::cos(time), 0,
		0,				0,				0, 1
	);
	
	m_rotation = rotationX * rotationY * rotationZ;
}

void Object::Draw(Renderer renderer)
{
	renderer.Draw(m_mesh);
}