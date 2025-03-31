#pragma once

#include"../Test.h"
#include "Entities/Mesh.h"

#include"../VertexBufferLayout.h"

#include"glm/glm.hpp"
#include"glm/gtc/matrix_transform.hpp"

#include<memory>

namespace test {
	class MovingSquaresTest : public Test {
	public:
		MovingSquaresTest();
		virtual ~MovingSquaresTest() {}

		virtual void OnUpdate(float deltaTime) override;
		virtual void OnRender() override;
		virtual void OnImGuiRender() override;
	private:
		float m_time;

		Renderer m_renderer;
		KeyHandler m_keyHandler;

		Mesh Square;

		glm::vec3 m_translationA;
		glm::vec3 m_translationB;
		float m_speed;
		glm::mat4 m_proj;
		glm::mat4 m_view;
	};
}