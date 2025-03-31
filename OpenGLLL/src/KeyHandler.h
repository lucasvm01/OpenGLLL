#pragma once

#include <GLFW/glfw3.h> // Renderer.h maybe?
#include <iostream>
#include <vector>

class KeyHandler {
	private:
		static int m_lastPress;
		static int m_lastRelease;

		static std::vector<int> m_PressedKeys;

		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	public:
		void KeyCallback();

		int GetKey(int key);

		bool IsKeyPressed();
		std::vector<int> PressedKeys();
};