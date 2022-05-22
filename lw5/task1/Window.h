#pragma once
#include "BaseWindow.h"
#include "AssimpModel.h"

class Window : public BaseWindow
{
public:
	Window(int w, int h, const char* title);

private:
	void OnRunStart() override;

	void OnMouseButton(int button, int action, [[maybe_unused]] int mods) override;
	void OnMouseMove(double x, double y) override;
	void OnResize(int width, int height) override;

	// ������� ������ ������ ������ ���������
	void RotateCamera(double xAngleRadians, double yAngleRadians);

	void Draw(int width, int height) override;
	void SetupCameraMatrix();

	AssimpModel m_assimpModel;

	// ���������� �� ������ �� ����� ��������
	static constexpr double DISTANCE_TO_ORIGIN = 3;

	bool m_leftButtonPressed = false;
	glm::dvec2 m_mousePos = {};
	glm::dmat4x4 m_cameraMatrix = glm::lookAt(
		glm::dvec3{ 0.0, 0.0, DISTANCE_TO_ORIGIN },
		glm::dvec3{ 0.0, 0.0, 0.0 },
		glm::dvec3{ 0.0, 1.0, 0.0 });
};