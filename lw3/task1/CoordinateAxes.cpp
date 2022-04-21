#include "CoordinateAxes.h"
#include "pch.h"

CoordinateAxes::CoordinateAxes(float maxX, float maxY, float divisionPrice)
	: m_maxX(maxX), m_maxY(maxY), m_divistionPrice(divisionPrice)
{
}

void CoordinateAxes::Draw()
{
	glBegin(GL_LINES);

	glVertex2f(-m_maxX, 0);
	glVertex2f(m_maxX, 0);

	glVertex2f(0, m_maxY);
	glVertex2f(0, -m_maxY);

	// вертикальная стрелка 
	glVertex2f(0, m_maxY);
	glVertex2f(m_maxX / 80, m_maxY - m_maxX / 15);
	glVertex2f(0, m_maxY);
	glVertex2f(-m_maxX / 80, m_maxY - m_maxX / 15);

	// горизонтальная стрелка 
	glVertex2f(m_maxX, 0);
	glVertex2f(m_maxX - m_maxX / 15, m_maxX / 80);
	glVertex2f(m_maxX, 0);
	glVertex2f(m_maxX - m_maxX / 15, -m_maxX / 80);

	float divisionPrice = m_maxX / 10;
	float divisionWidth = divisionPrice / 10;

	// Рисуем деления на оси X
	for (float x = 0; x < m_maxX; x += divisionPrice)
	{
		glVertex2f(x, divisionWidth);
		glVertex2f(x, -divisionWidth);
	}
	for (float x = 0; x > -m_maxX; x -= divisionPrice)
	{
		glVertex2f(x, divisionWidth);
		glVertex2f(x, -divisionWidth);
	}

	// Рисуем деления на оси Y
	for (float y = 0; y < m_maxY; y += divisionPrice)
	{
		glVertex2f(divisionWidth, y);
		glVertex2f(-divisionWidth, y);
	}
	for (float y = 0; y > -m_maxY; y -= divisionPrice)
	{
		glVertex2f(divisionWidth, y);
		glVertex2f(-divisionWidth, y);
	}

	glEnd();
}