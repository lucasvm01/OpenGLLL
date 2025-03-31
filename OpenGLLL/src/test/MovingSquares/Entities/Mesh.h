#pragma once

#include<iostream>
#include <memory>
#include<string>
#include "../../../Texture.h"
#include "../../../Shader.h"
#include "../../../IndexBuffer.h"
#include "../../../VertexArray.h"

#include"../VertexBufferLayout.h"

namespace test {
	class Mesh {
	public:
		void SetPositionVertices(float* data);

		void ProcessVertices();

		void SetShader();

		std::unique_ptr<Shader> m_shader;
		std::unique_ptr<Texture> m_texture;

		std::unique_ptr<VertexArray> m_VAO;
		std::unique_ptr<VertexBuffer> m_VBO;
		std::unique_ptr<IndexBuffer> m_IBO;
		// void SetUniformMat4f(const std::string& name, glm::mat4 mvp);
		// void SetMPV ???

		void SetTexture();
	private:
		float* m_pos;
		unsigned int* m_indices;
	};
}