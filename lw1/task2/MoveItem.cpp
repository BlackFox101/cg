#include "MoveItem.h"
#include <QPainter>
#include <QCursor>
#include <QPointF>

MoveItem::MoveItem()
    : QGraphicsItemGroup()
{
	addToGroup(GetHouse());
	addToGroup(GetFence());
}

QGraphicsItem* MoveItem::GetHouse() const
{
	auto house = new QGraphicsItemGroup();

	auto footing = new QGraphicsRectItem(150, 150, 150, 150);
	footing->setBrush(QColor(145, 130, 30));

	auto pipe = new QGraphicsRectItem(260, 70, 20, 60);
	pipe->setBrush(QColor(150, 75, 0));

	QPolygonF d;
	d << QPointF(150, 150) << QPointF(300, 150) << QPointF(225, 50);
	auto roof = new QGraphicsPolygonItem(d);
	roof->setBrush(QColor(255, 0, 0));

	auto door = new QGraphicsRectItem(250, 230, 35, 70);
	door->setBrush(QColor(110, 50, 0));

	auto doorPen = new QGraphicsEllipseItem(255, 270, 5, 5);
	doorPen->setBrush(QColor(0, 0, 0));

	auto window = new QGraphicsRectItem(170, 210, 50, 50);
	window->setBrush(QColor(255, 255, 255));

	house->addToGroup(footing);
	house->addToGroup(pipe);
	house->addToGroup(roof);
	house->addToGroup(door);
	house->addToGroup(doorPen);
	house->addToGroup(window);

	return house;
}

QGraphicsItem* MoveItem::GetFence() const
{
	auto fence = new QGraphicsItemGroup();
	QPen brownPen(QColor(230, 155, 60));
	brownPen.setWidth(0);

	auto rect1 = new QGraphicsRectItem(305, 250, 255, 5);
	rect1->setBrush(QColor(230, 155, 60));
	rect1->setPen(brownPen);

	auto rect2 = new QGraphicsRectItem(305, 280, 255, 5);
	rect2->setBrush(QColor(230, 155, 60));
	rect2->setPen(brownPen);

	for (int x = 0; x <= 250; x += 20)
	{
		auto rect3 = new QGraphicsRectItem(310, 240, 5, 50);
		rect3->setBrush(QColor(230, 155, 60));
		rect3->setPen(brownPen);
		rect3->moveBy(x, 0);
		fence->addToGroup(rect3);
	}

	fence->addToGroup(rect1);
	fence->addToGroup(rect2);

	return fence;
}

void MoveItem::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    this->setPos(mapToScene(event->pos() - m_point));
}

void MoveItem::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	m_point = event->pos();
    this->setCursor(QCursor(Qt::ClosedHandCursor));
}

void MoveItem::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
}

QRectF MoveItem::boundingRect() const
{
	return QGraphicsItemGroup::boundingRect();
}

void MoveItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    QGraphicsItemGroup::paint(painter, option, widget);
}
