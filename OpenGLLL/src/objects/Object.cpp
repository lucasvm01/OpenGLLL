#include "Object.h"

void Object::SetShader(std::string shader_path) {
	m_shader = std::make_unique<Shader>(shader_path);
	m_shader->Bind();
}

void Object::SetTexture(std::string texture_path) {
	m_texture = std::make_unique<Texture>(texture_path);
	m_texture->Bind();
}


void Object::SetSpeed(float speed) {
	m_speed = speed;
}


void Object::Draw(Renderer renderer)
{
	renderer.Draw(m_mesh);
}