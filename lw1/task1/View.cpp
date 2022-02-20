#include "View.h"
#include "ui_View.h"
#include <QGraphicsView>
#include <QTimer>

View::View(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::View)
    , m_scene(new QGraphicsScene(this))
{
    ui->setupUi(this);
    auto graphicsView = new QGraphicsView(this);
    graphicsView->setAlignment(Qt::AlignCenter);                                    // Делаем привязку содержимого к центру
    graphicsView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    // Растягиваем содержимое по виджету

    graphicsView->setMinimumHeight(400);
    graphicsView->setMinimumWidth(600);

    ui->gridLayout->addWidget(graphicsView);
    graphicsView->setScene(m_scene);

	auto width = graphicsView->width() - 11;
	auto height = graphicsView->height() - 11;
	m_scene->setSceneRect(0, 0, width, height);

	auto letter1 = GetLetterC();
	auto letter2 = GetLetterA();
	auto letter3 = GetLetterA();
	letter3->moveBy(80, 0);

	m_items.push_back({ letter1, 0 });
	m_items.push_back({ letter2, 0 });
	m_items.push_back({ letter3, 0 });

	m_scene->addItem(letter1);
	m_scene->addItem(letter2);
	m_scene->addItem(letter3);

	auto timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(Move()));
	timer->start(10);

}

View::~View()
{
    delete ui;
}

void View::Move()
{
	float speed = 5;
	float acceleration = -10;

	for (size_t i = 0; i < m_items.size(); i++)
	{
		auto& curItem = m_items.at(i);
		curItem.second = curItem.second + 0.01;

		float v = speed + (acceleration * curItem.second / 2);
		float newY = v * curItem.second;

		curItem.first->moveBy(0, -newY);
		if (curItem.first->y() >= 0)
		{
			curItem.second = 0;
		}
	}
}


QGraphicsItem* View::GetLetterC()
{
	auto group = new QGraphicsItemGroup();
	QPen pen;
	pen.setWidth(1);
	pen.setColor(QColor(255, 0, 0));

	QGraphicsRectItem* rect1 = new QGraphicsRectItem(20, 100, 10, 55);
	QGraphicsRectItem* rect2 = new QGraphicsRectItem(20, 100, 30, 10);
	QGraphicsRectItem* rect3 = new QGraphicsRectItem(20, 145, 30, 10);

	rect1->setBrush(QColor(255, 0, 0));
	rect1->setPen(pen);
	rect2->setBrush(QColor(255, 0, 0));
	rect2->setPen(pen);
	rect3->setBrush(QColor(255, 0, 0));
	rect3->setPen(pen);

	group->addToGroup(rect1);
	group->addToGroup(rect2);
	group->addToGroup(rect3);

	return group;
}

QGraphicsItem* View::GetLetterA()
{
	auto group = new QGraphicsItemGroup();
	QPen pen;
	pen.setWidth(1);
	pen.setColor(QColor(0, 0, 0));

	QGraphicsPolygonItem* rect1 = new QGraphicsPolygonItem();
	QPolygon p1;
	p1 << QPoint(110, 100) << QPoint(90, 155) << QPoint(100, 155) << QPoint(120, 100);
	rect1->setPolygon(p1);

	QGraphicsPolygonItem* rect2 = new QGraphicsPolygonItem();
	QPolygon p2;
	p2 << QPoint(110, 100) << QPoint(120, 100) << QPoint(140, 155) << QPoint(130, 155);
	rect2->setPolygon(p2);

	QGraphicsRectItem* rect3 = new QGraphicsRectItem(100, 130, 30, 10);

	rect1->setBrush(QColor(0, 0, 0));
	rect1->setPen(pen);
	rect2->setBrush(QColor(0, 0, 0));
	rect2->setPen(pen);
	rect3->setBrush(QColor(0, 0, 0));
	rect3->setPen(pen);

	group->addToGroup(rect1);
	group->addToGroup(rect2);
	group->addToGroup(rect3);

	return group;
}