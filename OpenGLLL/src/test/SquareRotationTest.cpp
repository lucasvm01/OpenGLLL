#include "SquareRotationTest.h"

test::SquareRotationTest::SquareRotationTest(GLFWwindow* window)
{
	// Projection Matrix
	float fNear = 0.1f;
	float fFar = 1000.0f;
	float fFov = 90.0f;
	]]
	int win_width, win_height;
	glfwGetWindowSize(window, &win_width, &win_height);
	float fAspectRatio = (float)win_width / win_height;
	float fFovRad = 1.0f / tanf(fFov * 0.5f / 180.0f * 3.14159f);

	matProj.m[0][0] = fAspectRatio * fFovRad;
	matProj.m[1][1] = fFovRad;
	matProj.m[2][2] = fFar / (fFar - fNear);
	matProj.m[3][2] = (-fFar * fNear) / (fFar - fNear);
	matProj.m[2][3] = 1.0f;
	matProj.m[3][3] = 0.0f;
}

void test::SquareRotationTest::OnUpdate(float deltaTime)
{
}

void test::SquareRotationTest::OnRender()
{
}

void test::SquareRotationTest::OnImGuiRender()
{
}