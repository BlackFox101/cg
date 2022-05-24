#pragma once
#include "BaseWindow.h"

class Window : public BaseWindow
{
public:
	Window(int w, int h, const char* title);

private:
	void OnRunStart() override;
	void OnResize(int width, int height) override;

	void Draw(int width, int height) override;
	void InitShaders();
	void InitUniform();

	GLuint m_program;
};