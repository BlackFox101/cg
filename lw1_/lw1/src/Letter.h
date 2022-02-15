#pragma once
#include <QGraphicsItem>

class Letter : public QGraphicsItem
{
public:
    void Update(float deltaSeconds);
    void ReDraw(QPainter& painter);

private:
    float m_positionX = 0;
    float m_positionY = 0;

    const float SPEED_X = 50;
    const float SPEED_Y = 60;
};

