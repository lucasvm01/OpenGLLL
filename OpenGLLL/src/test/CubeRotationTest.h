#pragma once

#include"Test.h"

#include"../Renderer.h"

namespace test {
	class CubeRotationTest : public Test {
	public:
		CubeRotationTest(GLFWwindow* window);
		~CubeRotationTest();

		virtual void OnUpdate(float deltaTime) override;
		virtual void OnRender() override;
		virtual void OnImGuiRender() override;
	private:
		GLFWwindow* m_window;
		unsigned int m_elapsedTime;

		glm::vec3 m_vertices[8];

		glm::mat4x4 m_projection_matrix;

		glm::mat4x4 m_x_rotation_matrix;
		glm::mat4x4 m_y_rotation_matrix;
		glm::mat4x4 m_z_rotation_matrix;
		
		float m_x_translation;
		float m_y_translation;
		float m_z_translation;

		float m_x_rotation_frequency;
		float m_y_rotation_frequency;
		float m_z_rotation_frequency;

		float m_z_far;
		float m_z_near;
		float m_z_ratio;

		float m_aspect_ratio;
		float m_fov;

		float m_scale;

		VertexArray* m_VAO;
		VertexBuffer* m_VBO;
		IndexBuffer* m_IBO;
		VertexBufferLayout* m_layout;
	};
}