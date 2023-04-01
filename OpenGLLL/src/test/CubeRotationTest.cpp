#define PI 3.1415926535897931

#include"CubeRotationTest.h"

#include<cmath>

namespace test {
	CubeRotationTest::CubeRotationTest(GLFWwindow* window) :
		m_window(window), 
	{
		elapsedTime = 0;

		m_fov = 1 / (tan((50 * PI / 180) * 0.5) * 0.5);
		m_z_ratio = m_z_far / m_z_near;

		m_vertices[0] = glm::vec3(0, 0, 0);
		m_vertices[1] = glm::vec3(0, 1, 0);
		m_vertices[2] = glm::vec3(1, 0, 0);
		m_vertices[3] = glm::vec3(1, 1, 0);
		m_vertices[4] = glm::vec3(1, 1, 1);
		m_vertices[5] = glm::vec3(0, 1, 1);
		m_vertices[6] = glm::vec3(1, 0, 1);
		m_vertices[7] = glm::vec3(0, 0, 1);

		m_x_rotation_matrix = glm::mat4x4{
			{1,				  0,				 0, 0},
			{0,cos(elapsedTime), -sin(elapsedTime), 0},
			{0,sin(elapsedTime),  cos(elapsedTime), 0},
			{0,				  0,				 0, 1}
		};

		m_y_rotation_matrix = glm::mat4x4{
			{cos(elapsedTime), -sin(elapsedTime),				  0,0},
			{				0,				   1,				  0,0},
			{				0,  sin(elapsedTime),  cos(elapsedTime),0},
			{				0,				   0,				  0,1}
		};

		m_z_rotation_matrix = glm::mat4x4{
			{cos(elapsedTime), -sin(elapsedTime), 0, 0},
			{sin(elapsedTime),  cos(elapsedTime), 0, 0},
			{				0,				   0, 1, 0},
			{				0,				   0, 0, 1}
		};
	}

	CubeRotationTest::~CubeRotationTest()
	{
	}

	void CubeRotationTest::OnUpdate(float deltaTime)
	{
		elapsedTime = 1.0f * deltaTime;

		int win_width, win_height;
		glfwGetWindowSize(m_window, &win_width, &win_width);
		if(win_width != 0)
			m_aspect_ratio = (float) win_width / win_height; // TODO: trying to do this dinamically

		m_projection_matrix = glm::mat4x4{
			{m_aspect_ratio * m_fov, 0, 0, 0}, // x
			{0, m_fov, 0, 0},				   // y
			{0, 0, m_z_ratio, 1},			   // z
			{0, 0, -m_z_near * m_z_ratio, 0}   // z complement
		};
	}

	void CubeRotationTest::OnRender()
	{
	}

	void CubeRotationTest::OnImGuiRender()
	{
	}
}