#pragma once
#include "BaseWindow.h"

struct Point
{
	float x, y;
};

class Window : public BaseWindow
{
public:
	using BaseWindow::BaseWindow;

	// TODO: обработать ресайз, уменьшать и увеличивать картинку
private:
	void OnMouseButton(int button, int action, [[maybe_unused]] int mods) override;
	void OnMouseMove(double x, double y) override;
	void OnRunStart() override;

	void Draw(int width, int height) override;
	void DrawByMove();

	bool m_leftButtonPressed = false;
	// TODO: Попробовать уменьшить кол-во переменных
	glm::vec2 m_mousePos = { 0, 0 };
	glm::vec2 m_mousePressPos = { 0, 0 };
	glm::vec2 m_offset = { 0, 0 };
	glm::vec2 m_lastOffset = { 0, 0 };
};