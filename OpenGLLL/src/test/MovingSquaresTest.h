#pragma once

#include"Test.h"

#include<memory>

namespace test {
	class MovingSquaresTest : public Test {
	public:
		MovingSquaresTest(GLFWwindow* window);
		virtual ~MovingSquaresTest() {}

		virtual void OnUpdate(float deltaTime) override {}
		virtual void OnRender() override;
		virtual void OnImGuiRender() override;
	private:
		float m_time;

		Renderer m_renderer;

		std::unique_ptr<VertexArray> m_VAO;
		std::unique_ptr<VertexBuffer> m_VBO;
		std::unique_ptr<IndexBuffer> m_IBO;

		std::unique_ptr<Shader> m_shader;
		std::unique_ptr<Texture> m_texture;

		glm::vec3 m_translationA;
		glm::vec3 m_translationB;
		glm::mat4 m_proj;
		glm::mat4 m_view;

		GLFWwindow* m_window;
	};
}