#include "Mesh.h"

#define SHADERS_FILE_PATH "res/shader/Basic.shader"
#define TEXTURES_FILE_PATH "res/texture/Cleiton.jpg"

namespace test {
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
	}

	void Mesh::SetShader() {
		m_shader = std::make_unique<Shader>(SHADERS_FILE_PATH);
		m_shader->Bind();
	}

	void Mesh::SetTexture() {
		m_texture = std::make_unique<Texture>(TEXTURES_FILE_PATH);
		m_texture->Bind();
	}


}
