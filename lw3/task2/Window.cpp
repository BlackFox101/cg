#include "Window.h"
#include "Picture.h"
#include "Primitives.h"

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
	glOrtho(0, width, height, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 1);
	DrawByMove();
}

void Window::OnMouseButton(int button, int action, [[maybe_unused]] int mods)
{
	if (button == GLFW_MOUSE_BUTTON_1)
	{
		bool isPressed = m_leftButtonPressed;
		m_leftButtonPressed = (action & GLFW_PRESS) != 0;

		if (!isPressed && m_leftButtonPressed)
		{
			double xpos, ypos;
			glfwGetCursorPos(GetWindow(), &xpos, &ypos);
			m_mousePressPos.x = xpos;
			m_mousePressPos.y = ypos;
		}

		if (isPressed && !m_leftButtonPressed)
		{
			m_lastOffset += m_offset;
			m_offset = { 0, 0 };
		}
	}
}

void Window::OnMouseMove(double x, double y)
{
	if (m_leftButtonPressed)
	{
		m_mousePos = { x, y };
		m_offset = m_mousePos - m_mousePressPos;
	}
}

void Window::DrawByMove()
{
	glPushMatrix();
	glTranslatef(m_lastOffset.x + m_offset.x, m_lastOffset.y + m_offset.y, 0);
	Picture picture;
	picture.Draw();
	glPopMatrix();
}