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

private:
	void OnRunStart() override;
	void Draw(int width, int height) override;
	void BuildCoordinateAxes(float maxX, float maxY);
	void DrawParabola(float leftX, float rightX);
	float Parabola(float x);
};