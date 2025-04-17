#include "CubeRotationTest.h"

test::CubeRotationTest::CubeRotationTest()
{
	// Vertices
	glm::vec3 vertices[] = {
		// Front vertices
		glm::vec3(-50.0f,-50.0f,-50.0f), glm::vec3(0.0f, 0.0f,0.0f),
		glm::vec3( 50.0f,-50.0f,-50.0f), glm::vec3(1.0f, 0.0f,0.0f),
		glm::vec3( 50.0f, 50.0f,-50.0f), glm::vec3(1.0f, 1.0f,0.0f),
		glm::vec3(-50.0f, 50.0f,-50.0f), glm::vec3(0.0f, 1.0f,0.0f),
		// Back vertices
		glm::vec3(-50.0f,-50.0f, 50.0f), glm::vec3(0.0f, 0.0f,1.0f),
		glm::vec3( 50.0f,-50.0f, 50.0f), glm::vec3(1.0f, 0.0f,1.0f),
		glm::vec3( 50.0f, 50.0f, 50.0f), glm::vec3(1.0f, 1.0f,1.0f),
		glm::vec3(-50.0f, 50.0f, 50.0f), glm::vec3(0.0f, 1.0f,1.0f),
	};

	// Indices of positions in order of drawing
	unsigned int indices[] = { // 36
		// Back face triangles
		7, 6, 5,
		5, 4, 7,
		// Right face triangles
		3, 2, 6,
		6, 7, 3,
		// Left face triangles
		4, 5, 1,
		1, 0, 4,
		// Up face triangles
		1, 5, 6,
		6, 2, 1,
		// Down face triangles
		0, 4, 7,
		7, 3, 0,
		// Front face triangles
		0, 1, 2,
		2, 3, 0,
	};

	CubeA.SetPositionVertices(vertices, indices);

	CubeA.DefineProperties();
}

void test::CubeRotationTest::OnUpdate(float deltaTime) {
	if (CubeA.m_rotate_x || CubeA.m_rotate_y || CubeA.m_rotate_z)
		m_elapsed_time += deltaTime;
	else m_elapsed_time = 0;

	CubeA.Rotate(m_elapsed_time);
}

void test::CubeRotationTest::OnRender() {
	GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
	GLCall(glClear(GL_COLOR_BUFFER_BIT));

	// Clear window - first because of first frame
	m_renderer.Clear();

	// Loop logic

	m_keyHandler.KeyCallback();

	{
		CubeA.m_shader->Bind();
		//CubeA.m_texture->Bind();

		CubeA.SetSpeed(2.0f);

		for (int key : m_keyHandler.PressedKeys()) {
			switch (key) {
			case GLFW_KEY_W:
				CubeA.TranslatePositiveY();
				break;
			case GLFW_KEY_S:
				CubeA.TranslateNegativeY();
				break;
			case GLFW_KEY_A:
				CubeA.TranslateNegativeX();
				break;
			case GLFW_KEY_D:
				CubeA.TranslatePositiveX();
				break;
			case GLFW_KEY_UP:
				CubeA.TranslatePositiveZ();
				break;
			case GLFW_KEY_DOWN:
				CubeA.TranslateNegativeZ();
				break;
			case GLFW_KEY_Z:
				CubeA.SetRotationZ();
				break;
			case GLFW_KEY_X:
				CubeA.SetRotationX();
				break;
			case GLFW_KEY_C:
				CubeA.SetRotationY();
				break;
			case GLFW_KEY_P:
				CubeA.StopRotationX();
				CubeA.StopRotationY();
				CubeA.StopRotationZ();
				break;
			}
		}

		CubeA.Move();

		CubeA.Draw(m_renderer);
	}
}

void test::CubeRotationTest::OnImGuiRender() {
	ImGui::SliderFloat3("Translation A: ", &CubeA.m_translation.x, 0.0f, 960.0f);
	ImGui::SliderFloat("Speed: ", &m_speed, 0.0f, 50.0f);
	ImGui::Text("AVG Framerate: ¨.3f ms/f (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
}