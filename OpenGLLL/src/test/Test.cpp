#include"Test.h"

namespace test {

	TestMenu::TestMenu(Test*& current_test_ptr, GLFWwindow* window) :
		m_current_test(current_test_ptr), Test(window)
	{
	}	

	void TestMenu::OnRender()
	{
		GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
	}

	void TestMenu::OnImGuiRender()
	{
		for (auto& test : m_tests){
			if (ImGui::Button(test.first.c_str()))
				m_current_test = test.second();
		}
	}
}