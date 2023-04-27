#pragma once

#include<GLAD/glad.h>
#include"GLFW/glfw3.h"

#include"VertexArray.h"
#include"VertexBuffer.h"
#include"IndexBuffer.h"

#include"Shader.h"

// Macro for error checking
#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();	x;	ASSERT(GLLogCall(#x, __FILE__, __LINE__)) 

void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);

class Renderer {
public:
	void Draw(const VertexArray& VA, const IndexBuffer& IB, const Shader& shader) const;
	void Clear() const;
};