#include "Object.h"

#define SHADERS_FILE_PATH "res/shader/Basic.shader"
#define TEXTURES_FILE_PATH "res/texture/Cleiton.jpg"

// TODO
void Object::SetPositionVertices(float* vertices, unsigned int* indices)
{
	m_mesh.SetVerticesProperties(vertices, indices);
}

void Object::DefineProperties() {

	m_mesh.m_VAO = std::make_unique<VertexArray>();
	m_mesh.m_VBO = std::make_unique<VertexBuffer>(m_mesh.m_vertices, 4 * 4 * sizeof(float));
	VertexBufferLayout layout;
	layout.Push<float>(2); // Coords
	layout.Push<float>(2); // ?? Local coords?
	m_mesh.m_VAO->AddBuffer(*m_mesh.m_VBO, layout);
	m_mesh.m_IBO = std::make_unique<IndexBuffer>(m_mesh.m_indices, 6);

	GLCall(glEnable(GL_BLEND));
	GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

	SetShader(SHADERS_FILE_PATH);

	//m_shader->SetUniform4f("u_color", 0.8f, 0.3f, 0.8f, 1.0f);


	SetTexture(TEXTURES_FILE_PATH);

	m_shader->SetUniform1i("u_texture", 0);
}


void Object::SetShader(std::string shader_path) {
	m_shader = std::make_unique<Shader>(shader_path);
	m_shader->Bind();
}

void Object::SetTexture(std::string texture_path) {
	m_texture = std::make_unique<Texture>(texture_path);
	m_texture->Bind();
}

void Object::MoveUp()
{
	m_translation = glm::vec3(0.0f, m_speed, 0.0f) + m_translation;
}

void Object::MoveDown()
{
	m_translation = glm::vec3(0.0f, -m_speed, 0.0f) + m_translation;
}

void Object::MoveLeft()
{
	m_translation = glm::vec3(-m_speed, 0.0f, 0.0f) + m_translation;
}

void Object::MoveRight()
{
	m_translation = glm::vec3(m_speed, 0.0f, 0.0f) + m_translation;
}

void Object::SetSpeed(float speed) {
	m_speed = speed;
}

void Object::Move() {
	// Setup projection matrix
	m_proj = glm::ortho(0.0f, 640.0f, 0.0f, 480.0f, -1.0f, 1.0f);

	// Setup view matrix
	m_view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));

	// Setup model matrix
	glm::mat4 model = glm::translate(glm::mat4(1.0f), m_translation);

	// Set mvp matrix
	glm::mat4 mvp = m_proj * m_view * model;

	m_shader->SetUniformMat4f("u_mvp", mvp);
}

void Object::Draw(Renderer renderer)
{
	renderer.Draw(m_mesh);
}
