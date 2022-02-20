#pragma once
#include <QObject>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>

class MoveItem : public QGraphicsItemGroup
{
public:
	MoveItem();
protected:
	QRectF boundingRect() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

	void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
	void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
private:
	QGraphicsItem* GetHouse() const;
	QGraphicsItem* GetFence() const;
	QPointF m_point;
};

