#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

#include<GLAD/glad.h>
#include<GLFW/glfw3.h>

#include"Renderer.h"

#include"VertexBuffer.h"
#include"VertexBufferLayout.h"
#include"IndexBuffer.h"
#include"VertexArray.h"
#include"Texture.h"
#include"Shader.h"

#include"glm/glm.hpp"
#include"glm/gtc/matrix_transform.hpp"

#include"imgui/imgui.h"
#include"imgui/imgui_impl_glfw.h"
#include"imgui/imgui_impl_opengl3.h"

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
	// Setting up entities
		// Vertices
		float pos[] = {
			-50.0f, -50.0f, 0.0f, 0.0f,
			 50.0f, -50.0f, 1.0f, 0.0f,
			 50.0f,  50.0f, 1.0f, 1.0f,
			-50.0f,  50.0f, 0.0f, 1.0f
		};

		// Indices of the positions in order of drawing
		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0
		};

		GLCall(glEnable(GL_BLEND));
		GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

		// VAs, VBs and IBs
		VertexArray VA;
		VertexBuffer VB(pos, 4 * 4 * sizeof(float));

		VertexBufferLayout layout;
		layout.Push<float>(2);
		layout.Push<float>(2);
		VA.AddBuffer(VB, layout);

		IndexBuffer IB(indices, 6);

		// Setup projection matrix
		glm::mat4 proj = glm::ortho(0.0f, 640.0f, 0.0f, 480.0f, -1.0f, 1.0f);
		// Setup view matrix
		glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));

		// Setup shaders
		Shader shader(SHADERS_FILE_PATH);
		shader.Bind();

		// Setup textures
		Texture texture(TEXTURES_FILE_PATH);
		texture.Bind();

		shader.SetUniform1i("u_texture", 0);

		VA.Unbind();
		VB.Unbind();
		IB.Unbind();
		shader.Unbind();

		// Setup Renderer
		Renderer renderer;

		// Setup ImGui
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init(glsl_version);
		ImGui::StyleColorsDark();

		// ImGui
		bool show_demo_window = true;
		bool show_another_window = false;
		ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);


		// Setup logic
		
		glm::vec3 translationA(200, 200, 0);
		glm::vec3 translationB(400, 200, 0);

		// Main loop
		while (!glfwWindowShouldClose(window)) {
			// Rendering

			// Clear window - first because of first frame
			renderer.Clear();
			
			// Start the ImGui frame
			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();

			shader.Bind();

			{
				// Setup model matrix
				glm::mat4 model = glm::translate(glm::mat4(1.0f), translationA);

				// Set mvp matrix
				glm::mat4 mvp = proj * view * model;
				shader.SetUniformMat4f("u_mvp", mvp);

				// Draw call
				renderer.Draw(VA, IB, shader);
			}

			{
				// Setup model matrix
				glm::mat4 model = glm::translate(glm::mat4(1.0f), translationB);

				// Set mvp matrix
				glm::mat4 mvp = proj * view * model;
				shader.SetUniformMat4f("u_mvp", mvp);

				// Draw call
				renderer.Draw(VA, IB, shader);
			}

			// Loop logic

			// Simple window ImGui
			{
				ImGui::SliderFloat3("Translation A: ", &translationA.x, 0.0f, 960.0f);
				ImGui::SliderFloat3("Translation B: ", &translationB.x, 0.0f, 960.0f);
				ImGui::Text("AVG Framerate: ¨.3f ms/f (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
			}

			// Rendering ImGui
			ImGui::Render();
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

			// Swap front and back buffers - show on screen
			glfwSwapBuffers(window);

			// Process events
			glfwPollEvents();
		}
	}

	// Cleanup
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwTerminate();
	return 0;
}