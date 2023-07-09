#pragma once

#include<iostream>
#include<vector>
#include<string>
#include<functional>

namespace test {
	class Test {
	public:
		Test(){}
		virtual ~Test(){}

		virtual void OnUpdate(float deltaTime){}
		virtual void OnRender(){}
		virtual void OnImGuiRender(){}
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