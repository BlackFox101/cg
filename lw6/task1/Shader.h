#pragma once
#include "pch.h"

enum class ShaderType
{
	Vertex = GL_VERTEX_SHADER,
	Fragment = GL_FRAGMENT_SHADER,
};

class Shader
{
public:
	static GLuint LoadShader(std::string path, ShaderType Type);

private:
	static std::string GetShaderFromFile(std::string path);
};

