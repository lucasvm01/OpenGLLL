#pragma once

#include<string>
#include<unordered_map>

#include"glm/glm.hpp"

struct ShaderProgramSource {
	std::string VertexSource;
	std::string FragmentSource;
};

class Shader {
private:
	const std::string m_Filepath;
	unsigned int m_RendederID;
	std::unordered_map<std::string, int> m_UniformLocationCache;
public:
	Shader(const std::string& filepath);
	~Shader();

	void Bind() const;
	void Unbind() const;

	// Set uniforms
	void SetUniform1i(const std::string& name, int value);
	void SetUniform1f(const std::string& name, float value);
	void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	void SetUniformMat4f(const std::string& name, glm::mat4& matrix);
private:
	ShaderProgramSource ParseShaderFile(const std::string& filepath);
	int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	int CompileShader(unsigned int type, const std::string& source);
	int GetUniformLocation(const std::string& name);
};