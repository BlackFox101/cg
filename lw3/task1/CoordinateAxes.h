#pragma once

class CoordinateAxes
{
public:
	CoordinateAxes(float maxX, float maxY, float divisionPrice);
	void Draw();

private:
	float m_divistionPrice;
	float m_maxX;
	float m_maxY;
};

