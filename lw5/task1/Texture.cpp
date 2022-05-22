#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

GLuint Texture::LoadTexture(std::string pathToTexture)
{
	GLuint textureName;
	// ���������� ���� ���������� ������������� ����������� �������
	glGenTextures(1, &textureName);
	// ������ �������� ���������� ������ � ������ ���������������
	// (� ��� ��� ���� �� ������� ������� �����������)
	glBindTexture(GL_TEXTURE_2D, textureName);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, comp;
	unsigned char* data = stbi_load(pathToTexture.c_str(), &width, &height, &comp, 0);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height,
		0, comp == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
	stbi_image_free(data);

	return textureName;
}
