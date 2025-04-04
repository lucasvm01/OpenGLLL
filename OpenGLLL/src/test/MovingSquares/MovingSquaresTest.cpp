#include"MovingSquaresTest.h"

#define SHADERS_FILE_PATH "res/shader/"
#define TEXTURES_FILE_PATH "res/texture/"

namespace test {
	MovingSquaresTest::MovingSquaresTest() :
	m_time(0), m_speed(2.0f)
	{
		// Vertices
		glm::vec3 vertices[] = {
			glm::vec3(-50.0f,-50.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.5f),
			glm::vec3( 50.0f,-50.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.5f),
			glm::vec3( 50.0f, 50.0f, 0.0f), glm::vec3(1.0f, 1.0f, 0.5f),
			glm::vec3(-50.0f, 50.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.5f)



			//-50.0f, -50.0f, 0.0f, 0.0f,
			// 50.0f, -50.0f, 1.0f, 0.0f,
			// 50.0f,  50.0f, 1.0f, 1.0f,
			//-50.0f,  50.0f, 0.0f, 1.0f
		};

		// Indices of positions in order of drawing
		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0
		};

		SquareA.SetPositionVertices(vertices, indices);
		SquareB.SetPositionVertices(vertices, indices);

		

		SquareA.DefineProperties(
			(std::string(SHADERS_FILE_PATH) + "Basic.shader").c_str(),
			(std::string(TEXTURES_FILE_PATH) + "OMG.jpg").c_str());
		SquareB.DefineProperties(
			(std::string(SHADERS_FILE_PATH) + "Basic.shader").c_str(),
			(std::string(TEXTURES_FILE_PATH) + "OMG.jpg").c_str());
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
					SquareA.MovementUp();
					break;
				case GLFW_KEY_S:
					SquareA.MovementDown();
					break;
				case GLFW_KEY_A:
					SquareA.MovementLeft();
					break;
				case GLFW_KEY_D:
					SquareA.MovementRight();
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
					SquareB.MovementUp();
					break;
				case GLFW_KEY_DOWN:
					SquareB.MovementDown();
					break;
				case GLFW_KEY_LEFT:
					SquareB.MovementLeft();
					break;
				case GLFW_KEY_RIGHT:
					SquareB.MovementRight();
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
		ImGui::Text("AVG Framerate: ¨.3f ms/f (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		// Define a buffer to hold the text
		static char textBuffer[256] = "Hello, ImGui!"; // Default text

		//ImGui::Text("Select an image:");

		//std::string selected_image;

		//if (ImGui::Button("XQC")) {
		//	strcpy_s(textBuffer, "Text 1 Selected!");
		//	selected_image = "OMG.jpg";

		//	SquareA.SetShader((std::string(TEXTURES_FILE_PATH) + selected_image).c_str());
		//}

		//if (ImGui::Button("Girl")) {
		//	strcpy_s(textBuffer, "Text 2 Selected!");
		//	selected_image = "download.jpg";

		//	SquareA.SetShader((std::string(TEXTURES_FILE_PATH) + selected_image).c_str());
		//}

		//if (ImGui::Button("Cleiton")) {
		//	strcpy_s(textBuffer, "Text 3 Selected!");
		//	selected_image = "Cleiton.jpg";

		//	SquareA.SetShader((std::string(TEXTURES_FILE_PATH) + selected_image).c_str());
		//}

		//// Display the selected text in a text input field
		//ImGui::InputText("Selected Image: ", textBuffer, IM_ARRAYSIZE(textBuffer));
	}
}