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

	// Setup entities
	{
		// Vertices
		float pos[] = {
			-0.5f, -0.5f,
			 0.5f, -0.5f,
			 0.5f,  0.5f,
			-0.5f,  0.5f
		};

		// Generate and bind a Vertex Array Object
		unsigned int VAO;
		GLCall(glGenVertexArrays(1, &VAO));
		GLCall(glBindVertexArray(VAO));

		// The constructor already binds it, so no need to call Bind()
		VertexArray VA;
		VertexBuffer VB(pos, 4 * 2 * sizeof(float));

		VertexBufferLayout layout;
		layout.Push<float>(2);
		VA.AddBuffer(VB, layout);


		// Indices of the positions in order of drawing
		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0
		};

		IndexBuffer IB(indices, 6);

		// Create shaders
		Shader shader(SHADERS_FILE_PATH);
		shader.Bind();
		shader.SetUniform4f("u_color", 0.8f, 0.0f, 0.7f, 0.5f);
		
		// Reset binds
		VA.Unbind();
		VB.Unbind();
		IB.Unbind();
		shader.Unbind();

		// Setup logic

		float r = 1.0f;
		float i = 0.05f;

		// Main loop
		while (!glfwWindowShouldClose(window)) {
			// Rendering

			// Clear window - first because of first frame
			GLCall(glClear(GL_COLOR_BUFFER_BIT));

			// Loop logic

			if (r < 1.0f) r += i;
			else r -= i;

			// Draw call
			shader.Bind();
			shader.SetUniform4f("u_color", r, 0.0f, 0.7f, 0.5f);

			VA.Bind();
			IB.Bind();

			GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

			// Process events
			GLCall(glfwPollEvents());

			// Swap front and back buffers - show on screen
			GLCall(glfwSwapBuffers(window));
		}
	}
	glfwTerminate();
	return 0;
}