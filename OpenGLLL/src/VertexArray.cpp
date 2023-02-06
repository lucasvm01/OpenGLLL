#include"Renderer.h"

#include"VertexArray.h"
#include"VertexBufferLayout.h"

VertexArray::VertexArray(){
	GLCall(glGenVertexArrays(1, &m_RendererID));
}

VertexArray::~VertexArray(){
	GLCall(glDeleteVertexArrays(1, &m_RendererID));
}

void VertexArray::AddBuffer(const VertexBuffer& VB, const VertexBufferLayout& layout)
{
	Bind();
	VB.Bind();
	const auto& elements = layout.GetElements();
	unsigned int offset = 0;
	for (unsigned int i = 0; i < elements.size(); i++) {
		const auto& element = elements[i];

		// Define and enable an attribute to the vertex (position - x, y - and others)
		GLCall(glEnableVertexAttribArray(i));
		GLCall(glVertexAttribPointer(i, element.count, element.type, element.isNormalized, layout.GetStride(), (const void*)offset));

		offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
	}
}

void VertexArray::Bind() const{
	GLCall(glBindVertexArray(m_RendererID));
}

void VertexArray::Unbind() const{
	GLCall(glBindVertexArray(0));
}