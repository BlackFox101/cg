#pragma once
#include "pch.h"

struct Edge
{
	std::vector<int> pointsNumber;
	glm::vec3 color;
};

namespace
{
	static const float m_fi = (1 + std::sqrt(5)) / 2;
    float CubicRoot(float number)
    {
        return pow(number, 1.0 / 3.0);
    }
} // namespace

class Polygon // Snub Dodecahedron
{
public:
	explicit Polygon(float size = 1);
	void Draw() const;

	//void SetSideColor(CubeSide side, const glm::vec4& color);
	void SetSpecularColor(glm::vec4 color);
	void SetShininess(float shininess);

private:
	float m_size;
	glm::vec4 m_specularColor = { 0, 0, 0, 1 };
	float m_shininess = 0.5;
    
	double b = (1.0 + sqrt(2));
	double c = (1.0 + 2.0 * sqrt(2));

	// Массив координат вершин
	const double m_vertices[48][3] = {
		{-c, -b, -1}, // 0
		{-c, -1, -b}, // 1
		{-b, -c, -1}, // 2
		{-b, -1, -c}, // 3
		{-1, -c, -b}, // 4
		{-1, -b, -c}, // 5
		{-b, -1,  c}, // 6
		{-b,  c, -1}, // 7
		{-1, -b,  c}, // 8
		{-1,  c, -b}, // 9
		{ c, -b, -1}, // 10
		{ c, -1, -b}, // 11
		{-c, -1,  b}, // 12
		{-c,  b, -1}, // 13
		{-1, -c,  b}, // 14
		{-1,  b, -c}, // 15
		{ b, -c, -1}, // 16
		{ b, -1, -c}, // 17
		{-1,  b,  c}, // 18
		{-1,  c,  b}, // 19
		{ b, -1,  c}, // 20
		{ b,  c, -1}, // 21
		{ c, -1,  b}, // 22
		{ c,  b, -1}, // 23
		{-c, -b,  1}, // 24
		{-c,  1, -b}, // 25
		{-b, -c,  1}, // 26
		{-b,  1, -c}, // 27
		{ 1, -c, -b}, // 28
		{ 1, -b, -c}, // 29
		{-b,  1,  c}, // 30
		{-b,  c,  1}, // 31
		{ 1, -b,  c}, // 32
		{ 1,  c, -b}, // 33
		{ c, -b,  1}, // 34
		{ c,  1, -b}, // 35
		{-c,  1,  b}, // 36
		{-c,  b,  1}, // 37
		{ 1, -c,  b}, // 38
		{ 1,  b, -c}, // 39
		{ b, -c,  1}, // 40
		{ b,  1, -c}, // 41
		{ 1,  b,  c}, // 42
		{ 1,  c,  b}, // 43
		{ b,  1,  c}, // 44
		{ b,  c,  1}, // 45
		{ c,  1,  b}, // 46
		{ c,  b,  1}, // 47
    };

	glm::vec3 red = { 1, 0, 0 };
	glm::vec3 green = { 0, 1, 0 };
	glm::vec3 blue = { 0, 0, 1 };
	glm::vec3 yellow = { 1, 1, 0 };

	const std::vector<Edge> m_faces = {
		{{ 0, 1, 3, 5, 4, 2 }, { 1, 0.5, 0 }},
		{{ 0, 2, 26, 24 }, blue},
		{{ 29, 28, 4, 5 }, blue},
		{{ 25, 27, 3, 1 }, blue},
		{{ 43, 19, 18, 42 }, blue},
		{{ 41,35, 11, 17 }, blue},
		{{ 21, 45, 47, 23 }, blue},
		{{ 46, 44, 20, 22 }, blue},
		{{ 13, 37, 31, 7}, blue},
		{{ 33, 39, 15, 9}, blue},
		{{ 40, 16, 10, 34}, blue},
		{{ 6, 30, 36, 12}, blue},
		{{ 14, 38, 32, 8}, blue},
		{{ 47, 46, 22, 34, 10, 11, 35, 23}, green},
		{{ 41, 17, 29, 5, 3, 27, 15, 39 }, green},
		{{ 9, 7, 31, 19, 43, 45, 21, 33 }, green},
		{{ 26, 2, 4, 28, 16, 40, 38, 14}, green},
		{{ 20, 44, 42, 18, 30, 6, 8, 32}, green},
		{{ 24, 12, 36, 37, 13, 25, 1, 0 }, green},
		{{ 19, 31, 37, 36, 30, 18}, red},
		{{ 11, 10, 16, 28, 29, 17}, red},
		{{ 27, 25, 13, 7, 9, 15}, red},
		{{ 21, 23, 35, 41, 39, 33}, red},
		{{ 6, 12, 24, 26, 14, 8}, red},
		{{ 38, 40, 34, 22, 20, 32}, red},
		{{ 47, 45, 43, 42, 44, 46 }, yellow},
	};
};