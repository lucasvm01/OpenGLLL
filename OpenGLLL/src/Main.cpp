#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

#include<GLAD/glad.h>
#include<GLFW/glfw3.h>

#include"Renderer.h"

#include"VertexBuffer.h"
#include"IndexBuffer.h"
#include"VertexArray.h"
#include"Shader.h"

#define SHADERS_FILE_PATH "res/shader/Basic.shader"

const unsigned int WINWIDTH = 640, WINHEIGHT = 480;

int main(void) {
	// Configuration
	GLFWwindow* window;

	// Initialize glfw
	if (!glfwInit())
		return -1;

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
			-0.5f, -0.5f,
			 0.5f, -0.5f,
			 0.5f,  0.5f,
			-0.5f,  0.5f
		};

		// Indices of the positions in order of drawing
		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0
		};

		// VAs, VBs and IBs
		VertexArray VA;
		VertexBuffer VB(pos, 4 * 2 * sizeof(float));

		VertexBufferLayout layout;
		layout.Push<float>(2);
		VA.AddBuffer(VB, layout);

		IndexBuffer IB(indices, 6);

		// Create shaders
		Shader shader(SHADERS_FILE_PATH);

		// Setup logic

		float r = 1.0f;
		float i = 0.01f;

		// Main loop
		while (!glfwWindowShouldClose(window)) {
			// Rendering

			// Clear window - first because of first frame
			GLCall(glClear(GL_COLOR_BUFFER_BIT));

			// Bind stuff
			shader.Bind();
			shader.SetUniform4f("u_color", r, 0.0f, 0.7f, 0.5f);

			VA.Bind();
			IB.Bind();

			// Draw call
			GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

			// Loop logic

			if(r > 1.0f) i *= -1;
			else if(r < 0.0f) i *= -1;

			r += i;

			// Swap front and back buffers - show on screen
			glfwSwapBuffers(window);

			// Process events
			glfwPollEvents();
		}
	}
	glfwTerminate();
	return 0;
}