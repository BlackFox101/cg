#pragma once
#include "BaseWindow.h"
#include "IFunction.h"

class Window : public BaseWindow
{
public:
	using BaseWindow::BaseWindow;

private:
	// TODO: отдельный класс при для параболы, для координатной оси(мин шаг + параметры)
	void OnRunStart() override;
	void Draw(int width, int height) override;
	//void DrawFunction(std::shared_ptr<IFunction> function, float left, float right);
};