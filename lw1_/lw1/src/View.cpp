#include "View.h"
#include "Letter.h"
#include <QTimer>
#include <QGraphicsItem>

View::View(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::View)
	, m_scene(new QGraphicsScene(this))
{
	ui->setupUi(this);
	setFixedSize(600, 500);
	m_scene->setItemIndexMethod(QGraphicsScene::NoIndex);
	m_scene->setSceneRect(0, 0, 500, 450);

	ui->graphicsView->resize(600, 500);
	ui->graphicsView->setScene(m_scene);

	auto letter1 = GetLetterC();
	auto letter2 = GetLetterA();
	auto letter3 = GetLetterA();
	letter3->moveBy(80, 0);
	
	m_scene->addItem(letter1);
	m_scene->addItem(letter2);
	m_scene->addItem(letter3);

	//auto timer = new QTimer(this);
	//connect(timer, SIGNAL(timeout()), this, SLOT(Move()));
	//timer->start(1000/60);
}

View::~View()
{

	delete ui;
}

void View::paintEvent(QPaintEvent* event)
{
	//QPainter painter(this);
	//painter.drawEllipse(QRect(20, 20, 100, 100));
}

void View::Move()
{

}

QGraphicsItemGroup* View::GetLetterC()
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

QGraphicsItemGroup* View::GetLetterA()
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