#include "CubeRotationTest.h"

test::CubeRotationTest::CubeRotationTest()
{
	// Vertices
	glm::vec3 vertices[] = {
		// Front vertices
		glm::vec3(-50.0f,-50.0f,-50.0f), glm::vec3(0.0f, 0.0f, 0.5f),
		glm::vec3( 50.0f,-50.0f,-50.0f), glm::vec3(1.0f, 0.0f, 0.5f),
		glm::vec3( 50.0f, 50.0f,-50.0f), glm::vec3(1.0f, 1.0f, 0.5f),
		glm::vec3(-50.0f, 50.0f,-50.0f), glm::vec3(0.0f, 1.0f, 0.5f),
		// Back vertices
		glm::vec3(-50.0f,-50.0f, 50.0f),
		glm::vec3( 50.0f,-50.0f, 50.0f),
		glm::vec3( 50.0f, 50.0f, 50.0f),
		glm::vec3(-50.0f, 50.0f, 50.0f),
	};

	// Indices of positions in order of drawing
	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 0
	};

}

void test::CubeRotationTest::OnUpdate(float deltaTime) {
	m_elapsed_time += deltaTime;
}

void test::CubeRotationTest::OnRender() {
}

void test::CubeRotationTest::OnImGuiRender() {
}
