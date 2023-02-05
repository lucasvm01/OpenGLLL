#include "Shader.h"

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

#include"Renderer.h"

Shader::Shader(const std::string& filepath) : 
		m_Filepath(filepath), m_RendederID(0){
	ShaderProgramSource source = ParseShaderFile(filepath);
	m_RendederID = CreateShader(source.VertexSource, source.FragmentSource);
}

Shader::~Shader()
{
	GLCall(glDeleteProgram(m_RendederID));
}

// Parse the content of the shader file
ShaderProgramSource Shader::ParseShaderFile(const std::string& filepath) {
	enum class ShaderType {
		NONE = -1, VERTEX = 0, FRAGMENT = 1,
	};

	std::ifstream stream(filepath);

	if (!stream) {
		std::cout << "Could not find shaders filepath." << std::endl;
	}

	std::string line;
	std::stringstream ss[2];
	ShaderType type = ShaderType::NONE;

	while (getline(stream, line)) {
		if (line.find("#shader") != std::string::npos) {
			if (line.find("vertex") != std::string::npos)
				type = ShaderType::VERTEX;
			else if (line.find("fragment") != std::string::npos)
				type = ShaderType::FRAGMENT;
		}
		else {
			ss[(int)type] << line << '\n';
		}
	}

	return { ss[0].str(), ss[1].str() };
}

// Create the specified shaders
int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader) {
	// Generate a program id for the shaders
	unsigned int program = glCreateProgram();
	// Compile vertex shader
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	if (vs == 0) return -1;
	glAttachShader(program, vs);

	// Compile fragment shader
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);
	if (fs == 0) return -1;
	glAttachShader(program, fs);

	// Link shaders in the program
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

// Compile each shader
int Shader::CompileShader(unsigned int type, const std::string& source) {
	// Generate a shader
	unsigned int id = glCreateShader(type);
	// Cast the string to char*
	const char* src = source.c_str();
	// Bind source to the shader
	glShaderSource(id, 1, &src, nullptr);
	// Compile it
	glCompileShader(id);

	// Error handling
	// Check if shader compiled succesfully
	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);

		std::cout << "Failed to compile shader." << std::endl;
		std::cout << message << std::endl;

		glDeleteShader(id);
		return 0;
	}

	return id;
}

void Shader::Bind() const{
	GLCall(glUseProgram(m_RendederID));
}

void Shader::Unbind() const{
	GLCall(glUseProgram(0));
}

void Shader::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3){
	GLCall(glUniform4f(GetUniformLocation(name), v0, v1, v2, v3));
}

int Shader::GetUniformLocation(const std::string& name){
	GLCall(int location = glGetUniformLocation(m_RendederID, name.c_str()));
	if (location == -1) {
		std::cout << "Warning: uniform '" << name << "' doesn't exist." << std::endl;
	}
	return location;
}
