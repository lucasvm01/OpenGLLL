#include"Renderer.h"

#include<iostream>

void GLClearError() {
	while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line) {
	if (GLenum error = glGetError()) {
		std::cout << "[OpenGL Error] (" << error << "): " << function << " at line " << line << " in " << file << std::endl;
		return false;
	};
	return true;
}

void Renderer::Draw(const VertexArray& VA, const IndexBuffer& IB, const Shader& shader) const
{
	// Bind stuff
	//shader.Bind();
	VA.Bind();
	IB.Bind();

	// Draw call
	GLCall(glDrawElements(GL_TRIANGLES, IB.GetCount(), GL_UNSIGNED_INT, nullptr));

}

void Renderer::Clear() const
{
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}
