#include"Test.h"
#include"../Renderer.h"
#include"imgui/imgui.h"

namespace test {

	TestMenu::TestMenu(Test*& current_test_ptr) :
		m_current_test(current_test_ptr)
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