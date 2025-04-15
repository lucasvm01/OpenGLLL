#include "Square.h"

#define SHADERS_FILE_PATH "res/shader/Basic.shader"
#define TEXTURES_FILE_PATH "res/texture/Cleiton.jpg"

// TODO
void Square::SetPositionVertices(glm::vec3* vertices, unsigned int* indices)
{
	m_mesh.SetVerticesProperties(vertices, indices);
}

void Square::DefineProperties(int op) {

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

	if (op == 1)SetTexture(TEXTURES_FILE_PATH);

	else SetTexture("res/texture/OMG.jpg");

	m_shader->SetUniform1i("u_texture", 0);
}

void Square::Move() {
	// Setup model matrix
	glm::mat4 model = glm::translate(glm::mat4(1.0f), m_translation);

	// Setup mvp matrix
	glm::mat4 mvp = m_proj * m_view * model;

	m_shader->SetUniformMat4f("u_mvp", mvp);
}