#pragma once

#include"../Test.h"

namespace test {
	class CubeRotationTest : public Test {
	public:
		CubeRotationTest();
		~CubeRotationTest() {}

		virtual void OnUpdate(float deltaTime) override;
		virtual void OnRender() override;
		virtual void OnImGuiRender() override;
	};
}