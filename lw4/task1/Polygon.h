#pragma once
#include "pch.h"

enum class CubeSide
{
	NEGATIVE_X,
	POSITIVE_X,
	NEGATIVE_Y,
	POSITIVE_Y,
	NEGATIVE_Z,
	POSITIVE_Z,
};

namespace
{
	static const float m_fi = (1 + std::sqrt(5)) / 2;
} // namespace

class Polygon // Snub Dodecahedron
{
public:
	explicit Polygon(float size = 1);
	void Draw() const;

	void SetSideColor(CubeSide side, const glm::vec4& color);
	void SetSpecularColor(glm::vec4 color);
	void SetShininess(float shininess);

private:
	float m_size;
	glm::vec4 m_sideColors[6];
	glm::vec4 m_specularColor = { 0, 0, 0, 1 };
	float m_shininess = 0.5;

	const float fi = (1 + sqrt(5)) / 2;
	const float e = 1.7155615;
	const float a = e - 1 / e;
	const float b = e * fi + fi * fi + fi / e;

	const float a1 = 2 * a;
	const float b1 = 2;
	const float c1 = 2 * b;

	const float a2 = a + b / fi + fi;
	const float b2 = -a * fi + b + 1 / fi;
	const float c2 = a / fi + b * fi - 1;

	const float a3 = a + b / fi - fi;
	const float b3 = a * fi - b + 1 / fi;
	const float c3 = a / fi + b * fi + 1;

	const float a4 = -a / fi + b * fi + 1;
	const float b4 = -a + b / fi - fi;
	const float c4 = a * fi + b - 1 / fi;

	const float a5 = -a / fi + b * fi - 1;
	const float b5 = a - b / fi - fi;
	const float c5 = a * fi + b + 1 / fi;

	// Массив координат вершин
	const float m_vertices[60][3] = {
		// (+-2a, +-2, +-2b),
		{  a1,  b1, -c1 },
		{  a1,  c1, -b1 },
		{  b1, -c1,  a1 },
		{  b1,  c1, -a1 },
		{  c1, -b1,  a1 },
		{  c1, -a1,  b1 },
		{ -c1, -b1, -a1 },
		{ -c1,  a1,  b1 },
		{ -b1, -a1, -c1 },
		{ -b1,  a1,  c1 },
		{ -a1, -c1, -b1 },
		{ -a1,  b1,  c1 },
		//(+-(a+b/fi+fi), +-(-a*fi+b+1/fi), +-(a/fi+b*fi-1))
		{  a2,  b2, -c2 },
		{  a2,  c2, -b2 },
		{  b2, -c2,  a2 },
		{  b2,  c2, -a2 },
		{  c2, -b2,  a2 },
		{  c2, -a2,  b2 },
		{ -c2, -b2, -a2 },
		{ -c2,  a2,  b2 },
		{ -b2, -a2, -c2 },
		{ -b2,  a2,  c2 },
		{ -a2, -c2, -b2 },
		{ -a2,  b2,  c2 },
		//(+-(a+b/fi-fi), +-(a*fi-b+1/fi), +-(a/fi+b*fi+1))
		{  a3,  b3, -c3 },
		{  a3,  c3, -b3 },
		{  b3, -c3,  a3 },
		{  b3,  c3, -a3 },
		{  c3, -b3,  a3 },
		{  c3, -a3,  b3 },
		{ -c3, -b3, -a3 },
		{ -c3,  a3,  b3 },
		{ -b3, -a3, -c3 },
		{ -b3,  a3,  c3 },
		{ -a3, -c3, -b3 },
		{ -a3,  b3,  c3 },
		//(+-(-a/fi+b*fi+1), +-(-a+b/fi-fi), +-(a*fi+b-1/fi))
		{  a4,  b4, -c4 },
		{  a4,  c4, -b4 },
		{  b4, -c4,  a4 },
		{  b4,  c4, -a4 },
		{  c4, -b4,  a4 },
		{  c4, -a4,  b4 },
		{ -c4, -b4, -a4 },
		{ -c4,  a4,  b4 },
		{ -b4, -a4, -c4 },
		{ -b4,  a4,  c4 },
		{ -a4, -c4, -b4 },
		{ -a4,  b4,  c4 },
		//(+-(-a/fi+b*fi-1), +-(a-b/fi-fi), +-(a*fi+b+1/fi))
		{  a5,  b5, -c5 },
		{  a5,  c5, -b5 },
		{  b5, -c5,  a5 },
		{  b5,  c5, -a5 },
		{  c5, -b5,  a5 },
		{  c5, -a5,  b5 },
		{ -c5, -b5, -a5 },
		{ -c5,  a5,  b5 },
		{ -b5, -a5, -c5 },
		{ -b5,  a5,  c5 },
		{ -a5, -c5, -b5 },
		{ -a5,  b5,  c5 },
	};

};