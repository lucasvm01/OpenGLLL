#include "Cube.h"

#define SHADERS_FILE_PATH "res/shader/Basic.shader"
#define TEXTURES_FILE_PATH "res/texture/gpu.jpg"

// Setup - Change to Object class implementation?
void Cube::SetPositionVertices(glm::vec3* vertices, unsigned int* indices) {
	m_mesh.SetVerticesProperties(vertices, indices); 
}

void Cube::DefineProperties() {
	m_mesh.m_VAO = std::make_unique<VertexArray>();
	m_mesh.m_VBO = std::make_unique<VertexBuffer>(m_mesh.m_vertices, 8 * 2 * sizeof(glm::vec3));
	VertexBufferLayout layout;
	layout.Push<glm::vec3>(1); // Coords
	layout.Push<glm::vec3>(1); // ?? Local coords?
	m_mesh.m_VAO->AddBuffer(*m_mesh.m_VBO, layout);
	m_mesh.m_IBO = std::make_unique<IndexBuffer>(m_mesh.m_indices, 36);

	GLCall(glEnable(GL_BLEND));
	GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

	SetShader(SHADERS_FILE_PATH);

	//m_shader->SetUniform4f("u_color", 0.8f, 0.3f, 0.8f, 1.0f);

	SetTexture(TEXTURES_FILE_PATH);

	m_shader->SetUniform1i("u_texture", 0);

	SetupProjection();
}

void Cube::Move() {
	// Setup model matrix
	glm::mat4 model = glm::translate(glm::mat4(1.0f), m_translation);

	model = model * m_rotation;

	// Setup mvp matrix
	glm::mat4 mvp = m_proj * m_view * model;

	m_shader->SetUniformMat4f("u_mvp", mvp);
}

void Cube::SetupProjection() {
	int width, height;
	glfwGetWindowSize(glfwGetCurrentContext(), &width, &height);
	float winRatio = width / height;

	float pi = glm::pi<float>();
	
	float angle = (50 * pi / 180) / 2;
	float fov = 1 / (glm::tan(angle) / 2);

	float zFar = 10000, zNear = 0.1;
	float z = zFar / (zFar - zNear);

	m_proj = glm::mat4(
		winRatio * fov, 0,	 0,			0,
		0,				fov, 0,			0,
		0,				0,   z,			1,
		0,				0,  -zNear * z, 0
	);
}
