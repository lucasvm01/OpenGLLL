

#include"CubeRotationTest.h"
#include"../../VertexBufferLayout.h"

#include<cmath>

#define PI 3.1415926535897931
#define SHADERS_FILE_PATH "res/shader/Basic.shader"

namespace test {
	CubeRotationTest::CubeRotationTest(GLFWwindow* window) :
		 m_elapsedTime(0)
	{
		m_fov = 1 / (tan((50 * PI / 180) * 0.5) * 0.5);
		m_z_ratio = m_z_far / m_z_near;

		m_vertices[0] = glm::vec3(0.0f, 0.0f, 0.0f);
		m_vertices[1] = glm::vec3(0.0f, 1.0f, 0.0f);
		m_vertices[2] = glm::vec3(1.0f, 0.0f, 0.0f);
		m_vertices[3] = glm::vec3(1.0f, 1.0f, 0.0f);
		m_vertices[4] = glm::vec3(1.0f, 1.0f, 1.0f);
		m_vertices[5] = glm::vec3(0.0f, 1.0f, 1.0f);
		m_vertices[6] = glm::vec3(1.0f, 0.0f, 1.0f);
		m_vertices[7] = glm::vec3(0.0f, 0.0f, 1.0f);

		//Shader shader(SHADERS_FILE_PATH);

		VertexArray VA;
		VertexBuffer VB(m_vertices, 8 * 3 * sizeof(glm::vec3));

		VertexBufferLayout layout;
		layout.Push<glm::vec3>(3);
		VA.AddBuffer(VB, layout);

		m_VAO = &VA;
	}

	CubeRotationTest::~CubeRotationTest()
	{
	}

	void CubeRotationTest::OnUpdate(float deltaTime)
	{
		m_elapsedTime = 1.0f * deltaTime;

		int win_width, win_height;
		if(win_width != 0)
			m_aspect_ratio = (float) win_width / win_height; // TODO: trying to do this dinamically

		m_projection_matrix = glm::mat4x4{
			{m_aspect_ratio * m_fov, 0, 0, 0}, // x
			{0, m_fov, 0, 0},				   // y
			{0, 0, m_z_ratio, 1},			   // z
			{0, 0, -m_z_near * m_z_ratio, 0}   // z complement
		};

		m_x_rotation_matrix = glm::mat4x4{
			{1,				    0,				     0, 0},
			{0,cos(m_elapsedTime), -sin(m_elapsedTime), 0},
			{0,sin(m_elapsedTime),  cos(m_elapsedTime), 0},
			{0,				    0,			     	 0, 1}
		};

		m_y_rotation_matrix = glm::mat4x4{
			{cos(m_elapsedTime), -sin(m_elapsedTime),				    0,0},
			{				  0,				   1,				    0,0},
			{				  0,  sin(m_elapsedTime),  cos(m_elapsedTime),0},
			{				  0,				   0,				    0,1}
		};

		m_z_rotation_matrix = glm::mat4x4{
			{cos(m_elapsedTime), -sin(m_elapsedTime), 0, 0},
			{sin(m_elapsedTime),  cos(m_elapsedTime), 0, 0},
			{				0,				   0, 1, 0},
			{				0,				   0, 0, 1}
		};
	}

	void CubeRotationTest::OnRender()
	{
	}

	void CubeRotationTest::OnImGuiRender()
	{
	}
}