#pragma once
#include "pch.h"

struct Face
{
	size_t vertices[3];
};

struct Vertex
{
	glm::vec3 pos;
	glm::vec3 normal;
	glm::vec2 texCoords;
};

class Mesh
{
public:
	Mesh(std::vector<Vertex> vertices, std::vector<Face> faces);
	
	void Draw();

private:
	std::vector<Vertex> m_vertices;

	std::vector<Face> m_faces;
};