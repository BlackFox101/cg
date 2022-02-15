#include "Letter.h"

void Letter::Update(float deltaSeconds)
{
	m_positionX += SPEED_X * deltaSeconds;
	m_positionY += SPEED_Y * deltaSeconds;
}

void Letter::ReDraw(QPainter& painter)
{

}
