#pragma once
#include <memory>
#include "../../../VertexArray.h"
#include "../../../IndexBuffer.h"
#include "../../../Shader.h"
#include "../../../Texture.h"

namespace test {
	class BaseEntity {
	public:

	private:
		std::unique_ptr<VertexArray> m_VAO;
		std::unique_ptr<VertexBuffer> m_VBO;
		std::unique_ptr<IndexBuffer> m_IBO;

		std::unique_ptr<Shader> m_shader;
		std::unique_ptr<Texture> m_texture;

	};
}