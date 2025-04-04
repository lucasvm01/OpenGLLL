#include "Square.h"

#define SHADERS_FILE_PATH "res/shader/Basic.shader"
#define TEXTURES_FILE_PATH "res/texture/Cleiton.jpg"

// TODO
void Square::SetPositionVertices(glm::vec3* vertices, unsigned int* indices)
{
	m_mesh.SetVerticesProperties(vertices, indices);
}

void Square::DefineProperties() {

	m_mesh.m_VAO = std::make_unique<VertexArray>();
	m_mesh.m_VBO = std::make_unique<VertexBuffer>(m_mesh.m_vertices, 4 * 2 * sizeof(glm::vec3)); 
	VertexBufferLayout layout;
	layout.Push<glm::vec3>(1); // Coords
	layout.Push<glm::vec3>(1); // ?? Local coords?
	m_mesh.m_VAO->AddBuffer(*m_mesh.m_VBO, layout);
	m_mesh.m_IBO = std::make_unique<IndexBuffer>(m_mesh.m_indices, 6);

	GLCall(glEnable(GL_BLEND));
	GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

	SetShader(SHADERS_FILE_PATH);

	//m_shader->SetUniform4f("u_color", 0.8f, 0.3f, 0.8f, 1.0f);


	SetTexture(TEXTURES_FILE_PATH);

	m_shader->SetUniform1i("u_texture", 0);
}

void Square::MoveUp()
{
	m_translation = glm::vec3(0.0f, m_speed, 0.0f) + m_translation;
}

void Square::MoveDown()
{
	m_translation = glm::vec3(0.0f, -m_speed, 0.0f) + m_translation;
}

void Square::MoveLeft()
{
	m_translation = glm::vec3(-m_speed, 0.0f, 0.0f) + m_translation;
}

void Square::MoveRight()
{
	m_translation = glm::vec3(m_speed, 0.0f, 0.0f) + m_translation;
}

void Square::Move() {
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