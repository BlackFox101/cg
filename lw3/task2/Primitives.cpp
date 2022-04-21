#include "Primitives.h"

void DrawElliplse(glm::vec2 center, float xRadius, float yRadius, glm::vec3 color, float startAngle, float endAngle)
{
	//StrokeEllipse(center.x, center.y, xRadius, yRadius);

	const float step = static_cast<float>(2 * M_PI / 360);

	glColor3f(color.x, color.y, color.z);
	// ������ ����������� � ���� "�����" �� �������������
	glBegin(GL_TRIANGLE_FAN);
	// ��������� ����� ����� ������������� � ������ �������
	glVertex2d(center.x, center.y);
	// ��������� ����� - ���������� �� ��� �������
	for (float angle = startAngle; angle <= endAngle; angle += step)
	{
		float a = (fabsf(static_cast<float>(angle - 2 * M_PI)) < 1e-5) ? 0 : angle;
		const float dx = xRadius * cosf(a);
		const float dy = yRadius * sinf(a);
		glVertex2f(dx + center.x, dy + center.y);
	}
	glEnd();
}

void DrawRectangle(glm::vec2 leftTop, float width, float height, glm::vec3 color)
{
	glColor3f(color.x, color.y, color.z);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2d(leftTop.x, leftTop.y);
	glVertex2d(leftTop.x, leftTop.y + height);
	glVertex2d(leftTop.x + width, leftTop.y);
	glVertex2d(leftTop.x + width, leftTop.y + height);
	glEnd();
}

void DrawQuadrilateral(glm::vec2 v1, glm::vec2 v2, glm::vec2 v3, glm::vec2 v4, glm::vec3 color)
{
	glColor3f(color.x, color.y, color.z);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2d(v1.x, v1.y);
	glVertex2d(v2.x, v2.y);
	glVertex2d(v3.x, v3.y);
	glVertex2d(v4.x, v4.y);
	glEnd();
}

void DrawTriangle(glm::vec2 v1, glm::vec2 v2, glm::vec2 v3, glm::vec3 color)
{
	glColor3f(color.x, color.y, color.z);
	glBegin(GL_TRIANGLES);
	glVertex2d(v1.x, v1.y);
	glVertex2d(v2.x, v2.y);
	glVertex2d(v3.x, v3.y);
	glEnd();
}