#include "KeyHandler.h"

int KeyHandler::m_lastPress;
int KeyHandler::m_lastRelease;
std::vector<int> KeyHandler::m_PressedKeys;

void print_vector(const std::vector<int>& c)
{
	for (int i : c)
		std::cout << i << ' ';
	std::cout << '\n';
}


void KeyHandler::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
	if (action == GLFW_PRESS) m_PressedKeys.push_back(key);

	if(action == GLFW_RELEASE)
		for (std::vector<int>::iterator it = m_PressedKeys.begin(); it != m_PressedKeys.end();) {
			if (*it == key) {
				m_PressedKeys.erase(it);
				break;
			}
			else
				++it;
		}
	//print_vector(m_PressedKeys);
}

void KeyHandler::KeyCallback(){
	glfwSetKeyCallback(glfwGetCurrentContext(), key_callback);
}

int KeyHandler::GetKeyState(int key)
{
	return glfwGetKey(glfwGetCurrentContext(), key);
}

bool KeyHandler::IsKeyPressed()
{
	return !m_PressedKeys.empty();
}

std::vector<int> KeyHandler::PressedKeys()
{
	return m_PressedKeys;
}
