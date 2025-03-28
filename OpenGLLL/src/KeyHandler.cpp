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
	/*
	if (action == GLFW_PRESS)	m_lastPress = key;

	if (action == GLFW_RELEASE)	m_lastRelease = key;

	std::cout << "Last press:	" << m_lastPress << std::endl;
	std::cout << "Last release: " << m_lastRelease << std::endl;
	*/

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
}

void KeyHandler::KeyCallback(){
	glfwSetKeyCallback(glfwGetCurrentContext(), key_callback);
}

int KeyHandler::GetKey(int key)
{
	return glfwGetKey(glfwGetCurrentContext(), key);
}

bool KeyHandler::IsKeyPressed()
{

	/*if (
		GetKey(GLFW_KEY_SPACE           ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_APOSTROPHE      ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_COMMA           ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_MINUS           ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_PERIOD          ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_SLASH           ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_0               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_1               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_2               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_3               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_4               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_5               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_6               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_7               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_8               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_9               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_SEMICOLON       ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_EQUAL           ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_A               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_B               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_C               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_D               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_E               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_F               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_G               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_H               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_I               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_J               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_K               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_L               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_M               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_N               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_O               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_P               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_Q               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_R               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_S               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_T               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_U               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_V               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_W               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_X               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_Y               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_Z               ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_LEFT_BRACKET    ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_BACKSLASH       ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_RIGHT_BRACKET   ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_GRAVE_ACCENT    ) == GLFW_PRESS ||
		GetKey(GLFW_KEY_WORLD_1         )== GLFW_PRESS ||
		GetKey(GLFW_KEY_WORLD_2         )== GLFW_PRESS ||
		GetKey(GLFW_KEY_ESCAPE          )== GLFW_PRESS ||
		GetKey(GLFW_KEY_ENTER           )== GLFW_PRESS ||
		GetKey(GLFW_KEY_TAB             )== GLFW_PRESS ||
		GetKey(GLFW_KEY_BACKSPACE       )== GLFW_PRESS ||
		GetKey(GLFW_KEY_INSERT          )== GLFW_PRESS ||
		GetKey(GLFW_KEY_DELETE          )== GLFW_PRESS ||
		GetKey(GLFW_KEY_RIGHT           )== GLFW_PRESS ||
		GetKey(GLFW_KEY_LEFT            )== GLFW_PRESS ||
		GetKey(GLFW_KEY_DOWN            )== GLFW_PRESS ||
		GetKey(GLFW_KEY_UP              )== GLFW_PRESS ||
		GetKey(GLFW_KEY_PAGE_UP         )== GLFW_PRESS ||
		GetKey(GLFW_KEY_PAGE_DOWN       )== GLFW_PRESS ||
		GetKey(GLFW_KEY_HOME            )== GLFW_PRESS ||
		GetKey(GLFW_KEY_END             )== GLFW_PRESS ||
		GetKey(GLFW_KEY_CAPS_LOCK       )== GLFW_PRESS ||
		GetKey(GLFW_KEY_SCROLL_LOCK     )== GLFW_PRESS ||
		GetKey(GLFW_KEY_NUM_LOCK        )== GLFW_PRESS ||
		GetKey(GLFW_KEY_PRINT_SCREEN    )== GLFW_PRESS ||
		GetKey(GLFW_KEY_PAUSE           )== GLFW_PRESS ||
		GetKey(GLFW_KEY_F1              )== GLFW_PRESS ||
		GetKey(GLFW_KEY_F2              )== GLFW_PRESS ||
		GetKey(GLFW_KEY_F3              )== GLFW_PRESS ||
		GetKey(GLFW_KEY_F4              )== GLFW_PRESS ||
		GetKey(GLFW_KEY_F5              )== GLFW_PRESS ||
		GetKey(GLFW_KEY_F6              )== GLFW_PRESS ||
		GetKey(GLFW_KEY_F7              )== GLFW_PRESS ||
		GetKey(GLFW_KEY_F8              )== GLFW_PRESS ||
		GetKey(GLFW_KEY_F9              )== GLFW_PRESS ||
		GetKey(GLFW_KEY_F10             )== GLFW_PRESS ||
		GetKey(GLFW_KEY_F11             )== GLFW_PRESS ||
		GetKey(GLFW_KEY_F12             )== GLFW_PRESS ||
		GetKey(GLFW_KEY_F13             )== GLFW_PRESS ||
		GetKey(GLFW_KEY_F14             )== GLFW_PRESS ||
		GetKey(GLFW_KEY_F15             )== GLFW_PRESS ||
		GetKey(GLFW_KEY_F16             )== GLFW_PRESS ||
		GetKey(GLFW_KEY_F17             )== GLFW_PRESS ||
		GetKey(GLFW_KEY_F18             )== GLFW_PRESS ||
		GetKey(GLFW_KEY_F19             )== GLFW_PRESS ||
		GetKey(GLFW_KEY_F20             )== GLFW_PRESS ||
		GetKey(GLFW_KEY_F21             )== GLFW_PRESS ||
		GetKey(GLFW_KEY_F22             )== GLFW_PRESS ||
		GetKey(GLFW_KEY_F23             )== GLFW_PRESS ||
		GetKey(GLFW_KEY_F24             )== GLFW_PRESS ||
		GetKey(GLFW_KEY_F25             )== GLFW_PRESS ||
		GetKey(GLFW_KEY_KP_0            )== GLFW_PRESS ||
		GetKey(GLFW_KEY_KP_1            )== GLFW_PRESS ||
		GetKey(GLFW_KEY_KP_2            )== GLFW_PRESS ||
		GetKey(GLFW_KEY_KP_3            )== GLFW_PRESS ||
		GetKey(GLFW_KEY_KP_4            )== GLFW_PRESS ||
		GetKey(GLFW_KEY_KP_5            )== GLFW_PRESS ||
		GetKey(GLFW_KEY_KP_6            )== GLFW_PRESS ||
		GetKey(GLFW_KEY_KP_7            )== GLFW_PRESS ||
		GetKey(GLFW_KEY_KP_8            )== GLFW_PRESS ||
		GetKey(GLFW_KEY_KP_9            )== GLFW_PRESS ||
		GetKey(GLFW_KEY_KP_DECIMAL      )== GLFW_PRESS ||
		GetKey(GLFW_KEY_KP_DIVIDE       )== GLFW_PRESS ||
		GetKey(GLFW_KEY_KP_MULTIPLY     )== GLFW_PRESS ||
		GetKey(GLFW_KEY_KP_SUBTRACT     )== GLFW_PRESS ||
		GetKey(GLFW_KEY_KP_ADD          )== GLFW_PRESS ||
		GetKey(GLFW_KEY_KP_ENTER        )== GLFW_PRESS ||
		GetKey(GLFW_KEY_KP_EQUAL        )== GLFW_PRESS ||
		GetKey(GLFW_KEY_LEFT_SHIFT      )== GLFW_PRESS ||
		GetKey(GLFW_KEY_LEFT_CONTROL    )== GLFW_PRESS ||
		GetKey(GLFW_KEY_LEFT_ALT        )== GLFW_PRESS ||
		GetKey(GLFW_KEY_LEFT_SUPER      )== GLFW_PRESS ||
		GetKey(GLFW_KEY_RIGHT_SHIFT     )== GLFW_PRESS ||
		GetKey(GLFW_KEY_RIGHT_CONTROL   )== GLFW_PRESS ||
		GetKey(GLFW_KEY_RIGHT_ALT       )== GLFW_PRESS ||
		GetKey(GLFW_KEY_RIGHT_SUPER     )== GLFW_PRESS ||
		GetKey(GLFW_KEY_MENU            )== GLFW_PRESS)*/
			//return true;
	return false;
}

std::vector<int> KeyHandler::PressedKeys()
{
	return m_PressedKeys;
}
