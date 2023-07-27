#include"MovingSquaresTest.h"

#include"../VertexBufferLayout.h"

#include"glm/glm.hpp"
#include"glm/gtc/matrix_transform.hpp"

#define SHADERS_FILE_PATH "res/shader/Basic.shader"
#define TEXTURES_FILE_PATH "res/texture/download.jpg"

namespace test {
	MovingSquaresTest::MovingSquaresTest(GLFWwindow* window) :
	m_translationA(200, 200, 0),
	m_translationB(400, 200, 0),
	m_proj(glm::ortho(0.0f, 640.0f, 0.0f, 480.0f, -1.0f, 1.0f)),
	m_view(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0))),
	m_time(0),
	m_window(window), Test(window){
		// Vertices
		float pos[] = {
			-50.0f, -50.0f, 0.0f, 0.0f,
			 50.0f, -50.0f, 1.0f, 0.0f,
			 50.0f,  50.0f, 1.0f, 1.0f,
			-50.0f,  50.0f, 0.0f, 1.0f
		};

		// Indices of the positions in order of drawing
		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0
		};

		GLCall(glEnable(GL_BLEND));
		GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

		m_VAO = std::make_unique<VertexArray>();
		m_VBO = std::make_unique<VertexBuffer>(pos, 4 * 4 * sizeof(float));
		VertexBufferLayout layout;
		layout.Push<float>(2);
		layout.Push<float>(2);
		m_VAO->AddBuffer(*m_VBO, layout);
		m_IBO = std::make_unique<IndexBuffer>(indices, 6);

		m_shader = std::make_unique<Shader>(SHADERS_FILE_PATH);
		m_shader->Bind();
		//m_shader->SetUniform4f("u_color", 0.8f, 0.3f, 0.8f, 1.0f);

		m_texture = std::make_unique<Texture>(TEXTURES_FILE_PATH);
		m_texture->Bind();

		m_shader->SetUniform1i("u_texture", 0);

		// Setup translation matrices
		m_translationA = glm::vec3(200, 200, 0);
		m_translationB = glm::vec3(400, 200, 0);
	}

	void MovingSquaresTest::OnRender() {
		GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
		GLCall(glClear(GL_COLOR_BUFFER_BIT));

		// Rendering
		Renderer renderer;

		// Clear window - first because of first frame
		m_renderer.Clear();

		// Loop logic

		m_shader->Bind();
		m_texture->Bind();

		// Setup projection matrix
		m_proj = glm::ortho(0.0f, 640.0f, 0.0f, 480.0f, -1.0f, 1.0f);

		// Setup view matrix
		m_view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));

		{
			// Setup model matrix
			glm::mat4 model = glm::translate(glm::mat4(1.0f), m_translationA);

			// Set mvp matrix
			glm::mat4 mvp = m_proj * m_view * model;

			m_shader->SetUniformMat4f("u_mvp", mvp);

			// Draw call
			renderer.Draw(*m_VAO, *m_IBO, *m_shader);
		}

		{
			// Setup model matrix
			glm::mat4 model = glm::translate(glm::mat4(1.0f), m_translationB);

			// Set mvp matrix
			glm::mat4 mvp = m_proj * m_view * model;

			m_shader->SetUniformMat4f("u_mvp", mvp);

			// Draw call
			renderer.Draw(*m_VAO, *m_IBO, *m_shader);
		}
	}
	void MovingSquaresTest::OnImGuiRender() {
		ImGui::SliderFloat3("Translation A: ", &m_translationA.x, 0.0f, 960.0f);
		ImGui::SliderFloat3("Translation B: ", &m_translationB.x, 0.0f, 960.0f);
		ImGui::Text("AVG Framerate: ¨.3f ms/f (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	}
}