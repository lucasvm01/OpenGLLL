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
void Object::RotatePositiveX() {
}

void Object::RotateNegativeX() {
}

void Object::RotatePositiveY() {
}

void Object::RotateNegativeY() {
}

void Object::RotatePositiveZ() {
}

void Object::RotateNegativeZ() {
}


void Object::SetSpeed(float speed) {
	m_speed = speed;
}


void Object::Draw(Renderer renderer)
{
	renderer.Draw(m_mesh);
}