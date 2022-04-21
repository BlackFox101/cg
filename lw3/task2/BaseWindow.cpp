#include "BaseWindow.h"

BaseWindow::BaseWindow(int w, int h, const char* title)
	: m_window{ MakeWindow(w, h, title) }
{
	if (!m_window)
	{
		throw std::runtime_error("Failed to create window");
	}

	glfwSetWindowUserPointer(m_window, this);

	glfwSetWindowSizeCallback(m_window,
		[](GLFWwindow* window, int width, int height) {
			GetBaseWindow(window)->OnResize(width, height);
		});

	glfwSetMouseButtonCallback(m_window,
		[](GLFWwindow* window, int button, int action, int mods) {
			GetBaseWindow(window)->OnMouseButton(button, action, mods);
		});

	glfwSetCursorPosCallback(m_window,
		[](GLFWwindow* window, double x, double y) {
			GetBaseWindow(window)->OnMouseMove(x, y);
		});
}

BaseWindow::~BaseWindow()
{
	glfwDestroyWindow(m_window);
}

void BaseWindow::Run()
{
	glfwMakeContextCurrent(m_window);
	OnRunStart();

	while (!glfwWindowShouldClose(m_window))
	{
		int w, h;
		glfwGetFramebufferSize(m_window, &w, &h);
		Draw(w, h);
		glFinish();

		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}
	OnRunEnd();
}

BaseWindow* BaseWindow::GetBaseWindow(GLFWwindow* window)
{
	return reinterpret_cast<BaseWindow*>(glfwGetWindowUserPointer(window));
}

GLFWwindow* BaseWindow::MakeWindow(int w, int h, const char* title)
{
	glfwWindowHint(GLFW_DEPTH_BITS, 24);
	return glfwCreateWindow(w, h, title, nullptr, nullptr);
}


glm::ivec2 BaseWindow::GetFramebufferSize() const
{
	int w, h;
	glfwGetFramebufferSize(m_window, &w, &h);
	return { w, h };
}

GLFWwindow* BaseWindow::GetWindow()
{
	return m_window;
}