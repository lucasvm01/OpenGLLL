#pragma once

#include"Test.h"
#include"../Renderer.h"

struct vec3d
{
	float x, y, z;
};

struct mat4x4
{
	float m[4][4] = { 0 };
};

namespace test {
	class SquareRotationTest : public Test {
	private:
		void MultiplyMatrixVector(vec3d& i, vec3d& o, mat4x4& m)
		{
			o.x = i.x * m.m[0][0] + i.y * m.m[1][0] + i.z * m.m[2][0] + m.m[3][0];
			o.y = i.x * m.m[0][1] + i.y * m.m[1][1] + i.z * m.m[2][1] + m.m[3][1];
			o.z = i.x * m.m[0][2] + i.y * m.m[1][2] + i.z * m.m[2][2] + m.m[3][2];
			float w = i.x * m.m[0][3] + i.y * m.m[1][3] + i.z * m.m[2][3] + m.m[3][3];

			if (w != 0.0f)
			{
				o.x /= w; o.y /= w; o.z /= w;
			}
		}
	public:
		SquareRotationTest(GLFWwindow* window);
		~SquareRotationTest();

		virtual void OnUpdate(float deltaTime) override;
		virtual void OnRender() override;
		virtual void OnImGuiRender() override;
	private:

		mat4x4 matProj;

		float fTheta;
	};
}