#include "Window.h"

int main()
{
	GLFWInitializer initGLFW;
	Window window{ 800, 600, "Hello, triangle" };
	window.Run();
}
