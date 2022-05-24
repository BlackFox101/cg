#include "Shader.h"

GLuint Shader::LoadShader(std::string path, ShaderType Type)
{
	auto str = GetShaderFromFile(path);
	GLchar const* sh = str.c_str();

	GLuint shader = glCreateShader((int)Type);
	glShaderSource(shader, 1, &sh, NULL);
	glCompileShader(shader);

	GLint compileStatus;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compileStatus);
	if (!compileStatus)
	{
		char infoLog[512];
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		glDeleteShader(shader);
		throw std::runtime_error(infoLog);
	}

	return shader;
}

std::string Shader::GetShaderFromFile(std::string path)
{
	std::ifstream stream(path);
	if (!stream.is_open())
	{
		throw std::runtime_error("Can't open shader file");
	}
	// Копируем данные из файлового потока в строковый поток
	std::stringstream strStream;
	strStream << stream.rdbuf();

	return strStream.str();
}