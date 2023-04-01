#pragma once

#include"Test.h"

#include"GLFW/glfw3.h"
#include"glm/glm.hpp"

#include"../Renderer.h"

namespace test {
	class CubeRotationTest : public Test {
	private:
		void MultiplyMatrixVector(glm::vec3& i, glm::vec3& o, glm::mat4x4& m)
		{
			o.x = i.x * m[0][0] + i.y * m[1][0] + i.z * m[2][0] + m[3][0];
			o.y = i.x * m[0][1] + i.y * m[1][1] + i.z * m[2][1] + m[3][1];
			o.z = i.x * m[0][2] + i.y * m[1][2] + i.z * m[2][2] + m[3][2];
			float w = i.x * m[0][3] + i.y * m[1][3] + i.z * m[2][3] + m[3][3];

			if (w != 0.0f){
				o.x /= w; o.y /= w; o.z /= w;
			}
		}
	public:
		CubeRotationTest(GLFWwindow* window);
		~CubeRotationTest();

		virtual void OnUpdate(float deltaTime) override;
		virtual void OnRender() override;
		virtual void OnImGuiRender() override;
	private:
		GLFWwindow* m_window;
		float elapsedTime;

		glm::vec3 m_vertices[8];

		float m_time;

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

		Shader m_shader;
	};
}