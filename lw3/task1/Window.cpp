#include "Window.h"
#include "CoordinateAxes.h"
#include "Parabola.h"

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
	const float maxY = 15;
	const float maxX = width * maxY / height;
	glOrtho(-maxX, maxX, -maxY, maxY, -1, 1);
	glMatrixMode(GL_MODELVIEW);

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0, 0, 0);
	// Поправить цену деления
	CoordinateAxes axes(maxX, maxY, 10);
	axes.Draw();

	glColor3f(0, 0, 1);
	Parabola parabola(2, -3, -8);
	DrawFunction(parabola, -4, 4);
}

void DrawFunction(const IFunction& function, float left, float right)
{
	glBegin(GL_LINE_STRIP);

	for (float x = left; x < right; x += 0.01)
	{
		glVertex2f(x, function.GetYByX(x));
	}

	glEnd();
}