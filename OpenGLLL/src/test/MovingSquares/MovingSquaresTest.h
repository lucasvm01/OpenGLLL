#pragma once

#include"../Test.h"

#include"../objects/Square/Square.h"

#include<memory>

#include"glm/glm.hpp"
#include"glm/gtc/matrix_transform.hpp"

namespace test {
	class MovingSquaresTest : public Test {
	public:
		MovingSquaresTest();
		~MovingSquaresTest() {}

		virtual void OnUpdate(float deltaTime) override;
		virtual void OnRender() override;
		virtual void OnImGuiRender() override;
	private:
		Renderer m_renderer;
		KeyHandler m_keyHandler;

		Square SquareA;
		Square SquareB;
		float m_speed;
	};
}