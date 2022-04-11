#include "Window.h"

void Window::OnRunStart()
{
	// Задаем цвет очистки буфера кадра
	glClearColor(1, 1, 1, 1);
}

void Window::Draw(int width, int height)
{
	// Настраиваем порт просмотра
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Размеры координатных осей
	const float maxX = 15;
	const float maxY = height * maxX / width;
	glOrtho(-maxX, maxX, -maxY, maxY, -1, 1);
	glMatrixMode(GL_MODELVIEW);

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0, 0, 0);
	BuildCoordinateAxes(maxX, maxY);

	glColor3f(0, 0, 1);
	DrawParabola(-4, 4);
}

void Window::BuildCoordinateAxes(float maxX, float maxY)
{
	glBegin(GL_LINES);


	glVertex2f(-maxX, 0);
	glVertex2f(maxX, 0);

	glVertex2f(0, maxY);
	glVertex2f(0, -maxY);

	// вертикальная стрелка 
	glVertex2f(0, maxY);
	glVertex2f(maxX / 80, maxY - maxX / 15);
	glVertex2f(0, maxY);
	glVertex2f(-maxX / 80, maxY - maxX / 15);

	// горизонтальная стрелка 
	glVertex2f(maxX, 0);
	glVertex2f(maxX - maxX / 15, maxX / 80);
	glVertex2f(maxX, 0);
	glVertex2f(maxX - maxX / 15, -maxX / 80);

	float divisionPrice = maxX / 10;
	float divisionWidth = divisionPrice / 10;

	// Рисуем деления на оси X
	for (float x = 0; x < maxX; x += divisionPrice)
	{
		glVertex2f(x, divisionWidth);
		glVertex2f(x, -divisionWidth);
	}
	for (float x = 0; x > -maxX; x -= divisionPrice)
	{
		glVertex2f(x, divisionWidth);
		glVertex2f(x, -divisionWidth);
	}

	// Рисуем деления на оси Y
	for (float y = 0; y < maxY; y += divisionPrice)
	{
		glVertex2f(divisionWidth, y);
		glVertex2f(-divisionWidth, y);
	}
	for (float y = 0; y > -maxY; y -= divisionPrice)
	{
		glVertex2f(divisionWidth, y);
		glVertex2f(-divisionWidth, y);
	}

	glEnd();
}

void Window::DrawParabola(float leftX, float rightX)
{
	glBegin(GL_LINE_STRIP);

	for (float x = leftX; x < rightX; x += 0.01)
	{
		glVertex2f(x, Parabola(x));
	}
	glEnd();
}

float Window::Parabola(float x)
{
	return ((2 * x) * (2 * x)) - (3 * x) - 8;
}