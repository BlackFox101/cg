#include "Polygon.h"

Polygon::Polygon(float size)
	: m_size(size)
{
	constexpr glm::vec4 defaultColor{ 1, 1, 1, 1 };
	SetSideColor(CubeSide::NEGATIVE_X, defaultColor);
	SetSideColor(CubeSide::POSITIVE_X, defaultColor);
	SetSideColor(CubeSide::NEGATIVE_Y, defaultColor);
	SetSideColor(CubeSide::POSITIVE_Y, defaultColor);
	SetSideColor(CubeSide::NEGATIVE_Z, defaultColor);
	SetSideColor(CubeSide::POSITIVE_Z, defaultColor);
}

void Polygon::Draw() const
{
	glEnable(GL_COLOR_MATERIAL);
	// ÷вет вершины будет управл€ть диффузным и фоновым цветом материала
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, glm::value_ptr(m_specularColor));
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, m_shininess);

	glColor4f(0, 0, 0, 1);
	glBegin(GL_TRIANGLE_STRIP);
	{
		for (size_t i = 0; i < 60; i++)
		{
			auto vectex = glm::make_vec3(m_vertices[i]) * 0.1;
			glVertex3fv(glm::value_ptr(vectex));
		}
	}
	glEnd();
}

void Polygon::SetSideColor(CubeSide side, const glm::vec4& color)
{
	unsigned index = static_cast<unsigned>(side);
	m_sideColors[index] = color;
}

void Polygon::SetSpecularColor(glm::vec4 color)
{
	m_specularColor = color;
}

void Polygon::SetShininess(float shininess)
{
	m_shininess = shininess;
}

std::vector<glm::vec3> GetEdges()
{
	return {};
}