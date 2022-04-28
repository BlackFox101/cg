#include "Polygon.h"
#include "ConvexHull.h"

float GetDistance(glm::vec3 p1, glm::vec3 p2)
{
	float a = (p2.x - p1.x);
	float b = (p2.y - p1.y);
	float c = (p2.z - p1.z);

	return sqrt(a * a + b * b + c * c);
}

float GetDistance(float p1[3], float p2[3])
{
	float a = (p2[0] - p1[0]);
	float b = (p2[1] - p1[1]);
	float c = (p2[2] - p1[2]);

	return sqrt(a * a + b * b + c * c);
}

Polygon::Polygon(float size)
	: m_size(size)
{

}

std::vector<double> operator*(const std::vector<double>& vector, float coef)
{
	std::vector<double> newVector;
	for (auto value : vector)
	{
		newVector.push_back(value * coef);
	}
	return newVector;
}

void Polygon::Draw() const
{
	glEnable(GL_COLOR_MATERIAL);
	// Цвет вершины будет управлять диффузным и фоновым цветом материала
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, glm::value_ptr(m_specularColor));
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, m_shininess);

	for (size_t i = 0; i < m_faces.size(); i++)
	{
		const auto face = m_faces[i];
		// устанавливаем диффузный и фоновый цвет грани
		glColor4fv(glm::value_ptr(face.color));

		// получаем вершины очередной грани куба
		std::vector<glm::vec3> vertices;
		for (auto number : face.pointsNumber)
		{
			vertices.push_back(glm::make_vec3(m_vertices[number]) * 0.2);
		}
			
		// Вычисляем нормаль к грани через
		// векторное произведение его смежных сторон
		auto v01 = vertices[1] - vertices[0];
		auto v02 = vertices[2] - vertices[0];
		auto normal = glm::normalize(glm::cross(v01, v02));

		glNormal3fv(glm::value_ptr(normal));

		glBegin(GL_POLYGON);
		{
			for (auto vertex : vertices)
			{
				glVertex3fv(glm::value_ptr(vertex));
			}
		}
		glEnd();

		glColor4f(0, 0, 0, 1);
		glBegin(GL_LINE_LOOP);
		{
			for (auto vertex : vertices)
			{
				glVertex3fv(glm::value_ptr(vertex));
			}
		}
		glEnd();
	}
}

void Polygon::SetSpecularColor(glm::vec4 color)
{
	m_specularColor = color;
}

void Polygon::SetShininess(float shininess)
{
	m_shininess = shininess;
}

const std::vector<Edge> m_faces = {
	{{ 0, 1, 3, 4, 2 }, { 1, 0, 0 }},

	{{ 47, 46, 44, 43, 45 }, {1 , 0, 0 }},
};