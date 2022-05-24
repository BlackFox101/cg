#include "Window.h"
#include "Shader.h"

namespace
{
// Угол обзора по вертикали
constexpr double FIELD_OF_VIEW = 60 * M_PI / 180.0;

constexpr double Z_NEAR = 0.1;
constexpr double Z_FAR = 10;

// Ортонормируем матрицу 4*4 (это должна быть аффинная матрица)
glm::dmat4x4 Orthonormalize(const glm::dmat4x4& m)
{
	// Извлекаем подматрицу 3*3 из матрицы m и ортонормируем её
	const auto normalizedMatrix = glm::orthonormalize(glm::dmat3x3{ m });
	// Заменяем 3 столбца исходной матрицы
	return {
		glm::dvec4{ normalizedMatrix[0], 0.0 },
		glm::dvec4{ normalizedMatrix[1], 0.0 },
		glm::dvec4{ normalizedMatrix[2], 0.0 },
		m[3]
	};
}
} //namespace

Window::Window(int w, int h, const char* title)
	: BaseWindow(w, h, title)
	, m_program(0)
{
}

void Window::OnRunStart()
{
	glClearColor(1, 1, 1, 1);
	glewInit();

	InitShaders();
}

void Window::OnResize(int width, int height)
{
	glViewport(0, 0, width, height);

	// Вычисляем соотношение сторон клиентской области окна
	double aspect = double(width) / double(height);

	glMatrixMode(GL_PROJECTION);
	const auto proj = glm::perspective(FIELD_OF_VIEW, aspect, Z_NEAR, Z_FAR);
	glLoadMatrixd(&proj[0][0]);
	glMatrixMode(GL_MODELVIEW);
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

	glUseProgram(m_program);
	InitUniform();

	glBegin(GL_QUADS);
	{
		glVertex2f(0, 0);
		glVertex2f(width, 0);
		glVertex2f(width, height);
		glVertex2f(0, height);
	}
	glEnd();

	glUseProgram(0);
}


void Window::InitShaders()
{
	// Создаем фрагментный шейдер шейдер
	GLuint fragShader = Shader::LoadShader("shaders/FS.glsl", ShaderType::Fragment);

	// Создаем программу
	m_program = glCreateProgram();

	// Присоединяем к ней шейдер
	glAttachShader(m_program, fragShader);
	glLinkProgram(m_program);

	GLint linkStatus;
	glGetProgramiv(m_program, GL_LINK_STATUS, &linkStatus);

	if (linkStatus != GL_TRUE)
	{
		glDeleteProgram(m_program);
		throw std::runtime_error("Cannot link program");
	}
}

void Window::InitUniform()
{
	auto windowSize = GetFramebufferSize();

	GLint widhtLocation = glGetUniformLocation(m_program, "v_widht");
	glUniform1f(widhtLocation, windowSize.x);

	GLint heightLocation = glGetUniformLocation(m_program, "v_height");
	glUniform1f(heightLocation, windowSize.y);
}