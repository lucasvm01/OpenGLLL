#pragma once

#include"../Test.h"
#include "../../objects/Cube/Cube.h"

namespace test {
	class CubeRotationTest : public Test {
	public:
		CubeRotationTest();
		~CubeRotationTest() {}

		virtual void OnUpdate(float deltaTime) override;
		virtual void OnRender() override;
		virtual void OnImGuiRender() override;

	private:
		Renderer m_renderer;
		KeyHandler m_keyHandler;

		Cube CubeA;
		//Cube CubeB;
		float m_speed;
	};
}