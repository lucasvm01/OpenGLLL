#include "Object.h"

void Object::SetShader(std::string shader_path) {
	m_shader = std::make_unique<Shader>(shader_path);
	m_shader->Bind();
}

void Object::SetTexture(std::string texture_path) {
	m_texture = std::make_unique<Texture>(texture_path);
	m_texture->Bind();
}

void Object::MovementPositiveY() {
	m_translation = glm::vec3(0.0f, m_speed, 0.0f) + m_translation;
}

void Object::MovementNegativeY() {
	m_translation = glm::vec3(0.0f, -m_speed, 0.0f) + m_translation;
}

void Object::MovementPositiveX() {
	m_translation = glm::vec3(m_speed, 0.0f, 0.0f) + m_translation;
}

void Object::MovementNegativeX() {
	m_translation = glm::vec3(-m_speed, 0.0f, 0.0f) + m_translation;
}

void Object::MovementPositiveZ() {
	m_translation = glm::vec3(0.0f, 0.0f, m_speed) + m_translation;
}

void Object::MovementNegativeZ() {
	m_translation = glm::vec3(0.0f, 0.0f,-m_speed) + m_translation;
}


void Object::SetSpeed(float speed) {
	m_speed = speed;
}


void Object::Draw(Renderer renderer)
{
	renderer.Draw(m_mesh);
}