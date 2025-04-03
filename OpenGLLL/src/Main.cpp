#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

#include"Renderer.h"
#include"KeyHandler.h"

#include"VertexBufferLayout.h"

#include"imgui/imgui.h"
#include"imgui/imgui_impl_glfw.h"
#include"imgui/imgui_impl_opengl3.h"

#include"test/Test.h"
#include"test/ClearColor/TestClearColor.h"
#include"test/MovingSquares/MovingSquaresTest.h"

#define SHADERS_FILE_PATH "res/shader/Basic.shader"
#define TEXTURES_FILE_PATH "res/texture/download.jpg"

const unsigned int WINWIDTH = 1280, WINHEIGHT = 960;

int main(void) {
	// Configuration
	GLFWwindow* window;

	// Initialize glfw
	if (!glfwInit())
		return -1;

	// Hints
	const char* glsl_version = "#version 130";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// Create a window and its OpenGL context
	window = glfwCreateWindow(WINWIDTH, WINHEIGHT, "Main window", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	glfwSwapInterval(1);

	// Initialize glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize OpenGL context" << std::endl;
		glfwTerminate();
		return -1;
	}
	GLCall(glViewport(0, 0, WINWIDTH, WINHEIGHT));

	{
		// Setup Renderer
		Renderer renderer;


		// Setup ImGui
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init(glsl_version);
		ImGui::StyleColorsDark();

		// Test menu environment
		test::Test* current_test = nullptr;
		test::TestMenu* test_menu = new test::TestMenu(current_test);
		current_test = test_menu;

		test_menu->RegisterTest<test::TestClearColor>("Clear color");
		test_menu->RegisterTest<test::MovingSquaresTest>("Moving squares");
		
		
		// Setup logic

		// Main loop
		while (!glfwWindowShouldClose(window)) {
			// Rendering

			// Clear window - first because of first frame
			renderer.Clear();
			
			// Start the ImGui frame
			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();

			// Loop logic
			if (current_test) {
				current_test->OnUpdate(0.0f);
				current_test->OnRender();

				ImGui::Begin("Test");

				if (current_test != test_menu && ImGui::Button("<-")) {
					delete current_test;
					current_test = test_menu;
				}

				current_test->OnImGuiRender();

				ImGui::End();
			}

			// Rendering ImGui
			ImGui::Render();
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

			// Swap front and back buffers - show on screen
			glfwSwapBuffers(window);

			// Process events
			glfwPollEvents();
		}
		if (current_test != test_menu) delete test_menu;
		delete current_test;
	}

	// Cleanup
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwTerminate();
	return 0;
}
