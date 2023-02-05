#pragma once

#include<string>

struct ShaderProgramSource {
	std::string VertexSource;
	std::string FragmentSource;
};

class Shader {
private:
	const std::string& m_Filepath;
	unsigned int m_RendederID;
public:
	Shader(const std::string& filepath);
	~Shader();

	void Bind() const;
	void Unbind() const;

	// Set uniforms
	void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
private:
	ShaderProgramSource ParseShaderFile(const std::string& filepath);
	int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	int CompileShader(unsigned int type, const std::string& source);
	int GetUniformLocation(const std::string& name);
};