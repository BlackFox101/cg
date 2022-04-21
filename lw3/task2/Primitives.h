#pragma once
#include "pch.h"

void DrawTriangle(glm::vec2 v1, glm::vec2 v2, glm::vec2 v3, glm::vec3 color);

void DrawElliplse(glm::vec2 center, float xRadius, float yRadius, glm::vec3 color, float rotationAngle = 0, float startAngle = 0, float endAngle = 2 * M_PI);

void DrawRectangle(glm::vec2 leftTop, float width, float height, glm::vec3 color);

void DrawQuadrilateral(glm::vec2 v1, glm::vec2 v2, glm::vec2 v3, glm::vec2 v4, glm::vec3 color);