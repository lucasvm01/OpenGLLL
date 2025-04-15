#pragma once

#include"../Renderer.h"
#include"imgui/imgui.h"

#include<iostream>
#include<vector>
#include<string>
#include<functional>

#include"../KeyHandler.h"

namespace test {
	class Test {
	public:
		Test() : m_elapsed_time(0) {}
		virtual ~Test(){}

		virtual void OnUpdate(float deltaTime){}
		virtual void OnRender(){}
		virtual void OnImGuiRender(){}

		float m_elapsed_time;
	};

	class TestMenu : public Test {
	public:
		TestMenu(Test*& current_test_ptr);

		virtual void OnRender() override;
		virtual void OnImGuiRender() override;

		template<typename T>
		void RegisterTest(const std::string& name) {
			std::cout << "Registering test " << name << std::endl;

			m_tests.push_back(std::make_pair(name, []() { return new T(); }));
		}
	private:
		Test*& m_current_test;
		std::vector<std::pair<std::string, std::function<Test*()>>> m_tests;
	};
}