#include "Parabola.h"

Parabola::Parabola(float a, float b, float c)
	: m_a(a), m_b(b), m_c(c)
{}

float Parabola::GetYByX(float x) const
{
	return m_a * x * x + m_b * x + m_c;
}