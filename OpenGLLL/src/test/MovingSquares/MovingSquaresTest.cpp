#include"MovingSquaresTest.h"

namespace test {
	MovingSquaresTest::MovingSquaresTest() :
	m_time(0), m_speed(2.0f)
	{
		// Vertices
		float vertices[] = {
			-50.0f, -50.0f, 0.0f, 0.0f,
			 50.0f, -50.0f, 1.0f, 0.0f,
			 50.0f,  50.0f, 1.0f, 1.0f,
			-50.0f,  50.0f, 0.0f, 1.0f
		};

		// Indices of positions in order of drawing
		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0
		};

		SquareA.SetPositionVertices(vertices, indices);
		SquareB.SetPositionVertices(vertices, indices);

		SquareA.DefineProperties();
		SquareB.DefineProperties();
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
			SquareA.Draw(m_renderer);
		}

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
			SquareB.Draw(m_renderer);
		}
	}
	void MovingSquaresTest::OnImGuiRender() {
		ImGui::SliderFloat3("Translation A: ", &SquareA.m_translation.x, 0.0f, 960.0f);
		ImGui::SliderFloat3("Translation B: ", &SquareB.m_translation.x, 0.0f, 960.0f);
		ImGui::SliderFloat("Speed: ", &m_speed, 0.0f, 10.0f);
		ImGui::Text("AVG Framerate: �.3f ms/f (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	}
}