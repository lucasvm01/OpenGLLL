#pragma once

#include"../Renderer.h"
#include"imgui/imgui.h"

#include<iostream>
#include<vector>
#include<string>
#include<functional>

namespace test {
	class Test {
	public:
		Test(GLFWwindow* window){}
		virtual ~Test(){}

		virtual void OnUpdate(float deltaTime){}
		virtual void OnRender(){}
		virtual void OnImGuiRender(){}
	};

	class TestMenu : public Test {
	public:
		TestMenu(Test*& current_test_ptr, GLFWwindow* window);

		virtual void OnRender() override;
		virtual void OnImGuiRender() override;

		template<typename T, GLFWwindow* window>
		void RegisterTest(const std::string& name) {
			std::cout << "Registering test " << name << std::endl;

			m_tests.push_back(std::make_pair(name, []() { return new T(window); }));
		}
	private:
		Test*& m_current_test;
		std::vector<std::pair<std::string, std::function<Test*()>>> m_tests;
	};
}