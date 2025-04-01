#include "Mesh.h"

#define SHADERS_FILE_PATH "res/shader/Basic.shader"
#define TEXTURES_FILE_PATH "res/texture/Cleiton.jpg"

void Mesh::SetPositionVertices(float* data) {
	// Vertices
	m_pos = data;
}

void Mesh::ProcessVertices() {

	// Vertices
	float pos[] = {
		-50.0f, -50.0f, 0.0f, 0.0f,
			50.0f, -50.0f, 1.0f, 0.0f,
			50.0f,  50.0f, 1.0f, 1.0f,
		-50.0f,  50.0f, 0.0f, 1.0f
	};

	m_pos = pos;

	// Indices of positions in order of drawing
	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	m_indices = indices;

	m_VAO = std::make_unique<VertexArray>();
	m_VBO = std::make_unique<VertexBuffer>(pos, 4 * 4 * sizeof(float));
	VertexBufferLayout layout;
	layout.Push<float>(2); // Coords
	layout.Push<float>(2); // ?? Local coords?
	m_VAO->AddBuffer(*m_VBO, layout);
	m_IBO = std::make_unique<IndexBuffer>(m_indices, 6);

	SetShader(SHADERS_FILE_PATH);

	SetTexture(TEXTURES_FILE_PATH);

	m_shader->SetUniform1i("u_texture", 0);


	// Setup projection matrix
	m_proj = glm::ortho(0.0f, 640.0f, 0.0f, 480.0f, -1.0f, 1.0f);

	// Setup view matrix
	m_view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
}

void Mesh::SetShader(std::string shader_path){
	m_shader = std::make_unique<Shader>(shader_path);
	m_shader->Bind();
}

void Mesh::SetTexture(std::string texture_path) {
	m_texture = std::make_unique<Texture>(texture_path);
	m_texture->Bind();
}

int Mesh::HandleInput(std::vector<int> keys)
{
	return 1;
}

void Mesh::MoveUp()
{
	m_translation = glm::vec3(0.0f, m_speed, 0.0f) + m_translation;
}

void Mesh::MoveDown()
{
	m_translation = glm::vec3(0.0f, -m_speed, 0.0f) + m_translation;
}

void Mesh::MoveLeft()
{
	m_translation = glm::vec3(-m_speed, 0.0f, 0.0f) + m_translation;
}

void Mesh::MoveRight()
{
	m_translation = glm::vec3(m_speed, 0.0f, 0.0f) + m_translation;
}

void Mesh::SetSpeed(float speed) {
	m_speed = speed;
}

void Mesh::Move() {
	// Setup model matrix
	glm::mat4 model = glm::translate(glm::mat4(1.0f), m_translation);

	// Set mvp matrix
	glm::mat4 mvp = m_proj * m_view * model;

	m_shader->SetUniformMat4f("u_mvp", mvp);
}
