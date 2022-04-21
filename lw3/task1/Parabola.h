#pragma once
#include "IFunction.h"

class Parabola : public IFunction
{
public:
	Parabola(float a, float b, float c);
	float GetYByX(float x) const override;
private:
	float m_a, m_b, m_c;
};

