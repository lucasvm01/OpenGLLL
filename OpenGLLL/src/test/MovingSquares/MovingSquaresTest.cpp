#include"MovingSquaresTest.h"

#define SHADERS_FILE_PATH "res/shader/Basic.shader"
#define TEXTURES_FILE_PATH "res/texture/Cleiton.jpg"

namespace test {
	MovingSquaresTest::MovingSquaresTest() :
	m_translationA(200, 200, 0),
	m_translationB(400, 200, 0),
	m_time(0), m_speed(2.0f)
	{
		// Vertices
		float pos[] = {
			-50.0f, -50.0f, 0.0f, 0.0f,
			 50.0f, -50.0f, 1.0f, 0.0f,
			 50.0f,  50.0f, 1.0f, 1.0f,
			-50.0f,  50.0f, 0.0f, 1.0f
		};


		SquareA.SetPositionVertices(pos);
		SquareB.SetPositionVertices(pos);

		SquareA.DefineProperties();
		SquareB.DefineProperties();

		//// Indices of positions in order of drawing
		//unsigned int indices[] = {
		//	0, 1, 2,
		//	2, 3, 0
		//};

		GLCall(glEnable(GL_BLEND));
		GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

		//m_VAO = std::make_unique<VertexArray>();
		//m_VBO = std::make_unique<VertexBuffer>(pos, 4 * 4 * sizeof(float));
		//VertexBufferLayout layout;
		//layout.Push<float>(2); // Coords
		//layout.Push<float>(2); // ?? Local coords?
		//m_VAO->AddBuffer(*m_VBO, layout);
		//m_IBO = std::make_unique<IndexBuffer>(indices, 6);
		
		/*m_shader = std::make_unique<Shader>(SHADERS_FILE_PATH);
		m_shader->Bind();*/
		//m_shader->SetUniform4f("u_color", 0.8f, 0.3f, 0.8f, 1.0f);

		/*m_texture = std::make_unique<Texture>(TEXTURES_FILE_PATH);
		m_texture->Bind();*/
	}

	void MovingSquaresTest::OnUpdate(float deltaTime)
	{
	}

	void MovingSquaresTest::OnRender() {
		GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
		GLCall(glClear(GL_COLOR_BUFFER_BIT));

		// Clear window - first because of first frame
		m_renderer.Clear();

		// Loop logic

		SquareA.m_shader->Bind();
		SquareA.m_texture->Bind();

		SquareB.m_shader->Bind();
		SquareB.m_texture->Bind();

		//// Setup projection matrix
		//m_proj = glm::ortho(0.0f, 640.0f, 0.0f, 480.0f, -1.0f, 1.0f);

		//// Setup view matrix
		//m_view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));

		m_keyHandler.KeyCallback();

		{
			SquareA.SetSpeed(m_speed);

			for (int key : m_keyHandler.PressedKeys()) {
				switch (key) {
				case GLFW_KEY_W:
					SquareA.MoveUp();
					break;
				case GLFW_KEY_S:
					SquareA.MoveDown();
					break;
				case GLFW_KEY_A:
					SquareA.MoveLeft();
					break;
				case GLFW_KEY_D:
					SquareA.MoveRight();
					break;
				}
			}

			SquareA.Move();

			// Draw call
			// m_renderer.Draw(*m_VAO, *m_IBO, *m_shader);
			SquareA.Draw(m_renderer);
		}

		//{
		//	for (int key : m_keyHandler.PressedKeys()) {
		//		switch (key) {
		//		case GLFW_KEY_UP:
		//			m_translationB = glm::vec3(0.0f, m_speed, 0.0f) + m_translationB;
		//			break;
		//		case GLFW_KEY_DOWN:
		//			m_translationB = glm::vec3(0.0f, -m_speed, 0.0f) + m_translationB;
		//			break;
		//		case GLFW_KEY_LEFT:
		//			m_translationB = glm::vec3(-m_speed, 0.0f, 0.0f) + m_translationB;
		//			break;
		//		case GLFW_KEY_RIGHT:
		//			m_translationB = glm::vec3(m_speed, 0.0f, 0.0f) + m_translationB;
		//			break;
		//		}
		//	}
		//	// Setup model matrix
		//	glm::mat4 model = glm::translate(glm::mat4(1.0f), m_translationB);

		//	// Set mvp matrix
		//	glm::mat4 mvp = m_proj * m_view * model;

		//	SquareB.m_shader->SetUniformMat4f("u_mvp", mvp);

		//	// Draw call
		//	m_renderer.Draw(*SquareB.m_VAO, *SquareB.m_IBO, *SquareB.m_shader);
		//}

		{
			SquareB.SetSpeed(m_speed);

			for (int key : m_keyHandler.PressedKeys()) {
				switch (key) {
				case GLFW_KEY_UP:
					SquareB.MoveUp();
					break;
				case GLFW_KEY_DOWN:
					SquareB.MoveDown();
					break;
				case GLFW_KEY_LEFT:
					SquareB.MoveLeft();
					break;
				case GLFW_KEY_RIGHT:
					SquareB.MoveRight();
					break;
				}
			}

			SquareB.Move();

			// Draw call
			// m_renderer.Draw(*m_VAO, *m_IBO, *m_shader);
			SquareB.Draw(m_renderer);
		}
	}
	void MovingSquaresTest::OnImGuiRender() {
		ImGui::SliderFloat3("Translation A: ", &SquareA.m_translation.x, 0.0f, 960.0f);
		ImGui::SliderFloat3("Translation B: ", &SquareB.m_translation.x, 0.0f, 960.0f);
		ImGui::SliderFloat3("Speed: ", &m_speed, 0.0f, 10.0f);
		ImGui::Text("AVG Framerate: ¨.3f ms/f (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	}
}