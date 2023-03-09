#pragma once

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
		TestMenu();
		~TestMenu();

		virtual void OnImGuiRender() override;
	private:
		Test* m_current_test;
		std::vector<std::pair<std::string, std::function<Test* ()>>> m_tests;
	};
}